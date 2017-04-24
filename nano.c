#include <stdint.h>

#if defined(__APPLE__)

#include <mach/mach_time.h>

static mach_timebase_info_data_t timebaseInfo;
static void __attribute__((constructor)) getTimebase() {
  mach_timebase_info(&timebaseInfo);
}

uint64_t getNano() {
  uint64_t time = mach_absolute_time();
  time = time * timebaseInfo.numer;
  time = time / timebaseInfo.denom;
  return time;
}

#endif