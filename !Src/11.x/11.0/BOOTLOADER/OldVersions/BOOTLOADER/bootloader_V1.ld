/* bootloader.ld */
INCLUDE memory_map.ld

/* Section Definitions */
SECTIONS
{
    .text :
    {
        KEEP(*(.vectors .vectors.*))
        *(.text*)
        *(.rodata*)
        _etext = .;
    } > bootrom
  ...
}
