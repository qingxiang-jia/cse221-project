#include <stdio.h>
#include <unistd.h>

int main()
{
  uint64_t start, end;
  unsigned cycles_high, cycles_low, cycles_high1, cycles_low1;
  asm volatile (
    "CPUID\n\t"
    "RDTSC\n\t"
    "mov %%edx, %0\n\t"
    "mov %%eax, %1\n\t": "=r" (cycles_high), "=r" (cycles_low)::"%rax", "%rbx", "%rcx", "%rdx"
  );
  // sleep(1);
  asm volatile (
    "RDTSCP\n\t"
    "mov %%edx, %0\n\t"
    "mov %%eax, %1\n\t"
    "CPUID\n\t": "=r" (cycles_high1), "=r" (cycles_low1)::"%rax", "%rbx", "%rcx", "%rdx"
  );
  start = ((uint64_t)cycles_high << 32 | cycles_low);
  end = ((uint64_t)cycles_high1 << 32 | cycles_low1);
  printf("%llu\n", end - start);
  return 0;
}
