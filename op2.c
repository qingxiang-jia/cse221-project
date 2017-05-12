#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include "count.h"
#include "unrolled_mem_read.h"

/* Measure RAM Access Time BEGIN */

#define SZ_INT 4
#define RAM_ACCESS_TIME_LOOP 100000
void expRAMAccessTime(int arraySize)
{
  int i;
  int j;
  int *chunkPtr = malloc(arraySize);
  int *ptr = chunkPtr;

  if (chunkPtr == NULL)
  {
    printf("malloc failed");
    exit(1);
  }
  double total = 0;
  double count = 0;

  printf("arraySize: %d \n", arraySize);
  for (i = 0; i < RAM_ACCESS_TIME_LOOP; i++)
  {
    double start, end;
    unsigned lo, hi, lo1, hi1;
    COUNT1(hi, lo)
    j = *ptr;
    COUNT2(hi1, lo1)
    GETNUM(hi, lo, start)
    GETNUM(hi1, lo1, end)
    ptr = chunkPtr + (rand() % (arraySize / 4));
    total += (end - start);
    printf("%f\n", end - start);
    count++;
  }
  // printf("avg: %f\n", total / count);
  free(chunkPtr);
}

void measureRAMAccessTime()
{
  int maxIncrement = 10;
  int arraySize;
  // int maxArraySize = 16777216; // 2^24
  int maxArraySize = 536870912; // 2^29
  for (arraySize = 4; arraySize <= maxArraySize; arraySize *= 2)
  {
    expRAMAccessTime(arraySize);
  }
}

/* Measure RAM Access Time END */

/* Measure RAM Bandwidth BEGIN */

double MBCycleToMBPerSecond(double MB, double cycles) {
  return (MB / (cycles)) * 2.4 * 1000000000;
}

void expBandwidth()
{
  long double *chunkPtr = malloc(8388608); // 8MB, 16B per long double
  if (chunkPtr == NULL)
  {
    printf("malloc failed");
    exit(1);
  }
  long double *ptr = chunkPtr;
  long double sum = 0;
  
  unsigned lo, hi, lo1, hi1;
  double start, end;
  COUNT1(hi, lo)
  UNROLLED_MEM_READ_LINE524288
  // so many that I have to use macro recursively
  COUNT2(hi1, lo1)
  GETNUM(hi, lo, start)
  GETNUM(hi1, lo1, end)
  printf("8MB data takes %f cycles, which is %f MB/s @ 2.4GHz\n", end - start, MBCycleToMBPerSecond(8.0, end - start));

  free(chunkPtr);
}

void measureRAMBandwidth()
{
  expBandwidth();
}

/* Measure RAM Bandwidth END */

int main()
{
  srand(time(NULL));
  // measureRAMAccessTime();
  measureRAMBandwidth();
  return 0;
}
