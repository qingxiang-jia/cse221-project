#ifndef COUNT_H_
#define COUNT_H_

// #include <stdint.h>
#include <mach/mach_time.h>
#define COUNT1(hi, lo)                                         \
  {                                                            \
    asm volatile(                                              \
        "CPUID\n\t"                                            \
        "RDTSC\n\t"                                            \
        "mov %%edx, %0\n\t"                                    \
        "mov %%eax, %1\n\t"                                    \
        : "=r"(hi), "=r"(lo)::"%rax", "%rbx", "%rcx", "%rdx"); \
  }

#define COUNT2(hi, lo)                                         \
  {                                                            \
    asm volatile(                                              \
        "RDTSCP\n\t"                                           \
        "mov %%edx, %0\n\t"                                    \
        "mov %%eax, %1\n\t"                                    \
        "CPUID\n\t"                                            \
        : "=r"(hi), "=r"(lo)::"%rax", "%rbx", "%rcx", "%rdx"); \
  }

#define GETTIME(hi, lo)                                        \
  {                                                            \
    asm volatile(                                              \
        "CPUID\n\t"                                            \
        "RDTSC\n\t"                                            \
        "mov %%edx, %0\n\t"                                    \
        "mov %%eax, %1\n\t"                                    \
        : "=r"(hi), "=r"(lo)::"%rax", "%rbx", "%rcx", "%rdx"); \
  }

#define GETNUM(hi, lo, num)                  \
  {                                          \
    num = (double)((uint64_t)hi << 32 | lo); \
  }

static mach_timebase_info_data_t timebaseInfo;
static void __attribute__((constructor)) getTimebase()
{
  mach_timebase_info(&timebaseInfo);
}

uint64_t getNano()
{
  uint64_t time = mach_absolute_time();
  time = time * timebaseInfo.numer;
  time = time / timebaseInfo.denom;
  return time;
}

#endif
