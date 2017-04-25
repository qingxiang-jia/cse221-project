#include <stdio.h>
#include <unistd.h>
#include "count.h"

#define READ_TIME_ROUNDS 10000

void measureReadTimeOverhead() {
  uint64_t avgOverhead, i;
  for (i = 0; i < READ_TIME_ROUNDS; i++) {
    uint64_t start, end;
    unsigned lo, hi, lo1, hi1;
    COUNT1(hi, lo)
    COUNT2(hi1, lo1)
    GETNUM(hi, lo, start)
    GETNUM(hi1, lo1, end)
    avgOverhead += (end - start);
  }
  avgOverhead /= READ_TIME_ROUNDS;
  printf("Average overhead for reading time is: %llu\n", avgOverhead);
}

int main()
{
  measureReadTimeOverhead();
  return 0;
}
