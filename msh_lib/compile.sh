#! /bin/bash

gcc -c -fPIC mshlib.c -o mshlib.o
gcc -shared -o mshlib.so mshlib.o
