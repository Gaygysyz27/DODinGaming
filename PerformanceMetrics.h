#pragma once
#include <cstddef>

#ifdef _WIN32
#include <windows.h>
#include <psapi.h>
#endif

class PerformanceMetrics {
public:
    float fps;
    float updateTime;
    float renderTime;
    float collisionTime;
    size_t memoryUsed;
    int collisionCount;
    
    PerformanceMetrics();
    static size_t GetMemoryUsage();
};