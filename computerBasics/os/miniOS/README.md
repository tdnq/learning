# how to run this boot?
1. go to the directory boot
2. run command "nasm -I include/ -o mbr.bin mbr.S&&dd if=./mbr.bin of=../config/disk_images/hd60M.img bs=512 count=1 conv=notrunc"
3. run command "nasm -I include/ -o loader.bin loader.S&&dd if=./loader.bin of=../config/disk_images/hd60M.img bs=512 count=1 seek=2 conv=notrunc"
4. run "bochs -f ../config/second.disk"

## 写入内核
1. `gcc -c -o main.out main.c`
2. `ld main.out -Ttext Oxe0001500 -e main -o kernel.bin`