#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include "count.h"

/* Measure RAM Access Time BEGIN */

#define SZ_INT 4

void expRAMAccessTime(int increment, int arraySize) {
  int i;
  int j;
  int *chunkPtr = malloc(SZ_INT * arraySize);
  int *ptr = chunkPtr;
  
  if (chunkPtr == NULL) {
    printf("malloc failed");
    exit(1);
  }
  double avg = 0;
  double count = 0;

  for (i = 0; i < arraySize; i += increment) {
    double start, end;
    unsigned lo, hi, lo1, hi1;
    COUNT1(hi, lo)
    j = *ptr;
    COUNT2(hi1, lo1)
    GETNUM(hi, lo, start)
    GETNUM(hi1, lo1, end)
    // ptr += increment;
    ptr = chunkPtr + (rand() % arraySize);
    avg += (end - start);
    count++;
  }
  printf("avg: %f\n", avg / count);
  free(chunkPtr);
}

void measureRAMAccessTime() {
  int increment;
  int maxIncrement = 10;
  int arraySize;
  int maxArraySize = 16777216; // 2^24
  // for (increment = 1; increment <= maxIncrement; increment++) {
    for (arraySize = 2; arraySize <= maxArraySize; arraySize *= 2) {
      printf("increment: %d  arraySize: %d\n", increment, arraySize);
      expRAMAccessTime(increment, arraySize);
    }
  // }
}

/* Measure RAM Access Time END */

int main()
{
  srand(time(NULL));
  measureRAMAccessTime();
  return 0;
}
