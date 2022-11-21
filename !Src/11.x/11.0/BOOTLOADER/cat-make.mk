# Makefile
$(BUILD_DIR)/$(PROJECT)-app.bin: $(BUILD_DIR)/$(PROJECT)-app.elf
  $(OCPY) $< $@ -O binary
  $(SZ) $<

$(BUILD_DIR)/$(PROJECT)-boot.bin: $(BUILD_DIR)/$(PROJECT)-boot.elf
  $(OCPY) --pad-to=0x4000 --gap-fill=0xFF -O binary $< $@
  $(SZ) $<

# Makefile
$(BUILD_DIR)/$(PROJECT).bin: $(BUILD_DIR)/$(PROJECT)-boot.bin $(BUILD_DIR)/$(PROJECT)-app.bin
  cat $^ > $@
