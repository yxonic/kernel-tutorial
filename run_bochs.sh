#!/bin/bash

# run_bochs.sh
# mounts the correct loopback device, runs bochs, then unmounts.

if [ -z $BXBOOT ]; then
    export BXBOOT="cdrom"
fi

sudo /sbin/losetup /dev/loop0 floppy.img
sudo -E bochs -f bochsrc.txt -q
sudo /sbin/losetup -d /dev/loop0 
