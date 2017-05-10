#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <stdlib.h>
#include "count.h"

/* Measure RAM Access Time BEGIN */

void expRAMAccessTime(int increment, int arraySize) {
  int i;
  int j;
  int *ptr = malloc(sizeof(int) * arraySize);

  for (i = 0; i < arraySize; i += increment) {
    double start, end;
    unsigned lo, hi, lo1, hi1;
    COUNT1(hi, lo)
    j = *ptr;
    COUNT2(hi1, lo1)
    GETNUM(hi, lo, start)
    GETNUM(hi1, lo1, end)
    ptr += increment;
    printf("%f\n", end - start);
  }
}

void measureRAMAccessTime() {
  int increment = 1;
  int arraySize = 2;
  for (; increment < )
}

/* Measure RAM Access Time END */

int main()
{
  expRAMAccessTime(2, 10);
  return 0;
}
