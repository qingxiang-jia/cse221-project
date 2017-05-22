#ifndef COUNT_H_
#define COUNT_H_

// #include <stdint.h>
#define COUNT1(hi, lo) {\
  asm volatile (\
    "CPUID\n\t"\
    "RDTSC\n\t"\
    "mov %%edx, %0\n\t"\
    "mov %%eax, %1\n\t": "=r" (hi), "=r" (lo)::"%rax", "%rbx", "%rcx", "%rdx"\
  );\
}

#define COUNT2(hi, lo) {\
  asm volatile (\
    "RDTSCP\n\t"\
    "mov %%edx, %0\n\t"\
    "mov %%eax, %1\n\t"\
    "CPUID\n\t": "=r" (hi), "=r" (lo)::"%rax", "%rbx", "%rcx", "%rdx"\
  );\
}

#define GETNUM(hi, lo, num) {\
  num = (double) ((uint64_t)hi << 32 | lo);\
}

#endif
