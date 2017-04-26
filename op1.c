#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include "count.h"

#define READ_TIME_ROUNDS 10000
#define LOOP_ROUNDS 10000
#define READ_TIME_OVERHEAD 32

/* Measure Overhead BEGIN */

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

/* Measure Overhead END */

/* Procedure Call Overhead BEGIN */

#define PROCEDURE_CALL_ROUNDS 10000

void p0()
{
}

void p1(int a1)
{
}

void p2(int a1, int a2)
{
}

void p3(int a1, int a2, int a3)
{
}

void p4(int a1, int a2, int a3, int a4)
{
}

void p5(int a1, int a2, int a3, int a4, int a5)
{
}

void p6(int a1, int a2, int a3, int a4, int a5, int a6)
{
}

void p7(int a1, int a2, int a3, int a4, int a5, int a6, float a7)
{
}

void p8(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8)
{
}

void measure0arg() {
  uint64_t i, avgOverhead;
  for (i = 0; i < PROCEDURE_CALL_ROUNDS; i++) {
    unsigned lo, hi, lo1, hi1, start, end;
    COUNT1(hi, lo)
    p0();
    COUNT2(hi1, lo1)
    GETNUM(hi, lo, start)
    GETNUM(hi1, lo1, end)
    avgOverhead += (end - start);
  }
  avgOverhead /= PROCEDURE_CALL_ROUNDS;
  printf("The average overhead for procedure call with 0 argument is: %llu\n", avgOverhead);
}

void measure1arg() {
  uint64_t i, avgOverhead;
  for (i = 0; i < PROCEDURE_CALL_ROUNDS; i++) {
    unsigned lo, hi, lo1, hi1, start, end;
    COUNT1(hi, lo)
    p1(1);
    COUNT2(hi1, lo1)
    GETNUM(hi, lo, start)
    GETNUM(hi1, lo1, end)
    avgOverhead += (end - start);
  }
  avgOverhead /= PROCEDURE_CALL_ROUNDS;
  printf("The average overhead for procedure call with 1 argument is: %llu\n", avgOverhead);
}

void measure2args() {
  uint64_t i, avgOverhead;
  for (i = 0; i < PROCEDURE_CALL_ROUNDS; i++) {
    unsigned lo, hi, lo1, hi1, start, end;
    COUNT1(hi, lo)
    p2(1, 2);
    COUNT2(hi1, lo1)
    GETNUM(hi, lo, start)
    GETNUM(hi1, lo1, end)
    avgOverhead += (end - start);
  }
  avgOverhead /= PROCEDURE_CALL_ROUNDS;
  printf("The average overhead for procedure call with 2 arguments is: %llu\n", avgOverhead);
}

void measure3args() {
  uint64_t i, avgOverhead;
  for (i = 0; i < PROCEDURE_CALL_ROUNDS; i++) {
    unsigned lo, hi, lo1, hi1, start, end;
    COUNT1(hi, lo)
    p3(1, 2, 3);
    COUNT2(hi1, lo1)
    GETNUM(hi, lo, start)
    GETNUM(hi1, lo1, end)
    avgOverhead += (end - start);
  }
  avgOverhead /= PROCEDURE_CALL_ROUNDS;
  printf("The average overhead for procedure call with 3 arguments is: %llu\n", avgOverhead);
}

void measure4args() {
  uint64_t i, avgOverhead;
  for (i = 0; i < PROCEDURE_CALL_ROUNDS; i++) {
    unsigned lo, hi, lo1, hi1, start, end;
    COUNT1(hi, lo)
    p4(1, 2, 3, 4);
    COUNT2(hi1, lo1)
    GETNUM(hi, lo, start)
    GETNUM(hi1, lo1, end)
    avgOverhead += (end - start);
  }
  avgOverhead /= PROCEDURE_CALL_ROUNDS;
  printf("The average overhead for procedure call with 4 arguments is: %llu\n", avgOverhead);
}

void measure5args() {
  uint64_t i, avgOverhead;
  for (i = 0; i < PROCEDURE_CALL_ROUNDS; i++) {
    unsigned lo, hi, lo1, hi1, start, end;
    COUNT1(hi, lo)
    p5(1, 2, 3, 4, 5);
    COUNT2(hi1, lo1)
    GETNUM(hi, lo, start)
    GETNUM(hi1, lo1, end)
    avgOverhead += (end - start);
  }
  avgOverhead /= PROCEDURE_CALL_ROUNDS;
  printf("The average overhead for procedure call with 5 arguments is: %llu\n", avgOverhead);
}

void measure6args() {
  uint64_t i, avgOverhead;
  for (i = 0; i < PROCEDURE_CALL_ROUNDS; i++) {
    unsigned lo, hi, lo1, hi1, start, end;
    COUNT1(hi, lo)
    p6(1, 2, 3, 4, 5, 6);
    COUNT2(hi1, lo1)
    GETNUM(hi, lo, start)
    GETNUM(hi1, lo1, end)
    avgOverhead += (end - start);
  }
  avgOverhead /= PROCEDURE_CALL_ROUNDS;
  printf("The average overhead for procedure call with 6 arguments is: %llu\n", avgOverhead);
}

void measure7args() {
  uint64_t i, avgOverhead;
  for (i = 0; i < PROCEDURE_CALL_ROUNDS; i++) {
    unsigned lo, hi, lo1, hi1, start, end;
    COUNT1(hi, lo)
    p7(1, 2, 3, 4, 5, 6, 7.0);
    COUNT2(hi1, lo1)
    GETNUM(hi, lo, start)
    GETNUM(hi1, lo1, end)
    avgOverhead += (end - start);
  }
  avgOverhead /= PROCEDURE_CALL_ROUNDS;
  printf("The average overhead for procedure call with 7 arguments is: %llu\n", avgOverhead);
}

void measure8args() {
  uint64_t i, avgOverhead;
  for (i = 0; i < PROCEDURE_CALL_ROUNDS; i++) {
    unsigned lo, hi, lo1, hi1, start, end;
    COUNT1(hi, lo)
    p8(1, 2, 3, 4, 5, 6, 7, 8);
    COUNT2(hi1, lo1)
    GETNUM(hi, lo, start)
    GETNUM(hi1, lo1, end)
    avgOverhead += (end - start);
  }
  avgOverhead /= PROCEDURE_CALL_ROUNDS;
  printf("The average overhead for procedure call with 8 arguments is: %llu\n", avgOverhead);
}

/* Procedure Call Overhead END */

int main()
{
  // measurement overhead
  measureReadTimeOverhead();
  measureLoopOverhead();

  // procedure call overhead
  measure0arg();
  measure1arg();
  measure2args();
  measure3args();
  measure4args();
  measure5args();
  measure6args();
  measure7args();
  measure8args();

  return 0;
}
