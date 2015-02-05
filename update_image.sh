#!/bin/bash

# update floppy image
sudo losetup /dev/loop0 floppy.img
sudo mount /dev/loop0 /mnt/os
sudo cp src/kernel.elf /mnt/os/kernel
sudo umount /dev/loop0
sudo losetup -d /dev/loop0 

# update iso
cp src/kernel.elf iso/boot/kernel
mkisofs -R \
        -b boot/grub/stage2_eltorito \
        -no-emul-boot \
        -boot-load-size 4 \
        -A os \
        -input-charset utf8 \
        -boot-info-table \
        -o image.iso \
        -quiet \
        iso
