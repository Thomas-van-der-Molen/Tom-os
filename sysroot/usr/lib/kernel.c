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
#include "mshlib.h"

/* Function Definitions */
void kernel(void)
{
  static const char cv[25] = {'H', 'e', 'l', 'l', 'o', ' ', 'f', 'r', 'o',
                              'm', ' ', 'm', 'a', 't', 'l', 'a', 'b', ' ',
                              'k', 'e', 'r', 'n', 'e', 'l', '!'};
  double terminal_column;
  unsigned int terminal_row;
  int x;
  int y;
  /* disp("Hello from kernel") */
  /* disp("Hello from terminal_initialize") */
  /* terminal_column= uint32(0); */
  /* always need -1 with arrays */
  /* terminal_buffer = uint16(vga_width * vga_height); */
  /* terminal_buffer = createArray([1 vga_width*vga_height], "uint16"); */
  for (y = 0; y < 26; y++) {
    for (x = 0; x < 81; x++) {
      /* disp("Hello from vga_entry") */
      /* uc = uint8(uc); */
      /* uc = str2ascii(uc,1); */
      /* color = uint8(color); */
      /* ret = uint16(ret); */
      use_video_memory((unsigned int)y * 80U + (unsigned int)x, 1824);
    }
  }
  /* [vga_width,vga_height,terminal_row,terminal_column,terminal_color,terminal_buffer]
   */
  terminal_row = 0U;
  terminal_column = 0.0;
  /* disp("Hello from terminal_write") */
  for (y = 0; y < 25; y++) {
    double d;
    unsigned long u;
    unsigned int q0;
    unsigned int qY;
    /* disp("Hello from terminal_putchar") */
    /* disp("Hello from terminal_putentryat") */
    /* +1 always needed */
    /* terminal_buffer(x, y) = vga_entry(c, color); */
    /* terminal_buffer(index) = vga_entry(c, color); */
    /* disp("Hello from vga_entry") */
    /* uc = uint8(uc); */
    /* uc = str2ascii(uc,1); */
    /* color = uint8(color); */
    /* ret = uint16(ret); */
    u = terminal_row * 80UL;
    if (u > 4294967295UL) {
      u = 4294967295UL;
    }
    d = (double)(unsigned int)u + terminal_column;
    if (d < 4.294967296E+9) {
      q0 = (unsigned int)d;
    } else {
      q0 = MAX_uint32_T;
    }
    qY = q0 + 1U;
    if (q0 + 1U < q0) {
      qY = MAX_uint32_T;
    }
    use_video_memory(qY, (unsigned short)(cv[y] | 1792));
    if (terminal_column + 1.0 == 80.0) {
      terminal_column = 0.0;
      qY = terminal_row + 1U;
      if (terminal_row + 1U < terminal_row) {
        qY = MAX_uint32_T;
      }
      q0 = terminal_row + 1U;
      if (terminal_row + 1U < terminal_row) {
        q0 = MAX_uint32_T;
      }
      if (qY == 25U) {
        terminal_row = 0U;
      } else {
        terminal_row = q0;
      }
    } else {
      /* assert(isa(terminal_column,"uint32")) */
      /* whos terminal_column */
      /* terminal_columnType = class(terminal_column); */
      /* terminal_column = cast(terminal_column, "uint32") */
      terminal_column++;
      /* terminal_column = uint32(terminal_column); */
      /* terminal_column = cast(terminal_column,"uint32") */
      /* what the fuck */
      /* whos terminal_column */
    }
  }
}

/* End of code generation (kernel.c) */
