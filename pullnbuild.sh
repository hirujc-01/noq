git pull
clear
make clean
echo "[Build has been cleaned 1/2]"
make
echo "[OS is compiled 2/2]"
scp hirujc@192.168.1.85:/home/hirujc/noq/build/main_floppy.img .
