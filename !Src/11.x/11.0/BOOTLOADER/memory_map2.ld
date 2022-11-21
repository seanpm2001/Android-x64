/* memory_map.ld */
MEMORY
{
  bootrom  (rx)  : ORIGIN = 0x00000000, LENGTH = 0x00004000
  approm   (rx)  : ORIGIN = 0x00004000, LENGTH = 0x0003C000
  shared   (rwx) : ORIGIN = 0x20000000, LENGTH = 0x1000
  ram      (rwx) : ORIGIN = 0x20001000, LENGTH = 0x00007000
}

/* shared data starts point at the origin of the shared region */
_shared_data_start = ORIGIN(shared);

