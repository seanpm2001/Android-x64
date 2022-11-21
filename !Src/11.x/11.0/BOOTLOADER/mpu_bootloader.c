/* bootloader.c */
int main(void) {
  /* ... */
  base_addr = 0x0;
  *mpu_rbar = (base_addr | 1 << 4 | 1);
  //  AP=0b110 to make the region read-only regardless of privilege
  //  TEXSCB=0b000010 because the Code is in "Flash memory"
  //  SIZE=13 because we want to cover 16kiB
  //  ENABLE=1
  *mpu_rasr = (0b110 << 24) | (0b000010 << 16) | (13 << 1) | 0x1;

  start_app(app_start, app_sp);

  /* Not reached */
  while (1) {}
}
