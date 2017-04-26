#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <sys/time.h>
#include <errno.h>
#include "count.h"

#define READ_TIME_ROUNDS 10000
#define READ_TIME_OVERHEAD 31
#define LOOP_ROUNDS_OUTER 1000
#define LOOP_ROUNDS_INNER 10000
#define LOOP_OVERHEAD 6
#define PROCEDURE_CALL_ROUNDS_OUTER 1000
#define PROCEDURE_CALL_ROUNDS_INNER 1000
#define SYS_CALL_ROUNDS 10000

/* Measure Overhead BEGIN */

void measureReadTimeOverhead()
{
  unsigned i;
  double avgOverhead;
  for (i = 0; i < READ_TIME_ROUNDS; i++)
  {
    double start, end;
    unsigned lo, hi, lo1, hi1;
    COUNT1(hi, lo)
    COUNT2(hi1, lo1)
    GETNUM(hi, lo, start)
    GETNUM(hi1, lo1, end)
    avgOverhead += (end - start);
  }
  avgOverhead /= READ_TIME_ROUNDS;
  printf("Average overhead for reading time is: %f\n", avgOverhead);
}

void measureLoopOverhead()
{
  unsigned i, j;
  double avgOverhead;
  for (i = 0; i < LOOP_ROUNDS_OUTER; i++)
  {
    double start, end;
    unsigned lo, hi, lo1, hi1;
    COUNT1(hi, lo)
    for (j = 0; j < LOOP_ROUNDS_INNER; j++)
    {
    }
    COUNT2(hi1, lo1)
    GETNUM(hi, lo, start)
    GETNUM(hi1, lo1, end)
    avgOverhead += (end - start);
    avgOverhead -= READ_TIME_OVERHEAD;
  }
  avgOverhead /= (LOOP_ROUNDS_OUTER * LOOP_ROUNDS_INNER);
  printf("Average overhead for loop is: %f\n", avgOverhead);
}

/* Measure Overhead END */

/* Procedure Call Overhead BEGIN */

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

void __attribute__((noinline)) p8(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8)
{
}

void measure0arg()
{
  unsigned i, j;
  double avgOverhead;
  for (i = 0; i < PROCEDURE_CALL_ROUNDS_OUTER; i++)
  {
    unsigned lo, hi, lo1, hi1;
    double start, end;
    COUNT1(hi, lo)
    for (j = 0; j < PROCEDURE_CALL_ROUNDS_INNER; j++)
    {
      p0();
      p0();
      p0();
      p0();
      p0();
      p0();
      p0();
      p0();
      p0();
      p0();
    }
    COUNT2(hi1, lo1)
    GETNUM(hi, lo, start)
    GETNUM(hi1, lo1, end)
    avgOverhead += (end - start - READ_TIME_OVERHEAD - LOOP_OVERHEAD * PROCEDURE_CALL_ROUNDS_INNER);
  }
  avgOverhead /= (10 * PROCEDURE_CALL_ROUNDS_OUTER * PROCEDURE_CALL_ROUNDS_INNER);
  printf("The average overhead for procedure call with 0 argument is: %f\n", avgOverhead);
}

void measure1arg()
{
  unsigned i, j;
  double avgOverhead;
  for (i = 0; i < PROCEDURE_CALL_ROUNDS_OUTER; i++)
  {
    unsigned lo, hi, lo1, hi1;
    double start, end;
    COUNT1(hi, lo)
    for (j = 0; j < PROCEDURE_CALL_ROUNDS_INNER; j++)
    {
      p1(1);
      p1(1);
      p1(1);
      p1(1);
      p1(1);
      p1(1);
      p1(1);
      p1(1);
      p1(1);
      p1(1);
    }
    COUNT2(hi1, lo1)
    GETNUM(hi, lo, start)
    GETNUM(hi1, lo1, end)
    avgOverhead += (end - start - READ_TIME_OVERHEAD - LOOP_OVERHEAD * PROCEDURE_CALL_ROUNDS_INNER);
  }
  avgOverhead /= (10 * PROCEDURE_CALL_ROUNDS_OUTER * PROCEDURE_CALL_ROUNDS_INNER);
  printf("The average overhead for procedure call with 1 argument is: %f\n", avgOverhead);
}

void measure2arg()
{
  unsigned i, j;
  double avgOverhead;
  for (i = 0; i < PROCEDURE_CALL_ROUNDS_OUTER; i++)
  {
    unsigned lo, hi, lo1, hi1;
    double start, end;
    COUNT1(hi, lo)
    for (j = 0; j < PROCEDURE_CALL_ROUNDS_INNER; j++)
    {
      p2(1, 2);
      p2(1, 2);
      p2(1, 2);
      p2(1, 2);
      p2(1, 2);
      p2(1, 2);
      p2(1, 2);
      p2(1, 2);
      p2(1, 2);
      p2(1, 2);
    }
    COUNT2(hi1, lo1)
    GETNUM(hi, lo, start)
    GETNUM(hi1, lo1, end)
    avgOverhead += (end - start - READ_TIME_OVERHEAD - LOOP_OVERHEAD * PROCEDURE_CALL_ROUNDS_INNER);
  }
  avgOverhead /= (10 * PROCEDURE_CALL_ROUNDS_OUTER * PROCEDURE_CALL_ROUNDS_INNER);
  printf("The average overhead for procedure call with 2 argument is: %f\n", avgOverhead);
}

void measure3arg()
{
  unsigned i, j;
  double avgOverhead;
  for (i = 0; i < PROCEDURE_CALL_ROUNDS_OUTER; i++)
  {
    unsigned lo, hi, lo1, hi1;
    double start, end;
    COUNT1(hi, lo)
    for (j = 0; j < PROCEDURE_CALL_ROUNDS_INNER; j++)
    {
      p3(1, 2, 3);
      p3(1, 2, 3);
      p3(1, 2, 3);
      p3(1, 2, 3);
      p3(1, 2, 3);
      p3(1, 2, 3);
      p3(1, 2, 3);
      p3(1, 2, 3);
      p3(1, 2, 3);
      p3(1, 2, 3);
    }
    COUNT2(hi1, lo1)
    GETNUM(hi, lo, start)
    GETNUM(hi1, lo1, end)
    avgOverhead += (end - start - READ_TIME_OVERHEAD - LOOP_OVERHEAD * PROCEDURE_CALL_ROUNDS_INNER);
  }
  avgOverhead /= (10 * PROCEDURE_CALL_ROUNDS_OUTER * PROCEDURE_CALL_ROUNDS_INNER);
  printf("The average overhead for procedure call with 3 argument is: %f\n", avgOverhead);
}

void measure4arg()
{
  unsigned i, j;
  double avgOverhead;
  for (i = 0; i < PROCEDURE_CALL_ROUNDS_OUTER; i++)
  {
    unsigned lo, hi, lo1, hi1;
    double start, end;
    COUNT1(hi, lo)
    for (j = 0; j < PROCEDURE_CALL_ROUNDS_INNER; j++)
    {
      p4(1, 2, 3, 4);
      p4(1, 2, 3, 4);
      p4(1, 2, 3, 4);
      p4(1, 2, 3, 4);
      p4(1, 2, 3, 4);
      p4(1, 2, 3, 4);
      p4(1, 2, 3, 4);
      p4(1, 2, 3, 4);
      p4(1, 2, 3, 4);
      p4(1, 2, 3, 4);
    }
    COUNT2(hi1, lo1)
    GETNUM(hi, lo, start)
    GETNUM(hi1, lo1, end)
    avgOverhead += (end - start - READ_TIME_OVERHEAD - LOOP_OVERHEAD * PROCEDURE_CALL_ROUNDS_INNER);
  }
  avgOverhead /= (10 * PROCEDURE_CALL_ROUNDS_OUTER * PROCEDURE_CALL_ROUNDS_INNER);
  printf("The average overhead for procedure call with 4 argument is: %f\n", avgOverhead);
}

void measure5arg()
{
  unsigned i, j;
  double avgOverhead;
  for (i = 0; i < PROCEDURE_CALL_ROUNDS_OUTER; i++)
  {
    unsigned lo, hi, lo1, hi1;
    double start, end;
    COUNT1(hi, lo)
    for (j = 0; j < PROCEDURE_CALL_ROUNDS_INNER; j++)
    {
      p5(1, 2, 3, 4, 5);
      p5(1, 2, 3, 4, 5);
      p5(1, 2, 3, 4, 5);
      p5(1, 2, 3, 4, 5);
      p5(1, 2, 3, 4, 5);
      p5(1, 2, 3, 4, 5);
      p5(1, 2, 3, 4, 5);
      p5(1, 2, 3, 4, 5);
      p5(1, 2, 3, 4, 5);
      p5(1, 2, 3, 4, 5);
    }
    COUNT2(hi1, lo1)
    GETNUM(hi, lo, start)
    GETNUM(hi1, lo1, end)
    avgOverhead += (end - start - READ_TIME_OVERHEAD - LOOP_OVERHEAD * PROCEDURE_CALL_ROUNDS_INNER);
  }
  avgOverhead /= (10 * PROCEDURE_CALL_ROUNDS_OUTER * PROCEDURE_CALL_ROUNDS_INNER);
  printf("The average overhead for procedure call with 5 argument is: %f\n", avgOverhead);
}

void measure6arg()
{
  unsigned i, j;
  double avgOverhead;
  for (i = 0; i < PROCEDURE_CALL_ROUNDS_OUTER; i++)
  {
    unsigned lo, hi, lo1, hi1;
    double start, end;
    COUNT1(hi, lo)
    for (j = 0; j < PROCEDURE_CALL_ROUNDS_INNER; j++)
    {
      p6(1, 2, 3, 4, 5, 6);
      p6(1, 2, 3, 4, 5, 6);
      p6(1, 2, 3, 4, 5, 6);
      p6(1, 2, 3, 4, 5, 6);
      p6(1, 2, 3, 4, 5, 6);
      p6(1, 2, 3, 4, 5, 6);
      p6(1, 2, 3, 4, 5, 6);
      p6(1, 2, 3, 4, 5, 6);
      p6(1, 2, 3, 4, 5, 6);
      p6(1, 2, 3, 4, 5, 6);
    }
    COUNT2(hi1, lo1)
    GETNUM(hi, lo, start)
    GETNUM(hi1, lo1, end)
    avgOverhead += (end - start - READ_TIME_OVERHEAD - LOOP_OVERHEAD * PROCEDURE_CALL_ROUNDS_INNER);
  }
  avgOverhead /= (10 * PROCEDURE_CALL_ROUNDS_OUTER * PROCEDURE_CALL_ROUNDS_INNER);
  printf("The average overhead for procedure call with 6 argument is: %f\n", avgOverhead);
}

void measure7arg()
{
  unsigned i, j;
  double avgOverhead;
  for (i = 0; i < PROCEDURE_CALL_ROUNDS_OUTER; i++)
  {
    unsigned lo, hi, lo1, hi1;
    double start, end;
    COUNT1(hi, lo)
    for (j = 0; j < PROCEDURE_CALL_ROUNDS_INNER; j++)
    {
      p7(1, 2, 3, 4, 5, 6, 7);
      p7(1, 2, 3, 4, 5, 6, 7);
      p7(1, 2, 3, 4, 5, 6, 7);
      p7(1, 2, 3, 4, 5, 6, 7);
      p7(1, 2, 3, 4, 5, 6, 7);
      p7(1, 2, 3, 4, 5, 6, 7);
      p7(1, 2, 3, 4, 5, 6, 7);
      p7(1, 2, 3, 4, 5, 6, 7);
      p7(1, 2, 3, 4, 5, 6, 7);
      p7(1, 2, 3, 4, 5, 6, 7);
    }
    COUNT2(hi1, lo1)
    GETNUM(hi, lo, start)
    GETNUM(hi1, lo1, end)
    avgOverhead += (end - start - READ_TIME_OVERHEAD - LOOP_OVERHEAD * PROCEDURE_CALL_ROUNDS_INNER);
  }
  avgOverhead /= (10 * PROCEDURE_CALL_ROUNDS_OUTER * PROCEDURE_CALL_ROUNDS_INNER);
  printf("The average overhead for procedure call with 7 argument is: %f\n", avgOverhead);
}

/* Procedure Call Overhead END */

/* System Call Overhead BEGIN */

void measureSystemCallOverhead()
{
  uint64_t i, avgOverhead;
  for (i = 0; i < SYS_CALL_ROUNDS; i++)
  {
    unsigned lo, hi, lo1, hi1, start, end;
    struct timeval now;
    COUNT1(hi, lo)
    gettimeofday(&now, NULL);
    // getpid();
    COUNT2(hi1, lo1)
    GETNUM(hi, lo, start)
    GETNUM(hi1, lo1, end)
    avgOverhead += (end - start);
    // printf("%u\n", (end - start));
  }
  avgOverhead -= SYS_CALL_ROUNDS * READ_TIME_OVERHEAD;
  avgOverhead /= SYS_CALL_ROUNDS;
  printf("The average overhead for system call is: %llu\n", avgOverhead);
}

/* System Call Overhead END */

/* Task Creation Time BEGIN */

void measureProcessCreationTime()
{
}

void measureThreadCreationTime()
{
}

/* Task Creation Time END */

int main()
{
  /* measurement overhead */
  measureReadTimeOverhead();
  measureLoopOverhead();

  // /* procedure call overhead */
  measure0arg();
  measure1arg();
  measure2arg();
  measure3arg();
  measure4arg();
  measure5arg();
  measure6arg();
  measure7arg();

  /* system call overhead */
  // measureSystemCallOverhead();

  return 0;
}
