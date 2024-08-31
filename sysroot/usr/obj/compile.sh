#! /bin/bash

i686-elf-gcc -T linker.ld -o tomos.bin -ffreestanding -O2 -nostdlib *.o -lgcc -I../include

if grub-file --is-x86-multiboot tomos.bin; then
	echo multiboot confirmed
else
	echo tomos.bin is not multiboot
fi
