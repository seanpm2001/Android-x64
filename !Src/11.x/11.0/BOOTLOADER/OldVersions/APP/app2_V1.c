/* app.c */
int main() {
  serial_init();
  set_output(LED_0_PIN);

  printf("App!\n");
  while (true) {
    port_pin_toggle_output_level(LED_0_PIN);
    for (int i = 0; i < 100000; ++i) {}
  }
}
