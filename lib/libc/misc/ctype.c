/*
 *  misc/ctype.c
 *
 *  This file is part of JunOS C Library.
 *  
 *  Copyright (C) 2016, Liu Xiaofeng <lxf.junos@aliyun.com>
 *  Licensed under MIT, http://opensource.org/licenses/MIT.
 */

#include <ctype.h>

#if defined(__CTYPE)
unsigned char __ctype[]={ 0,
	_C,_C,_C,_C,_C,_C,_C,_C,
	_C,_C|_S,_C|_S,_C|_S,_C|_S,_C|_S,_C,_C,
	_C,_C,_C,_C,_C,_C,_C,_C,
	_C,_C,_C,_C,_C,_C,_C,_C,
	_S,_P,_P,_P,_P,_P,_P,_P,
	_P,_P,_P,_P,_P,_P,_P,_P,
	_D,_D,_D,_D,_D,_D,_D,_D,
	_D,_D,_P,_P,_P,_P,_P,_P,
	_P,_U|_X,_U|_X,_U|_X,_U|_X,_U|_X,_U|_X,_U,
	_U,_U,_U,_U,_U,_U,_U,_U,
	_U,_U,_U,_U,_U,_U,_U,_U,
	_U,_U,_U,_P,_P,_P,_P,_P,
	_P,_L|_X,_L|_X,_L|_X,_L|_X,_L|_X,_L|_X,_L,
	_L,_L,_L,_L,_L,_L,_L,_L,
	_L,_L,_L,_L,_L,_L,_L,_L,
	_L,_L,_L,_P,_P,_P,_P,_C,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
};

#elif defined(_ISUPPER)
int (isupper)(int c)
{
	return isupper(c);
}

#elif defined(_ISLOWER)
int (islower)(int c)
{
	return islower(c);
}

#elif defined(_ISDIGIT)
int (isdigit)(int c)
{
	return isdigit(c);
}

#elif defined(_ISCNTRL)
int (iscntrl)(int c)
{
	return iscntrl(c);
}

#elif defined(_ISSPACE)
int (isspace)(int c)
{
	return isspace(c);
}

#elif defined(_ISPUNCT)
int (ispunct)(int c)
{
	return ispunct(c);
}

#elif defined(_ISXDIGIT)
int (isxdigit)(int c)
{
	return isxdigit(c);
}

#elif defined(_ISALPHA)
int (isalpha)(int c)
{
	return isalpha(c);
}

#elif defined(_ISALNUM)
int (isalnum)(int c)
{
	return isalnum(c);
}

#elif defined(_ISGRAPH)
int (isgraph)(int c)
{
	return isgraph(c);
}

#elif defined(_ISPRINT)
int (isprint)(int c)
{
	return isprint(c);
}

#elif defined(_TOUPPER)
int (toupper)(int c)
{
	return islower(c) ? c-0x20 : c;
}

#elif defined(_TOLOWER)
int (tolower)(int c)
{
	return isupper(c) ? c+0x20 : c;
}

#endif
