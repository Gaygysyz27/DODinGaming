#include "PerformanceMetrics.h"

PerformanceMetrics::PerformanceMetrics() 
    : fps(0), updateTime(0), renderTime(0), 
      collisionTime(0), memoryUsed(0), collisionCount(0) {}

size_t PerformanceMetrics::GetMemoryUsage() {
#ifdef _WIN32
    PROCESS_MEMORY_COUNTERS_EX pmc;
    if (GetProcessMemoryInfo(GetCurrentProcess(), 
        (PROCESS_MEMORY_COUNTERS*)&pmc, sizeof(pmc))) {
        return pmc.WorkingSetSize / (1024 * 1024);
    }
#endif
    return 0;
}