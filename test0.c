#include <unistd.h>
#include <stdio.h>
#include "nano.h"

int main()
{
  int i;
  uint64_t a;
  uint64_t b;
  for (i = 0; i < 10; i++) {
    a = getNano();
    sleep(1);
    b = getNano();
    printf("%llu\n", b-a);
  }
  return 0;
}
