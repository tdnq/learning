echo "creating disk"
bximage -hd -mode="flat" -size=60 -q hd60M.img
echo "compiling"
nasm -I include/boot -o ./boot/mbr.bin ./boot/mbr.S
nasm -I include/boot -o ./boot/loader.bin ./boot/loader.S
nasm -f elf64 -o include/kernel/print.out include/kernel/print.S
gcc  -I include/kernel/ -c -o ./kernel/main.out ./kernel/main.c
ld -Ttext 0xc0001500 -e main -o ./kernel/kernel.bin ./kernel/main.out ./include/kernel/print.out

echo "wirte bios,mbr,loader to disk"
dd if=./boot/mbr.bin of=./config/disk_images/hd60M.img bs=512 count=1 conv=notrunc
dd if=./boot/loader.bin of=./config/disk_images/hd60M.img bs=512 count=1 seek=2 conv=notrunc
dd if=./kernel/kernel.bin of=./config/disk_images/hd60M.img bs=512 count=200 seek=9 conv=notrunc

echo "starting"
bochs -f ./config/second.disk;
