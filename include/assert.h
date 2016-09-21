/*
 *  assert.h
 * 
 *  This file is part of JunOS C Library.
 *
 *  Copyright (C) 2016, Liu Xiaofeng <lxf.junos@aliyun.com>
 *  Licensed under MIT, http://opensource.org/licenses/MIT.
 */

#undef assert

#ifdef NDEBUG
	#define assert(exp)	((void)0)
#else
	extern void __assert(char *str);

	#define _STR(x)		_VAL(x)
	#define _VAL(x) 	#x

	#define assert(exp)		\
		((exp) ? (void)0 : 	\
			__assert(__FILE__ ":" _STR(__LINE__) " " #exp))
#endif
