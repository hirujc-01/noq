clear
make clean
echo "[Build has been cleaned 1/2]"
make
echo "[OS is compiled 2/2]"
echo "[OS is ready for launch!]"
qemu-system-i386 -debugcon stdio -fda build/main_floppy.img