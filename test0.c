#include <stdio.h>
#include <unistd.h>
#include "monotonic_timer.c"

int main(int argc, char* argv[])
{
  int i;
  double a;
  double b;
  for (i = 0; i < 10; i++) {
    a = monotonic_seconds();
    sleep(1);
    b = monotonic_seconds();
    printf("%llu\n", b-a);
  }
  return 0;
}
