#include <stdio.h>
#include <unistd.h>

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
  num = ((uint64_t)hi << 32 | lo);\
}

// int main()
// {
//   uint64_t start, end;
//   unsigned cycles_high, cycles_low, cycles_high1, cycles_low1;
//   asm volatile (
//     "CPUID\n\t"
//     "RDTSC\n\t"
//     "mov %%edx, %0\n\t"
//     "mov %%eax, %1\n\t": "=r" (cycles_high), "=r" (cycles_low)::"%rax", "%rbx", "%rcx", "%rdx"
//   );
//   // sleep(1);
//   asm volatile (
//     "RDTSCP\n\t"
//     "mov %%edx, %0\n\t"
//     "mov %%eax, %1\n\t"
//     "CPUID\n\t": "=r" (cycles_high1), "=r" (cycles_low1)::"%rax", "%rbx", "%rcx", "%rdx"
//   );
//   start = ((uint64_t)cycles_high << 32 | cycles_low);
//   end = ((uint64_t)cycles_high1 << 32 | cycles_low1);
//   printf("%llu\n", end - start);

//   return 0;
// }

int main()
{
  uint64_t start, end;
  unsigned cycles_high, cycles_low, cycles_high1, cycles_low1;
  COUNT1(cycles_high, cycles_low)
  sleep(1);
  COUNT2(cycles_high1, cycles_low1)
  GETNUM(cycles_high, cycles_low, start)
  GETNUM(cycles_high1, cycles_low1, end)
  printf("%llu\n", end - start);

  return 0;
}

