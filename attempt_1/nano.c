#include <stdint.h>

#if defined(__APPLE__)

#include <mach/mach_time.h>

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

#else
static uint64_t ticks = 0;

static inline uint64_t rdtsc()
{
  uint32_t hiReg, loReg;
  asm volatile("rdtscp\n"
               "movl %%edx, %0\n"
               "movl %%eax, %1\n"
               "cpuid"
               : "=r"(hiReg), "=r"(loReg)
               :
               : "%rax", "%rbx", "%rcx", "%rdx");
  return (((uint64_t)hiReg) << 32) | (uint64_t)loReg;
}

static __attribute__((constructor)) ticksPerMicroSec()
{
  uint64_t start = rdtsc();
  usleep(1); //1 microsecond
  ticks = rdtsc() - start;
}

uint64_t getNano()
{
  printf("ubuntu\n");
  return (double)rdtsc() / (double)ticks * 1000;
}

#endif