file kernel/kernel.elf
target remote 192.168.56.101:1234
b start
c
layout split
set disassembly-flavor intel
set print pretty on