#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
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
#define SYS_CALL_ROUNDS_OUTER 1000
#define SYS_CALL_ROUNDS_INNER 1000
#define PROCESS_CREATION_ROUNDS 10000
#define THREAD_CREATION_ROUNDS_OUTER 10
#define THREAD_CREATION_ROUNDS_INNER 10

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
  unsigned i, j;
  double avgOverhead;
  struct timeval now;
  for (i = 0; i < SYS_CALL_ROUNDS_OUTER; i++)
  {
    unsigned lo, hi, lo1, hi1;
    double start, end;
    COUNT1(hi, lo)
    for (j = 0; j < SYS_CALL_ROUNDS_INNER; j++)
    {
      gettimeofday(&now, NULL);
      gettimeofday(&now, NULL);
      gettimeofday(&now, NULL);
      gettimeofday(&now, NULL);
      gettimeofday(&now, NULL);
      gettimeofday(&now, NULL);
      gettimeofday(&now, NULL);
      gettimeofday(&now, NULL);
      gettimeofday(&now, NULL);
      gettimeofday(&now, NULL);
    }
    COUNT2(hi1, lo1)
    GETNUM(hi, lo, start)
    GETNUM(hi1, lo1, end)
    avgOverhead += (end - start - READ_TIME_OVERHEAD - LOOP_OVERHEAD * SYS_CALL_ROUNDS_INNER);
  }
  avgOverhead /= (10 * SYS_CALL_ROUNDS_OUTER * SYS_CALL_ROUNDS_INNER);
  printf("The average overhead for system call is: %f\n", avgOverhead);
}

/* System Call Overhead END */

/* Task Creation Time BEGIN */

void measureProcessCreationTime()
{
  unsigned i;
  double avgOverhead;
  for (i = 0; i < PROCESS_CREATION_ROUNDS; i++)
  {
    unsigned lo, hi, lo1, hi1;
    double start, end;
    COUNT1(hi, lo)
    pid_t pid = fork();
    COUNT2(hi1, lo1)
    GETNUM(hi, lo, start)
    GETNUM(hi1, lo1, end)
    if (pid == 0)
    {
      exit(0);
    }
    avgOverhead += (end - start);
  }
  avgOverhead -= READ_TIME_OVERHEAD * PROCESS_CREATION_ROUNDS;
  avgOverhead /= PROCESS_CREATION_ROUNDS;
  printf("The average overhead for process creation is: %f\n", avgOverhead);
}

void *fRunByThread(void *void_ptr) {
  return NULL;
}

void measureThreadCreationTime()
{
  unsigned i, j;
  double avgOverhead;
  for (i = 0; i < THREAD_CREATION_ROUNDS_OUTER; i++) {
    for (j = 0; j < THREAD_CREATION_ROUNDS_INNER; j++) {
      unsigned lo, hi, lo1, hi1;
      double start, end;
      int dummy = 0;
      pthread_t t1;
      pthread_t t2;
      pthread_t t3;
      pthread_t t4;
      pthread_t t5;
      pthread_t t6;
      pthread_t t7;
      pthread_t t8;
      pthread_t t9;
      pthread_t t10;
      COUNT1(hi, lo)
      pthread_create(&t1, NULL, fRunByThread, &dummy);
      pthread_create(&t2, NULL, fRunByThread, &dummy);
      pthread_create(&t3, NULL, fRunByThread, &dummy);
      pthread_create(&t4, NULL, fRunByThread, &dummy);
      pthread_create(&t5, NULL, fRunByThread, &dummy);
      pthread_create(&t6, NULL, fRunByThread, &dummy);
      pthread_create(&t7, NULL, fRunByThread, &dummy);
      pthread_create(&t8, NULL, fRunByThread, &dummy);
      pthread_create(&t9, NULL, fRunByThread, &dummy);
      pthread_create(&t10, NULL, fRunByThread, &dummy);
      COUNT2(hi1, lo1)
      GETNUM(hi, lo, start)
      GETNUM(hi1, lo1, end)
      avgOverhead += (end - start - READ_TIME_OVERHEAD);
    }
  }
  avgOverhead -= LOOP_OVERHEAD * THREAD_CREATION_ROUNDS_OUTER * THREAD_CREATION_ROUNDS_INNER; 
  avgOverhead /= (10 * THREAD_CREATION_ROUNDS_OUTER * THREAD_CREATION_ROUNDS_INNER);
  printf("The average overhead for thread creation is: %f\n", avgOverhead);
}

/* Task Creation Time END */

int main()
{
  // /* measurement overhead */
  // measureReadTimeOverhead();
  // measureLoopOverhead();

  // /* procedure call overhead */
  // measure0arg();
  // measure1arg();
  // measure2arg();
  // measure3arg();
  // measure4arg();
  // measure5arg();
  // measure6arg();
  // measure7arg();

  // /* system call overhead */
  // measureSystemCallOverhead();

  // /* measure process/thread creation time */
  // measureProcessCreationTime();
  measureThreadCreationTime();

  return 0;
}
