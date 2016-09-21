/*
 *  stdlib/div.c
 *
 *  This file is part of JunOS C Library.
 *  
 *  Copyright (C) 2016, Liu Xiaofeng <lxf.junos@aliyun.com>
 *  Licensed under MIT, http://opensource.org/licenses/MIT.
 */
 
#include <stdlib.h>

#if defined(_DIV)
div_t div(int numer, int denom)
{
	div_t r;
	
	r.quot = numer / denom; 
	r.rem = numer % denom;

	return r;
}

#elif defined(_LDIV)
ldiv_t ldiv(long numer, long denom)
{
	ldiv_t r;
	
	r.quot = numer / denom; 
	r.rem = numer % denom;

	return r;
}

#elif defined(_LLDIV)
lldiv_t lldiv(long long numer, long long denom)
{
	lldiv_t r;
	
	r.quot = numer / denom; 
	r.rem = numer % denom;

	return r;
}
#endif
