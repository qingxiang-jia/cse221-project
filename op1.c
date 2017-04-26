#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include "count.h"

#define READ_TIME_ROUNDS 10000
#define LOOP_ROUNDS 10000
#define READ_TIME_OVERHEAD 32

void measureReadTimeOverhead()
{
  uint64_t avgOverhead, i;
  for (i = 0; i < READ_TIME_ROUNDS; i++)
  {
    uint64_t start, end, j;
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

void measureLoopOverhead()
{
  uint64_t i, avgOverhead;
  for (i = 0; i < LOOP_ROUNDS; i++)
  {
    uint64_t start, end, j;
    unsigned lo, hi, lo1, hi1;
    COUNT1(hi, lo)
    for (j = 0; j < 100; j++)
    {
    }
    COUNT2(hi1, lo1)
    GETNUM(hi, lo, start)
    GETNUM(hi1, lo1, end)
    avgOverhead += (end - start);
  }
  avgOverhead -= READ_TIME_OVERHEAD;
  avgOverhead /= (LOOP_ROUNDS * 100);
  printf("Average overhead for loop is: %llu\n", avgOverhead);
}

int main()
{
  measureReadTimeOverhead();
  measureLoopOverhead();
  return 0;
}
