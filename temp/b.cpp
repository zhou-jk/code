// 优化后的pathToContours实现，移除BitCast依赖
void OptimizedPathToContours(const SkPath& path,
                            float tolerance,
                            const SkRect& clipBounds,
                            std::vector<SkPoint>& contourPoints,
                            std::vector<int>& contourSizes,
                            bool* isLinear) {
    // 使用Skia的标准类型和函数
    const float toleranceSqd = tolerance * tolerance;
    *isLinear = true;
    
    // 预估容量以减少重新分配
    int estimatedPoints = 4 * path.countPoints();
    contourPoints.clear();
    contourPoints.reserve(estimatedPoints);
    contourSizes.clear();
    
    int currentContourSize = 0;
    SkPoint contourStart = {0, 0};
    
    // 处理反向填充
    if (path.isInverseFillType()) {
        SkPoint quad[4];
        clipBounds.toQuad(quad);
        
        // 逆时针添加边界
        for (int i = 3; i >= 0; i--) {
            contourPoints.push_back(quad[i]);
            currentContourSize++;
        }
        contourSizes.push_back(currentContourSize);
        currentContourSize = 0;
    }
    
    // 点之间的中点计算 - 替代mix函数
    auto midPoint = [](const SkPoint& a, const SkPoint& b, float t) -> SkPoint {
        return SkPoint {
            a.fX + (b.fX - a.fX) * t,
            a.fY + (b.fY - a.fY) * t
        };
    };
    
    // 计算点距离平方 - 类似于skvx中的lengthSquared
    auto distanceSquared = [](const SkPoint& a, const SkPoint& b) -> float {
        float dx = b.fX - a.fX;
        float dy = b.fY - a.fY;
        return dx * dx + dy * dy;
    };
    
    // 计算一个点到直线段的距离平方
    auto distToLineSegSqd = [](const SkPoint& pt, const SkPoint& a, const SkPoint& b) -> float {
        float vx = b.fX - a.fX;
        float vy = b.fY - a.fY;
        float wx = pt.fX - a.fX;
        float wy = pt.fY - a.fY;
        
        
        // 计算投影
        float c1 = vx * wx + vy * wy;
        if (c1 <= 0) return wx * wx + wy * wy;
        
        // 线段长度平方
        float c2 = vx * vx + vy * vy;
        if (c2 <= c1) {
            float dx = pt.fX - b.fX;
            float dy = pt.fY - b.fY;
            return dx * dx + dy * dy;
        }
        
        // 点到线的距离
        float b1 = c1 / c2;
        float px = a.fX + b1 * vx;
        float py = a.fY + b1 * vy;
        float dx = pt.fX - px;
        float dy = pt.fY - py;
        return dx * dx + dy * dy;
    };
    
    // 类似于wang公式的曲线细分计算
    auto calculateCubicSegments = [](const SkPoint pts[4], float tolerance) -> int {
        // 计算曲线控制点之间的距离
        float d1 = distToLineSegSqd(pts[1], pts[0], pts[3]);
        float d2 = distToLineSegSqd(pts[2], pts[0], pts[3]);
        
        float maxDist = std::max(d1, d2);
        
        // 根据控制点偏离程度估算细分
        if (maxDist <= tolerance * tolerance) {
            return 1;
        } else {
            // 使用类似于PatchWriter的公式估算分段数
            return std::min(64, static_cast<int>(sqrtf(maxDist / (tolerance * tolerance)) + 1));
        }
    };
    
    // 立方曲线评估函数
    auto evaluateCubic = [](const SkPoint pts[4], float t) -> SkPoint {
        float oneMinusT = 1.0f - t;
        float oneMinusT2 = oneMinusT * oneMinusT;
        float oneMinusT3 = oneMinusT2 * oneMinusT;
        float t2 = t * t;
        float t3 = t2 * t;
        
        return SkPoint {
            oneMinusT3 * pts[0].fX + 
            3.0f * t * oneMinusT2 * pts[1].fX + 
            3.0f * t2 * oneMinusT * pts[2].fX + 
            t3 * pts[3].fX,
            
            oneMinusT3 * pts[0].fY + 
            3.0f * t * oneMinusT2 * pts[1].fY + 
            3.0f * t2 * oneMinusT * pts[2].fY + 
            t3 * pts[3].fY
        };
    };
    
    // 处理三次曲线的非递归函数
    auto processCubic = [&](const SkPoint pts[4]) {
        // 快速检查是否接近直线
        SkPoint thirdPoint = midPoint(pts[0], pts[3], 1.0f/3.0f);
        SkPoint twoThirdPoint = midPoint(pts[0], pts[3], 2.0f/3.0f);
        
        if (distanceSquared(pts[1], thirdPoint) < toleranceSqd &&
            distanceSquared(pts[2], twoThirdPoint) < toleranceSqd) {
            contourPoints.push_back(pts[3]);
            currentContourSize++;
            return;
        }
        
        // 使用类wang公式估算所需细分段数
        int segments = calculateCubicSegments(pts, tolerance);
        
        if (segments <= 1) {
            // 只需要一个段
            contourPoints.push_back(pts[3]);
            currentContourSize++;
        } else {
            // 直接采样法，借鉴PatchWriter的非递归方式
            float step = 1.0f / segments;
            for (int i = 1; i <= segments; i++) {
                float t = i * step;
                contourPoints.push_back(evaluateCubic(pts, t));
                currentContourSize++;
            }
        }
    };
    
    // 处理二次曲线的函数
    auto processQuadratic = [&](const SkPoint pts[3]) {
        // 转换为立方曲线表示进行统一处理
        SkPoint cubicPts[4];
        cubicPts[0] = pts[0];
        cubicPts[1] = midPoint(pts[0], pts[1], 2.0f/3.0f);
        cubicPts[2] = midPoint(pts[2], pts[1], 2.0f/3.0f);
        cubicPts[3] = pts[2];
        
        processCubic(cubicPts);
    };
    
    // 迭代处理路径
    SkPath::Iter iter(path, false);
    SkPoint pts[4];
    SkPath::Verb verb;
    SkAutoConicToQuads conicConverter;
    
    while ((verb = iter.next(pts)) != SkPath::kDone_Verb) {
        switch (verb) {
            case SkPath::kMove_Verb:
                if (currentContourSize > 0) {
                    contourSizes.push_back(currentContourSize);
                    currentContourSize = 0;
                }
                contourStart = pts[0];
                contourPoints.push_back(pts[0]);
                currentContourSize++;
                break;
                
            case SkPath::kLine_Verb:
                contourPoints.push_back(pts[1]);
                currentContourSize++;
                break;
                
            case SkPath::kQuad_Verb:
                *isLinear = false;
                
                if (toleranceSqd == 0) {
                    contourPoints.push_back(pts[2]);
                    currentContourSize++;
                } else {
                    processQuadratic(pts);
                }
                break;
                
            case SkPath::kConic_Verb: {
                *isLinear = false;
                
                if (toleranceSqd == 0) {
                    contourPoints.push_back(pts[2]);
                    currentContourSize++;
                } else {
                    float weight = iter.conicWeight();
                    
                    // 参考PatchWriter的处理方式
                    if (weight > 0.99f) {
                        // 接近二次曲线
                        processQuadratic(pts);
                    } else {
                        // 转换为多个二次曲线
                        const SkPoint* quadPts = conicConverter.computeQuads(pts, weight, toleranceSqd);
                        int quadCount = conicConverter.countQuads();
                        
                        for (int i = 0; i < quadCount; ++i) {
                            SkPoint quadSegment[3] = {
                                quadPts[i*2], quadPts[i*2+1], quadPts[i*2+2]
                            };
                            processQuadratic(quadSegment);
                        }
                    }
                }
                break;
            }
                
            case SkPath::kCubic_Verb:
                *isLinear = false;
                
                if (toleranceSqd == 0) {
                    contourPoints.push_back(pts[3]);
                    currentContourSize++;
                } else {
                    processCubic(pts);
                }
                break;
                
            case SkPath::kClose_Verb:
                // 确保轮廓闭合
                if (currentContourSize > 1) {
                    SkPoint& lastPt = contourPoints[contourPoints.size() - 1];
                    if ((lastPt.fX != contourStart.fX) || (lastPt.fY != contourStart.fY)) {
                        contourPoints.push_back(contourStart);
                        currentContourSize++;
                    }
                }
                
                if (currentContourSize > 0) {
                    contourSizes.push_back(currentContourSize);
                    currentContourSize = 0;
                }
                break;
                
            default:
                break;
        }
    }
    
    // 保存最后一个轮廓
    if (currentContourSize > 0) {
        contourSizes.push_back(currentContourSize);
    }
    
    // 优化：去除冗余点
    if (!contourPoints.empty()) {
        const float minDistSqd = 0.01f;
        std::vector<SkPoint> optimized;
        std::vector<int> optimizedSizes;
        optimized.reserve(contourPoints.size());
        optimizedSizes.reserve(contourSizes.size());
        
        size_t index = 0;
        for (int size : contourSizes) {
            int newSize = 0;
            if (size > 0) {
                optimized.push_back(contourPoints[index]);
                newSize++;
                
                for (int i = 1; i < size; i++) {
                    const SkPoint& curr = contourPoints[index + i];
                    const SkPoint& prev = optimized.back();
                    
                    if (distanceSquared(curr, prev) > minDistSqd) {
                        optimized.push_back(curr);
                        newSize++;
                    }
                }
                
                if (newSize > 0) {
                    optimizedSizes.push_back(newSize);
                }
            }
            index += size;
        }
        
        // 只有当优化后点数显著减少时才替换
        if (optimized.size() < contourPoints.size() * 0.9f) {
            contourPoints = std::move(optimized);
            contourSizes = std::move(optimizedSizes);
        }
    }
}