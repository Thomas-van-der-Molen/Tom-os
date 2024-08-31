#! /bin/bash

i686-elf-gcc -c kernel.c -std=gnu99 -ffreestanding -O2 -Wall -Wextra -I../include
i686-elf-gcc -c kernel_initialize.c -std=gnu99 -ffreestanding -O2 -Wall -Wextra -I../include
i686-elf-gcc -c kernel_terminate.c -std=gnu99 -ffreestanding -O2 -Wall -Wextra -I../include
i686-elf-gcc -c main.c -std=gnu99 -ffreestanding -O2 -Wall -Wextra -I../include
i686-elf-gcc -c mshlib.c -std=gnu99 -ffreestanding -O2 -Wall -Wextra -I../include

mv *.o ../obj
