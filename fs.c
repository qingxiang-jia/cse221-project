#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <fcntl.h>
#include "headers/count.h"

/* Measure File Cache Size BEGIN */

#define SZ_30G 32212254720
#define SZ_19G 20401094656
#define SZ_18G 19327352832
#define SZ_17G 18253611008
#define SZ_16G 17179869184
#define SZ_15G 16106127360
#define SZ_14G 15032385536
#define SZ_13G 13958643712
#define SZ_12G 12884901888
#define SZ_11G 11811160064
#define SZ_10G 10737418240
#define SZ_9G 9663676416
#define SZ_8G 8589934592
#define SZ_7G 7516192768
#define SZ_6G 6442450944
#define SZ_5G 5368709120
#define SZ_4p5G 4831838208
#define SZ_4G 4294967296
#define SZ_3G 3221225472
#define SZ_2G 2147483648
#define SZ_1G 1073741824
#define SZ_10MB 10485760
#define SZ_512MB 536870912
#define SZ_256MB 268435456
#define SZ_128MB 134217728
#define SZ_64MB 67108864
#define SZ_32MB 33554432
#define SZ_16MB 16777216
#define SZ_8MB 8388608
#define SZ_4MB 4194304
#define SZ_2MB 2097152
#define SZ_1MB 1048576
#define SSD_BLOCK_SIZE 4096
// #define CYC_PER_SECOND 2.4e9
#define CYC_PER_SECOND 2e9
void measureFileCacheSize(uint64_t fileSize, char *path)
{
  int largeFile = open(path, O_RDONLY);
  char *buf = malloc(SZ_10MB); // 1 char = 1 byte
  uint64_t numOfBlocks = fileSize / SSD_BLOCK_SIZE;
  uint64_t i;

  uint64_t k;
  double start, end;
  unsigned lo, hi, lo1, hi1;
  COUNT1(hi, lo)
  for (i = 0; i < numOfBlocks; i++)
  {
    k = read(largeFile, buf, SSD_BLOCK_SIZE);
  }
  COUNT2(hi1, lo1)
  GETNUM(hi, lo, start)
  GETNUM(hi1, lo1, end)
  double rate = (fileSize / 1024.0 / 1024.0) / ((end - start) / CYC_PER_SECOND);
  // printf("%f MB/s\n", rate);
  close(largeFile);

  int round;
  ssize_t bytesRead;
  uint64_t offset = 1024 * SSD_BLOCK_SIZE;
  uint64_t readOccurrence = 0;
  for (round = 0; round < 20; round++)
  {
    largeFile = open(path, O_RDONLY);
    start = 0, end = 0, hi = 0, lo = 0, hi1 = 0, lo1 = 0;
    COUNT1(hi, lo)
    while (1)
    {
      bytesRead = read(largeFile, buf, SZ_10MB);
      if (bytesRead <= 0)
      {
        break;
      }
      lseek(largeFile, offset, SEEK_CUR);
      readOccurrence++;
    }
    COUNT2(hi1, lo1)
    GETNUM(hi, lo, start)
    GETNUM(hi1, lo1, end)
    rate = ((double)(SZ_10MB * readOccurrence) / 1024.0 / 1024.0) / ((end - start) / CYC_PER_SECOND);
    // printf("read %zd time\n", readOccurrence);
    printf("%f MB/s\n", rate);
    close(largeFile);
  }
  free(buf);
}

int main()
{

  system("sudo purge");
  measureFileCacheSize(SZ_4p5G, "/Users/lee/Documents/4p5g");

  // system("sudo purge");
  // measureFileCacheSize(SZ_1G, "/Users/lee/Documents/1g");
  // printf("\n");
  // system("sudo purge");
  // measureFileCacheSize(SZ_2G, "/Users/lee/Documents/2g");
  // printf("\n");
  // system("sudo purge");
  // measureFileCacheSize(SZ_3G, "/Users/lee/Documents/3g");
  // printf("\n");
  // system("sudo purge");
  // measureFileCacheSize(SZ_4G, "/Users/lee/Documents/4g");
  // printf("\n");
  // system("sudo purge");
  // measureFileCacheSize(SZ_5G, "/Users/lee/Documents/5g");
  // printf("\n");
  // system("sudo purge");
  // measureFileCacheSize(SZ_6G, "/Users/lee/Documents/6g");
  // printf("\n");
  // system("sudo purge");
  // measureFileCacheSize(SZ_7G, "/Users/lee/Documents/7g");
  // printf("\n");
  // system("sudo purge");
  // measureFileCacheSize(SZ_8G, "/Users/lee/Documents/8g");
  // printf("\n");
  return 0;
}

/* Measure File Cache Size END */

/* Measure File Read Time BEGIN */

void readFileNoCacheSeq(uint64_t fileSize, char *path)
{
  int file = open(path, O_RDONLY);
  fcntl(file, F_NOCACHE, 1);
  char *buf = malloc(SZ_10MB); // 1 char = 1 byte
  uint64_t numOfBlocks = fileSize / SSD_BLOCK_SIZE;
  uint64_t i;

  double start, end;
  unsigned lo, hi, lo1, hi1;

  double rate;
  double perBlockTime;
  for (i = 0; i < 10; i++)
  {
    system("sudo purge");
    file = open(path, O_RDONLY);
    fcntl(file, F_NOCACHE, 1);
    uint64_t j;
    start = 0, end = 0, lo = 0, hi = 0, lo1 = 0, hi1 = 0;
    COUNT1(hi, lo)
    for (j = 0; j < numOfBlocks; j++)
    {
      read(file, buf, SSD_BLOCK_SIZE);
    }
    COUNT2(hi1, lo1)
    GETNUM(hi, lo, start)
    GETNUM(hi1, lo1, end)
    rate = (fileSize / 1024.0 / 1024.0) / ((end - start) / CYC_PER_SECOND);
    perBlockTime = (end - start) / (double)numOfBlocks / CYC_PER_SECOND * 1000;
    printf("%-10f MB/s           %-10f ms per block\n", rate, perBlockTime);
    close(file);
  }
  free(buf);
}

void readFileNoCacheRand(uint64_t fileSize, char *path)
{
  int file = open(path, O_RDONLY);
  fcntl(file, F_NOCACHE, 1);
  char *buf = malloc(SZ_10MB); // 1 char = 1 byte
  uint64_t numOfBlocks = fileSize / SSD_BLOCK_SIZE;
  uint64_t i;

  double start, end;
  unsigned lo, hi, lo1, hi1;

  time_t t;
  srand((unsigned)time(&t));
  double rate;
  double perBlockTime;
  for (i = 0; i < 10; i++)
  {
    system("sudo purge");
    file = open(path, O_RDONLY);
    fcntl(file, F_NOCACHE, 1);
    uint64_t iterations = numOfBlocks / 2;
    off_t *offset = malloc(iterations * sizeof(off_t));
    uint64_t j;
    for (j = 0; j < iterations; j++)
    {
      offset[j] = (off_t)(rand() % (fileSize - SSD_BLOCK_SIZE));
    }

    start = 0, end = 0, lo = 0, hi = 0, lo1 = 0, hi1 = 0;
    COUNT1(hi, lo)
    for (j = 0; j < iterations; j++)
    {
      lseek(file, offset[j], SEEK_SET);
      read(file, buf, SSD_BLOCK_SIZE);
    }
    COUNT2(hi1, lo1)
    GETNUM(hi, lo, start)
    GETNUM(hi1, lo1, end)
    rate = ((double)iterations * (double)SSD_BLOCK_SIZE / 1024.0 / 1024.0) / ((end - start) / CYC_PER_SECOND);
    perBlockTime = (end - start) / (double)iterations / CYC_PER_SECOND * 1000;
    printf("%-10f MB/s           %-10f ms per block\n", rate, perBlockTime);
    close(file);
    free(offset);
  }
  free(buf);
}

int main2()
{
  // printf("1MB\n");
  // readFileNoCacheSeq(SZ_1MB, "/Users/lee/Documents/1m");
  // printf("2MB\n");
  // readFileNoCacheSeq(SZ_2MB, "/Users/lee/Documents/2m");
  // printf("4MB\n");
  // readFileNoCacheSeq(SZ_4MB, "/Users/lee/Documents/4m");
  // printf("8MB\n");
  // readFileNoCacheSeq(SZ_8MB, "/Users/lee/Documents/8m");
  // printf("16MB\n");
  // readFileNoCacheSeq(SZ_16MB, "/Users/lee/Documents/16m");
  // printf("32MB\n");
  // readFileNoCacheSeq(SZ_32MB, "/Users/lee/Documents/32m");
  // printf("64MB\n");
  // readFileNoCacheSeq(SZ_64MB, "/Users/lee/Documents/64m");
  // printf("128MB\n");
  // readFileNoCacheSeq(SZ_128MB, "/Users/lee/Documents/128m");
  // printf("256MB\n");
  // readFileNoCacheSeq(SZ_256MB, "/Users/lee/Documents/256m");
  // printf("512MB\n");
  // readFileNoCacheSeq(SZ_512MB, "/Users/lee/Documents/512m");
  // printf("1G\n");
  // readFileNoCacheSeq(SZ_1G, "/Users/lee/Documents/1g");
  // printf("1MB\n");
  // readFileNoCacheRand(SZ_1MB, "/Users/lee/Documents/1m");
  // printf("2MB\n");
  // readFileNoCacheRand(SZ_2MB, "/Users/lee/Documents/2m");
  // printf("4MB\n");
  // readFileNoCacheRand(SZ_4MB, "/Users/lee/Documents/4m");
  // printf("8MB\n");
  // readFileNoCacheRand(SZ_8MB, "/Users/lee/Documents/8m");
  // printf("16MB\n");
  // readFileNoCacheRand(SZ_16MB, "/Users/lee/Documents/16m");
  // printf("32MB\n");
  // readFileNoCacheRand(SZ_32MB, "/Users/lee/Documents/32m");
  // printf("64MB\n");
  // readFileNoCacheRand(SZ_64MB, "/Users/lee/Documents/64m");
  // printf("128MB\n");
  // readFileNoCacheRand(SZ_128MB, "/Users/lee/Documents/128m");
  // printf("256MB\n");
  // readFileNoCacheRand(SZ_256MB, "/Users/lee/Documents/256m");
  // printf("512MB\n");
  // readFileNoCacheRand(SZ_512MB, "/Users/lee/Documents/512m");
  // printf("1G\n");
  // readFileNoCacheRand(SZ_1G, "/Users/lee/Documents/1g");

  // printf("1MB\n");
  // readFileNoCacheSeq(SZ_1MB, "/Users/twincus/Desktop/mount/lee/Documents/1m");
  // printf("2MB\n");
  // readFileNoCacheSeq(SZ_2MB, "/Users/twincus/Desktop/mount/lee/Documents/2m");
  // printf("4MB\n");
  // readFileNoCacheSeq(SZ_4MB, "/Users/twincus/Desktop/mount/lee/Documents/4m");
  // printf("8MB\n");
  // readFileNoCacheSeq(SZ_8MB, "/Users/twincus/Desktop/mount/lee/Documents/8m");
  // printf("16MB\n");
  // readFileNoCacheSeq(SZ_16MB, "/Users/twincus/Desktop/mount/lee/Documents/16m");
  // printf("32MB\n");
  // readFileNoCacheSeq(SZ_32MB, "/Users/twincus/Desktop/mount/lee/Documents/32m");
  // printf("64MB\n");
  // readFileNoCacheSeq(SZ_64MB, "/Users/twincus/Desktop/mount/lee/Documents/64m");
  // printf("128MB\n");
  // readFileNoCacheSeq(SZ_128MB, "/Users/twincus/Desktop/mount/lee/Documents/128m");
  // printf("256MB\n");
  // readFileNoCacheSeq(SZ_256MB, "/Users/twincus/Desktop/mount/lee/Documents/256m");
  // printf("512MB\n");
  // readFileNoCacheSeq(SZ_512MB, "/Users/twincus/Desktop/mount/lee/Documents/512m");
  // printf("1G\n");
  // readFileNoCacheSeq(SZ_1G, "/Users/twincus/Desktop/mount/lee/Documents/1g");
  printf("1MB\n");
  readFileNoCacheRand(SZ_1MB, "/Users/twincus/Desktop/mount/lee/Documents/1m");
  printf("2MB\n");
  readFileNoCacheRand(SZ_2MB, "/Users/twincus/Desktop/mount/lee/Documents/2m");
  printf("4MB\n");
  readFileNoCacheRand(SZ_4MB, "/Users/twincus/Desktop/mount/lee/Documents/4m");
  printf("8MB\n");
  readFileNoCacheRand(SZ_8MB, "/Users/twincus/Desktop/mount/lee/Documents/8m");
  printf("16MB\n");
  readFileNoCacheRand(SZ_16MB, "/Users/twincus/Desktop/mount/lee/Documents/16m");
  printf("32MB\n");
  readFileNoCacheRand(SZ_32MB, "/Users/twincus/Desktop/mount/lee/Documents/32m");
  printf("64MB\n");
  readFileNoCacheRand(SZ_64MB, "/Users/twincus/Desktop/mount/lee/Documents/64m");
  printf("128MB\n");
  readFileNoCacheRand(SZ_128MB, "/Users/twincus/Desktop/mount/lee/Documents/128m");
  // printf("256MB\n");
  // readFileNoCacheRand(SZ_256MB, "/Users/twincus/Desktop/mount/lee/Documents/256m");
  // printf("512MB\n");
  // readFileNoCacheRand(SZ_512MB, "/Users/twincus/Desktop/mount/lee/Documents/512m");
  // printf("1G\n");
  // readFileNoCacheRand(SZ_1G, "/Users/twincus/Desktop/mount/lee/Documents/1g");

  return 0;
}

/* Measure File Read Time END */

/* Measure Contention BEGIN */

void readFileSeq(uint64_t fileSize, char *path)
{
  int file = open(path, O_RDONLY);
  fcntl(file, F_NOCACHE, 1);
  char *buf = malloc(SZ_10MB); // 1 char = 1 byte
  uint64_t numOfBlocks = fileSize / SSD_BLOCK_SIZE;
  uint64_t i;

  double start, end;
  unsigned lo, hi, lo1, hi1;

  double rate;
  double perBlockTime;
  for (i = 0; i < 10; i++)
  {
    file = open(path, O_RDONLY);
    fcntl(file, F_NOCACHE, 1);
    uint64_t j;
    start = 0, end = 0, lo = 0, hi = 0, lo1 = 0, hi1 = 0;
    COUNT1(hi, lo)
    for (j = 0; j < numOfBlocks; j++)
    {
      read(file, buf, SSD_BLOCK_SIZE);
    }
    COUNT2(hi1, lo1)
    GETNUM(hi, lo, start)
    GETNUM(hi1, lo1, end)
    rate = (fileSize / 1024.0 / 1024.0) / ((end - start) / CYC_PER_SECOND);
    perBlockTime = (end - start) / (double)numOfBlocks / CYC_PER_SECOND * 1000;
    printf("%-10f MB/s           %-10f ms per block\n", rate, perBlockTime);
    close(file);
  }
  free(buf);
}

void spawn(int numOfProcesses, char *pathTemplate) // pathTemplate: /Users/lee/Documents/512m%d
{
  int i, pid;
  char filePath[50];
  system("sudo purge");

  for (i = 1; i <= numOfProcesses; i++)
  {
    pid = fork();
    if (pid == -1)
    {
      printf("Spawning failed.");
      return;
    }
    if (pid == 0)
    {
      sprintf(filePath, pathTemplate, i);
      // printf("filePath: %s\n", filePath);
      readFileSeq(SZ_64MB, filePath);
      printf("Process %d is done.\n", i);
      return;
    }
  }
}

int main4(int argc, char *argv[])
{
  printf("\n\n");
  spawn(atoi(argv[1]), "/Users/lee/Documents/64m%d");
  // if (argc < 2)
  // {
  //   spawn(2);
  // }
  // else
  // {
  //   spawn(atoi(argv[1]));
  // }
  return 0;
}

/* Measure Contention END */