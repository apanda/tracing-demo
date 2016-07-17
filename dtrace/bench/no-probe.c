#include <stdio.h>
#include <stdint.h>

static inline uint64_t rdtsc() {
    uint32_t hi, lo;
    asm volatile("rdtsc": "=a" (lo), "=d" (hi));
    return (((uint64_t)hi) << 32) | ((uint64_t)lo);
}

static inline void nop() {
    asm volatile("nop");
}

int main(int argc, char* argv[]) {
    const uint64_t iters = 3600000;
    uint64_t iter = 0;
    uint64_t end = 0; 
    uint64_t begin = rdtsc();
    while(iter < iters) {
        nop();
        iter++;
    }
    end = rdtsc();
    printf("%llu %llu\n", iters, end - begin);
}
