;
;  csu/crt.s
;  
;  This file is part of JunOS C Library.
;  
;  Copyright (C) 2016, Liu Xiaofeng <lxf.junos@aliyun.com>
;  Licensed under MIT, http://opensource.org/licenses/MIT.
;

extern main, exit, _edata, _end
global _start, environ, errno

section .text
_start:
	mov  ax,ss
	mov  ds,ax
	mov  es,ax
	mov  eax,[esp+8]
	mov  dword [environ],eax
	mov  edi, _edata
	mov  ecx, _end
	sub  ecx, edi
	xor  eax,eax
	rep  stosb
	call main
	push eax
	call exit
	mov  eax,4
	int  0x30

section .data
environ:
	dd 0
errno:
	dd 0
