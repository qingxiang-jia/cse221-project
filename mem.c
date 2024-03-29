#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <fcntl.h>
#include "headers/count.h"
#include "headers/unrolled_mem_read.h"
#include "headers/unrolled_mem_write.h"
#include "headers/unrolled_long_double_ptr_inc.h"

/* Measure RAM Access Time Old BEGIN */

#define SZ_INT 4
#define RAM_ACCESS_TIME_LOOP 1000000
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

/* Measure RAM Access Time Old END */

/* Measure RAM Bandwidth BEGIN */

#define LONG_DOUBLE_PTR_INCREMENT_COST 896000

void ptrIncrementCost()
{
  int i;
  double total = 0;
  long double *ptr = 0;
  for (i = 0; i < 1000; i++)
  {
    unsigned lo, hi, lo1, hi1;
    double start, end;
    COUNT1(hi, lo)
    // UNROLLED_LONG_DOUBLE_PTR_INC_LINE2048 // <- comment if you are not using it to speed up compilation
    COUNT2(hi1, lo1)
    GETNUM(hi, lo, start)
    GETNUM(hi1, lo1, end)
    total += end - start;
  }
  printf("Avg cost for 8M/256 long double is %f cycles.\n", total / 1000);
}

double MBCycleToMBPerSecond(double MB, double cycles)
{
  return (MB / (cycles)) * 2.4 * 1000000000;
}

void expBandwidthRead()
{
  uint64_t *chunkPtr = malloc(8388608); // 8MB, 16B per long double
  if (chunkPtr == NULL)
  {
    printf("malloc failed");
    exit(1);
  }
  int i;
  uint64_t *ptr = chunkPtr;
  uint64_t d = 0;
  double totalCycles = 0;
  double totalBytes = 0;

  double measurement[100000]; // for sd calculation

  for (i = 0; i < 100000; i++)
  {
    double start, end;
    unsigned lo, hi, lo1, hi1;
    COUNT1(hi, lo)
    UNROLLED_MEM_READ_HEAD_TAIL
    COUNT2(hi1, lo1)
    GETNUM(hi, lo, start)
    GETNUM(hi1, lo1, end)
    totalCycles += end - start;   // cycles
    measurement[i] = end - start; // for sd calculation
    totalBytes += 512 * 8;
  }

  for (i = 0; i < 100000; i++)
  {
    printf("%f\n", measurement[i]); // for sd calculation
  }

  double totalMB = totalBytes / 1024 / 1024;
  double totalSeconds = totalCycles / (2.4 * 1000000000);
  double bandwidth = totalMB / totalSeconds;
  printf("RAM read bandwidth: %f\n", bandwidth);

  free(chunkPtr);
}

void expBandwidthWrite()
{
  uint64_t *chunkPtr = malloc(8388608); // 8MB, 16B per long double
  if (chunkPtr == NULL)
  {
    printf("malloc failed");
    exit(1);
  }
  int i;
  uint64_t *ptr = chunkPtr;
  double totalCycles = 0;
  double totalBytes = 0;

  double measurement[100000]; // for sd calculation

  for (i = 0; i < 100000; i++)
  {
    double start, end;
    unsigned lo, hi, lo1, hi1;
    COUNT1(hi, lo)
    UNROLLED_MEM_WRITE_HEAD_TAIL
    COUNT2(hi1, lo1)
    GETNUM(hi, lo, start)
    GETNUM(hi1, lo1, end)
    totalCycles += end - start; // cycles
    // printf("%f\n", end - start);
    measurement[i] = end - start; // for sd calculation
    totalBytes += 512 * 8;
  }

  for (i = 0; i < 100000; i++)
  {
    printf("%f\n", measurement[i]); // for sd calculation
  }

  double totalMB = totalBytes / 1024 / 1024;
  double totalSeconds = totalCycles / (2.4 * 1000000000);
  double bandwidth = totalMB / totalSeconds;
  printf("RAM write bandwidth: %f\n", bandwidth);

  free(chunkPtr);
}

/* Measure RAM Bandwidth END */

/* Measure Overhead of Page Fault */
void measurePageFault()
{
  uint64_t start, end, totalTime = 0;
  unsigned cycles_high, cycles_low, cycles_high1, cycles_low1;
  char *map;
  int i, fd, COUNT = 100;
  uint64_t FILE_SIZE = 1200 * 1024 * 1024, offset = 0, pageSize = 4096; //file size is 1.2GB

  if ((fd = open("testfile", O_RDONLY)) < 0)
  {
    printf("Can't open testfile");
    exit(1);
  }

  for (i = 0; i < COUNT; i++)
  {
    system("sudo purge"); // clear RAM and disk cache of mac OS
    map = mmap(NULL, pageSize, PROT_READ, MAP_PRIVATE, fd, offset);

    COUNT1(cycles_high, cycles_low)
    char ch = map[0];
    COUNT2(cycles_high1, cycles_low1)
    GETNUM(cycles_high, cycles_low, start)
    GETNUM(cycles_high1, cycles_low1, end)
    if (end - start < 1000000)
      totalTime += end - start;
    munmap(map, pageSize);

    printf("time_%d = %llu\n", i + 1, end - start);
    // offset += 20*1024*1024; //3MB
    // if(offset > FILE_SIZE)  offset = 0;
  }

  close(fd);
  printf("Page fault time = %f\n", totalTime / (double)COUNT);
}

/* End of Measurement for Page Fault */

/* Measure RAM Access Time BEGIN */

void measureAccessTime(uint64_t stride, uint64_t arraySize)
{
  uint64_t i; // sizeof(uint64_t) == 8
  uint64_t j;
  uint64_t nextIndex = 0;
  uint64_t rounds = 1000;
  uint64_t *array = malloc(arraySize);
  uint64_t numOfElem = arraySize / sizeof(uint64_t);
  if (array == NULL)
  {
    printf("malloc failed, exiting\n");
    exit(1);
  }
  for (i = 0; i < numOfElem; i++) {
    array[i] = (stride + i) % numOfElem;
  }

  double start, end;
  unsigned lo, hi, lo1, hi1;

  COUNT1(hi, lo)
  for (i = 0; i < rounds; i++)
  {
    nextIndex = array[nextIndex];
  }
  COUNT2(hi1, lo1)
  GETNUM(hi, lo, start)
  GETNUM(hi1, lo1, end)
  double perAccessCycles = (end - start) / (double)rounds;
  printf("%f\n", perAccessCycles);
  free(array);
}

int main()
{
  uint64_t strideIndex, arraySize;
  uint64_t strides[] = {64/*, 128, 256, 512, 1024*/};
  uint64_t totalRepeat = 10;
  uint64_t repeat;
  for (strideIndex = 0; strideIndex < 1; strideIndex++) {
    printf("stride: %llu\n", strides[strideIndex]);
    for (arraySize = 8; arraySize <= 134217728; arraySize *= 2) {
      printf("arraySize: %llu\n", arraySize);
      for (repeat = 0; repeat < totalRepeat; repeat++) {
        measureAccessTime(strides[strideIndex], arraySize);
      }
    }
  }
}

/* Measure RAM Access Time END */

int mainOld()
{
  srand(time(NULL));
  // measureRAMAccessTime();
  // measurePageFault();
  // expBandwidthRead();
  expBandwidthWrite();
  return 0;
}
