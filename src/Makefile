# Makefile for JamesM's kernel tutorials.
# The C and C++ rules are already setup by default.
# The only one that needs changing is the assembler
# rule, as we use nasm instead of GNU as.

SOURCES=boot.o main.o common.o monitor.o

CFLAGS=-m32 -nostdlib -nostdinc -fno-builtin -fno-stack-protector -Wall
LDFLAGS=-Tlink.ld -melf_i386
ASFLAGS=-felf

all: $(SOURCES) link

clean:
	-rm -f *.o kernel.elf

link:
	ld $(LDFLAGS) -o kernel.elf $(SOURCES)

.s.o:
	nasm $(ASFLAGS) $<
