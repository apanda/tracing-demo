#include <stdio.h>
#include <stdint.h>

#define TRACEPOINT_CREATE_PROBES
#define TRACEPOINT_DEFINE
#include "lttng-tp.h"

static inline uint64_t rdtsc() {
    uint32_t hi, lo;
    asm volatile("rdtsc": "=a" (lo), "=d" (hi));
    return (((uint64_t)hi) << 32) | ((uint64_t)lo);
}

static inline void nop() {
    asm volatile("nop");
}

int main(int argc, char* argv[]) {
    const uint64_t iters = 360000000;
    uint64_t iter = 0;
    uint64_t end = 0; 
    uint64_t begin = rdtsc();
    while(iter < iters) {
        tracepoint(benchmark, probe); 
        nop();
        iter++;
    }
    end = rdtsc();
    printf("%lu %lu\n", iters, end - begin);
}
