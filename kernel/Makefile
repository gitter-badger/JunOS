#
#  Makefile for the Junos kernel.
#  
#  This file is part of JunOS Operating System.
#  
#  Copyright (C) 2016, Liu Xiaofeng <lxf.junos@aliyun.com>
#  Licensed under MIT, http://opensource.org/licenses/MIT.
#

AS=nasm
CC=gcc

SFLAGS=-g -f elf32
CFLAGS=-g -c -x c -Wall -m32 -std=c99 -nostdinc -nostdlib -fno-builtin \
       -fno-stack-protector  -I ../include

# kernel objects 
KERN_OBJS=kern/entry.o 			\
          kern/trap.o  			\
	  kern/sched.o 			\
          kern/signal.o  		\
          kern/timer.o 			\
          kern/softirq.o 		\
          kern/printk.o 		\
          kern/sys.o   			\
          kern/fork.o  			\
          kern/wait.o  			\
          kern/exit.o  			\
          kern/trace.o 			\

MM_OBJS=  mm/memory.o 			\

# fs objects 
FS_OBJS=  fs/buffer.o 			\
          fs/super.o 			\
          fs/inode.o  			\
          fs/read.o 			\
          fs/stat.o  			\
          fs/open.o  			\
          fs/write.o  			\
          fs/fcntl.o 			\
          fs/create.o 			\
          fs/pipe.o 			\
          fs/ioctl.o 			\
          fs/close.o 			\
          fs/exec.o    			\
          fs/minix/super.o 		\
          fs/minix/inode.o 		\
          fs/minix/bitmap.o 		\
          fs/minix/namei.o 		\
          fs/minix/file.o  		\

# net part 
NET_OBJS= net/skbuf.o 			\
          net/inet.o 			\
          net/arp.o 			\

DEV_OBJS= driver/ata/atapi.o 		\
	  driver/mem/mem.o 		\
	  driver/net/ne2k.o 		\
	  driver/pci/pci.o 		\
	  driver/rd/ramdisk.o 		\
          driver/tty/console.o  	\
          driver/tty/keyboard.o 	\
          driver/tty/serial.o 	 	\
          driver/tty/tty.o 		\
          driver/vga/vga.o 		\
          driver/dev.o      				

# total objects 
OBJS=     init/head.o init/main.o 	\
	  $(KERN_OBJS)			\
	  $(MM_OBJS)			\
	  $(FS_OBJS)			\
	  $(NET_OBJS)			\
	  $(DEV_OBJS)

.s.o:
	@echo         AS	$<
	@$(AS) $(SFLAGS) -o $@  $<
.c.o:
	@echo         CC	$<
	@$(CC) $(CFLAGS) -o $@  $<

kernel.bin: $(OBJS)
	@echo         LD      OBJS
	ld -m elf_i386 -e _start -Ttext 0xC0010000 --oformat binary \
	    -o kernel.bin $(OBJS)
	@ld -m elf_i386 -e _start -Ttext 0xC0010000  \
	    -o kernel.elf $(OBJS)

install:kernel.bin
	cp kernel.bin $(PREFIX)/kernel.bin
	
clean:
	@echo kernel cleaning...
	@-rm -f kernel.bin kernel.elf $(OBJS)
