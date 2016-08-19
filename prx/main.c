#include <stdio.h>

#include <psp2/ctrl.h>
#include <psp2/kernel/modulemgr.h>
#include <psp2/moduleinfo.h>
#include <psp2/power.h>

#define freq = 444

extern "C" {
	int scePowerSetArmClockFrequency(int freq);
}

int module_start(SceSize args, void *argp) {
  SceUID thid;

  scePowerSetArmClockFrequency(freq);

  return 0;
}

int module_stop(void) {
  return 0;
}

int main() {
  module_start();
  module_stop();
  return 0xDEADBEEF;
}
