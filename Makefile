#
#  Top Makefile for the Junos Operating System Project.
#
#  Copyright (C) 2016, Liu Xiaofeng <lxf.junos@aliyun.com>
#  Licensed under MIT, http://opensource.org/licenses/MIT.
#

QEMU=qemu-system-i386 -boot d                                     \
	 -net nic,model=ne2k_pci,vlan=1,macaddr=12:54:00:12:34:56 \
	 -net tap,vlan=1,ifname=tap1                              \
	 -serial tcp::4444,server,nowait                          \
	 -serial tcp::4445,server,nowait                          \
	 -cdrom  tmp/cdrom.iso                                    \
	 -hda    tmp/hd.img

build: complie
	@sh script/mkrdimg
	@sh script/mkcdrom
	@sh script/mkhdimg

rebuild: clean build

complie:
	@mkdir -p tmp/iso
	@mkdir -p tmp/down
	make -C kernel
	make -C lib/csu
	make -C lib/libc
	make -C lib/libutil
	make -C utility
#	make -C lua5.1
#	make -C tcc0.9
#	make -C nasm2.12

clean:
	make clean -C kernel
	make clean -C lib/csu
	make clean -C lib/libc
	make clean -C lib/libutil
	make clean -C utility
#	make clean -C lua5.1
#	make clean -C tcc0.9
#	make clean -C nasm2.12

distclean: clean
	@rm -rf tmp

run:
	$(QEMU)

dbg:
	$(QEMU) -S -gdb tcp::1234

install:
	make install PREFIX=$(PREFIX)/System/Utility -C utility
#	make install PREFIX=$(PREFIX)/Utility -C lua5.1
#	make install PREFIX=$(PREFIX)/Utility -C tcc0.9
