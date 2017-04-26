#include <stdio.h>
#include <stdint.h>
#include <unistd.h>

int main() {
  uint64_t a = 221;
  double b = 0;
  b = (double) a;
  printf("%f\n", b);
  return 0;
}