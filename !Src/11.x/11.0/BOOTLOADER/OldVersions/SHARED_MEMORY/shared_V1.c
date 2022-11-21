/* shared.h */

#include <inttypes.h>

uint8_t shared_data_get_boot_count(void);

void shared_data_increment_boot_count(void);

void shared_data_reset_boot_count(void);
