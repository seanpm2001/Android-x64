/* startup_samd21.c */
/* Set the vector table base address */
uint32_t *vector_table = (uint32_t *) &_stext;
uint32_t *vtor = (uint32_t *)0xE000ED08;
*vtor = ((uint32_t) vector_table & 0xFFFFFFF8);
