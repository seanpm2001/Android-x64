/* shared.c */

#include "shared.h"

extern uint32_t _shared_data_start;

#pragma pack (push)
struct shared_data {
  uint8_t boot_count;
};
#pragma pack (pop)

struct shared_data *sd = (struct shared_data *)&_shared_data_start;

uint8_t shared_data_get_boot_count(void) {
  return sd->boot_count;
}

void shared_data_increment_boot_count(void) {
  sd->boot_count++;
}

void shared_data_reset_boot_count(void) {
  sd->boot_count = 0;
}
