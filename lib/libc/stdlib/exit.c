/*
 *  stdlib/exit.c
 *
 *  This file is part of JunOS C Library.
 *  
 *  Copyright (C) 2016, Liu Xiaofeng <lxf.junos@aliyun.com>
 *  Licensed under MIT, http://opensource.org/licenses/MIT.
 */

#include <stdlib.h>
#include <sys/unistd.h>

typedef void (*atexit_func_t)(void);

#if defined(_EXIT)

atexit_func_t atexit_func_tab[32];
int atexit_func_num;

void exit(int exit_code)
{
	//atexit_func_t fn;
	//for (int i = 0; i < atexit_func_num; i++) {
	//	printf("\nexit3:comehere");
	//	fn = atexit_func_tab[i];
	//	(fn)();
	//}
	_exit(exit_code);
}

#elif defined(_ATEXIT)

extern atexit_func_t atexit_func_tab[];
extern int atexit_func_num;

int atexit(void (*func)(void))
{
	if(atexit_func_num<32){
		atexit_func_tab[atexit_func_num++]=func;
		return 1;
	}
	return 0;
}
#endif
