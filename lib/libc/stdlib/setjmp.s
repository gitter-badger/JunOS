;
;  stdlib/setjmp.s
;
;  This file is part of JunOS C Library.
;  
;  Copyright (C) 2016, Liu Xiaofeng <lxf.junos@aliyun.com>
;  Licensed under MIT, http://opensource.org/licenses/MIT.
;

section .text
global setjmp, longjmp

setjmp:
	mov ecx, [esp]
	mov eax, [esp+4]
	mov [eax],    ebx
	mov [eax+4],  ebp
	mov [eax+8],  esi
	mov [eax+12], edi
	mov [eax+16], esp
	mov [eax+20], ecx
	xor eax, eax
	ret

longjmp:
	mov eax, [esp+8]
	mov ecx, [esp+4]
	mov ebx, [ecx]
	mov ebp, [ecx+4]
	mov esi, [ecx+8]
	mov edi, [ecx+12]
	mov esp, [ecx+16]
	mov edx, [ecx+20]
	mov [esp], edx
	ret
