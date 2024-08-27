/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * kernel.c
 *
 * Code generation for function 'kernel'
 *
 */

/* Include files */
#include "kernel.h"
#include <stdio.h>

/* Function Definitions */
void kernel(void)
{
  int i;
  printf("%s\n", "Hello from kernel");
  fflush(stdout);
  printf("%s\n", "Hello from terminal_initialize");
  fflush(stdout);
  /* terminal_column= uint32(0); */
  printf("%s\n", "Hello from vga_entry_color");
  fflush(stdout);
  /* whos ret b */
  /* always need -1 with arrays */
  /* terminal_buffer = uint16(vga_width * vga_height); */
  /* terminal_buffer = createArray([1 vga_width*vga_height], "uint16"); */
  /* [vga_width,vga_height,terminal_row,terminal_column,terminal_color,terminal_buffer]
   */
  printf("%s\n", "Hello from terminal_write");
  fflush(stdout);
  for (i = 0; i < 25; i++) {
    printf("%s\n", "Hello from terminal_putchar");
    fflush(stdout);
    printf("%s\n", "Hello from terminal_putentryat");
    fflush(stdout);
    /* +1 always needed */
    /* terminal_buffer(x, y) = vga_entry(c, color); */
    printf("%s\n", "Hello from vga_entry");
    fflush(stdout);
    /* uc = uint8(uc); */
    /* uc = str2ascii(uc,1); */
    /* color = uint8(color); */
    /* ret = uint16(ret); */
  }
}

/* End of code generation (kernel.c) */
