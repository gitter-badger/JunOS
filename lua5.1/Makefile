#
#  Makefile of Lua5.1 for Junos.
#  
#  Copyright (C) 2016, Liu Xiaofeng <lxf.junos@aliyun.com>
#  Licensed under MIT, http://opensource.org/licenses/MIT.
#

AS=nasm
CC=gcc
LD=ld -m elf_i386 -T ../script/ldscript  ../lib/crt.o

SFLAGS=-O2 -f elf32
CFLAGS=-O2 -c -x c -Wall -m32 -std=c99 -nostdinc -nostdlib -fno-builtin \
       -fno-stack-protector -I ../include 
LIB=../lib/libutil.a ../lib/libc.a  

.s.o:
	@echo         AS	$<
	@$(AS) $(SFLAGS) -o $@  $<
.c.o:
	@echo         CC	$<
	@$(CC) $(CFLAGS) -o $@  $<

DOWN_DIR= ../tmp/down
LUA_DIR	= $(DOWN_DIR)/lua-5.1
S=$(LUA_DIR)/src

OBJS=$(S)/lapi.o     $(S)/lcode.o    $(S)/ldebug.o   $(S)/ldo.o      \
     $(S)/ldump.o    $(S)/lfunc.o    $(S)/lgc.o      $(S)/llex.o     \
     $(S)/lmem.o     $(S)/lobject.o  $(S)/lopcodes.o $(S)/lparser.o  \
     $(S)/lstate.o   $(S)/lstring.o  $(S)/ltable.o   $(S)/ltm.o      \
     $(S)/lundump.o  $(S)/lvm.o      $(S)/lzio.o     $(S)/lauxlib.o  \
     $(S)/lbaselib.o $(S)/ldblib.o   $(S)/liolib.o   $(S)/lmathlib.o \
     $(S)/loslib.o   $(S)/ltablib.o  $(S)/lstrlib.o  $(S)/loadlib.o  \
     $(S)/linit.o

lua.elf: $(LUA_DIR) $(S)/lua.o liblua.a $(LIB)
	$(LD) -o $@ $(S)/lua.o liblua.a $(LIB)

liblua.a:$(OBJS)
	@echo  AR  OBJS
	@ar rcs liblua.a $(OBJS)

install: 
	cp lua.elf   $(PREFIX)/lua

clean:
	@rm -f lua.elf $(S)/lua.o liblua.a $(OBJS)

$(LUA_DIR):
	cd $(DOWN_DIR) &&                             \
	wget http://www.lua.org/ftp/lua-5.1.tar.gz && \
	tar xzf lua-5.1.tar.gz  
