echo "loading mbr"
nasm -I include/ -o mbr.bin mbr.S&&dd if=./mbr.bin of=../config/disk_images/hd60M.img bs=512 count=1 conv=notrunc
echo "loading loader"
nasm -I include/ -o loader.bin loader.S&&dd if=./loader.bin of=../config/disk_images/hd60M.img bs=512 count=1 seek=2 conv=notrunc
echo "loading kernel"
gcc -c -o ../kernel/main.out ../kernel/main.c&&ld main.out -Ttext Oxe0001500 -e main -o kernel.bin

echo "starting"
bochs -f ../config/second.disk;
