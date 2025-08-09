#/bin/bash

set -e
rm main_floppy.img
scp hirujc@192.168.1.85:/home/hirujc/noq/build/main_floppy.img .
qemu-system-i386 -fda main_floppy.img
