/* boootloader.c */
#include <inttypes.h>
#include "memory_map.h"

static void start_app(uint32_t pc, uint32_t sp) {
    __asm("           \n\
          msr msp, r1 /* load r1 into MSP */\n\
          bx r0       /* branch to the address at r0 */\n\
    ");
}

int main() {
  serial_init();
  printf("Bootloader!\n");
  serial_deinit();

  uint32_t *app_code = (uint32_t *)__approm_start__;
  uint32_t app_sp = app_code[0];
  uint32_t app_start = app_code[1];

  start_app(app_start, app_sp);

  // should never be reached
  while (1);
}
