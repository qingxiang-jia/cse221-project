#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include "count.h"

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
