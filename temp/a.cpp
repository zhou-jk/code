/*
 * Copyright 2023 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "bench/TriangulatorBenchHuawei_new.h"
#include <chrono>
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

// 计时助手类
class Timer {
public:
    Timer() : mStart(std::chrono::high_resolution_clock::now()) {}
    
    void reset() {
        mStart = std::chrono::high_resolution_clock::now();
    }
    
    // 返回经过的毫秒数
    double elapsedMs() const {
        auto now = std::chrono::high_resolution_clock::now();
        return std::chrono::duration<double, std::milli>(now - mStart).count();
    }
    
private:
    std::chrono::time_point<std::chrono::high_resolution_clock> mStart;
};

// 自定义内存分配器，用于三角化测试
class TestAllocator : public GrEagerVertexAllocator {
public:
    TestAllocator() : fVertexAllocSize(0) {}
    
    void* lock(size_t stride, int eagerCount) override {
        size_t allocSize = eagerCount * stride;
        if (allocSize > fVertexAllocSize) {
            fVertexData.reset(allocSize);
            fVertexAllocSize = allocSize;
        }
        return fVertexData;
    }
    
    void unlock(int) override {}
    
private:
    SkAutoTMalloc<char> fVertexData;
    size_t fVertexAllocSize;
};

// 测试类 - 对特定路径进行多次三角化并测量性能
class TriangulatorTest {
public:
    explicit TriangulatorTest(const char* testName) : fTestName(testName) {}
    
    // 运行测试
    void runTest(const SkPath& path, float tolerance, int iterations) {
        TestAllocator allocator;
        std::vector<double> timings;
        timings.reserve(iterations);
        
        for (int i = 0; i < iterations; ++i) {
            Timer timer;
            bool isLinear;
            GrTriangulator_new::PathToTriangles(path, tolerance, SkRect::MakeWH(500, 500), &allocator, &isLinear);
            timings.push_back(timer.elapsedMs());
        }
        
        // 计算统计数据
        double total = 0.0;
        double min = timings[0];
        double max = timings[0];
        
        for (double time : timings) {
            total += time;
            min = std::min(min, time);
            max = std::max(max, time);
        }
        
        double avg = total / iterations;
        
        // 计算标准差
        double variance = 0.0;
        for (double time : timings) {
            double diff = time - avg;
            variance += diff * diff;
        }
        double stdDev = std::sqrt(variance / iterations);
        
        // 输出结果
        std::cout << "测试: " << fTestName << std::endl;
        std::cout << "  迭代次数: " << iterations << std::endl;
        std::cout << "  平均时间: " << std::fixed << std::setprecision(3) << avg << " ms" << std::endl;
        std::cout << "  最小时间: " << min << " ms" << std::endl;
        std::cout << "  最大时间: " << max << " ms" << std::endl;
        std::cout << "  标准差: " << stdDev << " ms" << std::endl;
        std::cout << "-----------------------------------" << std::endl;
    }
    
private:
    const char* fTestName;
};

int main(int argc, char* argv[]) {
    // 设置测试参数
    int iterations = 100; // 默认迭代次数
    
    // 解析命令行参数
    for (int i = 1; i < argc; ++i) {
        if (std::string(argv[i]) == "--iterations" && i + 1 < argc) {
            iterations = std::stoi(argv[i + 1]);
            i++;
        }
    }
    
    std::cout << "开始三角化性能测试..." << std::endl;
    std::cout << "迭代次数: " << iterations << std::endl;
    std::cout << "====================================" << std::endl;
    
    // 测试简单形状
    std::vector<const char*> simpleShapes = {"rect", "roundrect", "circle", "star", "complex"};
    
    for (const char* shapeName : simpleShapes) {
        SimpleTestPath testPath = CreateSimplePath(shapeName);
        TriangulatorTest test(shapeName);
        test.runTest(testPath.fPath, 0.25f, iterations);
    }
    
    // 测试不同精度
    std::vector<float> tolerances = {0.1f, 0.25f, 0.5f, 1.0f};
    SimpleTestPath complexPath = CreateSimplePath("complex");
    
    for (float tolerance : tolerances) {
        std::string testName = "complex_tolerance_" + std::to_string(tolerance);
        TriangulatorTest test(testName.c_str());
        test.runTest(complexPath.fPath, tolerance, iterations);
    }
    
    // 测试星形
    TriangulatorTest starTest("star_150_50");
    SkPath starPath;
    const float cx = 250;
    const float cy = 250;
    const float outerRadius = 150;
    const float innerRadius = 50;
    const int numPoints = 5;
    
    for (int i = 0; i < numPoints * 2; i++) {
        float radius = (i & 1) ? innerRadius : outerRadius;
        float angle = static_cast<float>(SK_ScalarPI * (i * 2 + 3) / numPoints / 2);
        float x = cx + radius * cos(angle);
        float y = cy + radius * sin(angle);
        
        if (i == 0) {
            starPath.moveTo(x, y);
        } else {
            starPath.lineTo(x, y);
        }
    }
    starPath.close();
    
    starTest.runTest(starPath, 0.25f, iterations);
    
    // 测试SVG (如果资源可用)
    std::vector<const char*> svgTests = {"scan", "dynamic_island", "star_of_david"};
    
    for (const char* svgName : svgTests) {
        SkString fileName = SVGNameToFileName(svgName);
        SkPath svgPath = GetPathFromSVG(fileName.c_str());
        
        if (!svgPath.isEmpty()) {
            std::string testName = std::string("svg_") + svgName;
            TriangulatorTest test(testName.c_str());
            test.runTest(svgPath, 0.25f, iterations);
        } else {
            std::cout << "跳过SVG测试 '" << svgName << "': 资源不可用或路径为空" << std::endl;
        }
    }
    
    std::cout << "所有测试完成！" << std::endl;
    return 0;
} 