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
#define SZ_4G 4294967296
#define SZ_3G 3221225472
#define SZ_2G 2147483648
#define SZ_1G 1073741824
#define SZ_10MB 10485760
#define SZ_1MB 1048576
#define SSD_BLOCK_SIZE 4096
#define CYC_PER_SECOND 2.4e9
void measureFileCacheSize(uint64_t fileSize, char *path)
{
  int largeFile = open(path, O_RDONLY);
  char *buf = malloc(SZ_10MB); // 1 char = 1 byte
  uint64_t numOfChunks = fileSize / SSD_BLOCK_SIZE;
  uint64_t i;

  uint64_t k;
  double start, end;
  unsigned lo, hi, lo1, hi1;
  COUNT1(hi, lo)
  for (i = 0; i < numOfChunks; i++)
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
  for (round = 0; round < 1; round++)
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
    rate = ((double) (SZ_10MB * readOccurrence) / 1024.0 / 1024.0) / ((end - start) / CYC_PER_SECOND);
    // printf("read %zd time\n", readOccurrence);
    printf("%f MB/s\n", rate);
    close(largeFile);
  }
}

int main()
{
  system("sudo purge");
  measureFileCacheSize(SZ_1G, "/Users/lee/Documents/1g");
  // printf("\n");
  system("sudo purge");
  measureFileCacheSize(SZ_2G, "/Users/lee/Documents/2g");
  // printf("\n");
  system("sudo purge");
  measureFileCacheSize(SZ_3G, "/Users/lee/Documents/3g");
  // printf("\n");
  system("sudo purge");
  measureFileCacheSize(SZ_4G, "/Users/lee/Documents/4g");
  // printf("\n");
  system("sudo purge");
  measureFileCacheSize(SZ_5G, "/Users/lee/Documents/5g");
  // printf("\n");
  system("sudo purge");
  measureFileCacheSize(SZ_6G, "/Users/lee/Documents/6g");
  // printf("\n");
  system("sudo purge");
  measureFileCacheSize(SZ_7G, "/Users/lee/Documents/7g");
  // printf("\n");
  system("sudo purge");
  measureFileCacheSize(SZ_8G, "/Users/lee/Documents/8g");
  // printf("\n");

  return 0;
}

/* Measure File Cache Size END */