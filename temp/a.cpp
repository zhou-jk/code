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

// Timer helper class
class Timer {
public:
    Timer() : mStart(std::chrono::high_resolution_clock::now()) {}
    
    void reset() {
        mStart = std::chrono::high_resolution_clock::now();
    }
    
    // Returns elapsed milliseconds
    double elapsedMs() const {
        auto now = std::chrono::high_resolution_clock::now();
        return std::chrono::duration<double, std::milli>(now - mStart).count();
    }
    
private:
    std::chrono::time_point<std::chrono::high_resolution_clock> mStart;
};

// Custom memory allocator for triangulation tests
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

// Test class - performs multiple triangulations on a specific path and measures performance
class TriangulatorTest {
public:
    explicit TriangulatorTest(const char* testName) : fTestName(testName) {}
    
    // Run the test
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
        
        // Calculate statistics
        double total = 0.0;
        double min = timings[0];
        double max = timings[0];
        
        for (double time : timings) {
            total += time;
            min = std::min(min, time);
            max = std::max(max, time);
        }
        
        double avg = total / iterations;
        
        // Calculate standard deviation
        double variance = 0.0;
        for (double time : timings) {
            double diff = time - avg;
            variance += diff * diff;
        }
        double stdDev = std::sqrt(variance / iterations);
        
        // Output results
        std::cout << "Test: " << fTestName << std::endl;
        std::cout << "  Iterations: " << iterations << std::endl;
        std::cout << "  Average time: " << std::fixed << std::setprecision(3) << avg << " ms" << std::endl;
        std::cout << "  Minimum time: " << min << " ms" << std::endl;
        std::cout << "  Maximum time: " << max << " ms" << std::endl;
        std::cout << "  Standard deviation: " << stdDev << " ms" << std::endl;
        std::cout << "-----------------------------------" << std::endl;
    }
    
private:
    const char* fTestName;
};

int main(int argc, char* argv[]) {
    // Set test parameters
    int iterations = 100; // Default iteration count
    
    // Parse command line arguments
    for (int i = 1; i < argc; ++i) {
        if (std::string(argv[i]) == "--iterations" && i + 1 < argc) {
            iterations = std::stoi(argv[i + 1]);
            i++;
        }
    }
    
    std::cout << "Starting triangulation performance tests..." << std::endl;
    std::cout << "Iterations: " << iterations << std::endl;
    std::cout << "====================================" << std::endl;
    
    // Test simple shapes
    std::vector<const char*> simpleShapes = {"rect", "roundrect", "circle", "star", "complex"};
    
    for (const char* shapeName : simpleShapes) {
        SimpleTestPath testPath = CreateSimplePath(shapeName);
        TriangulatorTest test(shapeName);
        test.runTest(testPath.fPath, 0.25f, iterations);
    }
    
    // Test different tolerances
    std::vector<float> tolerances = {0.1f, 0.25f, 0.5f, 1.0f};
    SimpleTestPath complexPath = CreateSimplePath("complex");
    
    for (float tolerance : tolerances) {
        std::string testName = "complex_tolerance_" + std::to_string(tolerance);
        TriangulatorTest test(testName.c_str());
        test.runTest(complexPath.fPath, tolerance, iterations);
    }
    
    // Test star shape
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
    
    // Test SVGs (if resources are available)
    std::vector<const char*> svgTests = {"scan", "dynamic_island", "star_of_david"};
    
    for (const char* svgName : svgTests) {
        SkString fileName = SVGNameToFileName(svgName);
        SkPath svgPath = GetPathFromSVG(fileName.c_str());
        
        if (!svgPath.isEmpty()) {
            std::string testName = std::string("svg_") + svgName;
            TriangulatorTest test(testName.c_str());
            test.runTest(svgPath, 0.25f, iterations);
        } else {
            std::cout << "Skipping SVG test '" << svgName << "': Resource unavailable or path is empty" << std::endl;
        }
    }
    
    std::cout << "All tests completed!" << std::endl;
    return 0;
} 