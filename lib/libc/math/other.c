/*
 *  math/other.c
 *
 *  This file is part of JunOS C Library.
 *  
 *  Copyright (C) 2016, Liu Xiaofeng <lxf.junos@aliyun.com>
 *  Licensed under MIT, http://opensource.org/licenses/MIT.
 */

#include <math.h>

#if defined(_FABS)
double fabs(double x)
{
	double r;
	__asm__("fabs" :"=t"(r) :"0"(x));
	return r;
}

#elif defined(_FLOOR)
double floor(double x)
{
	long r = x;
	return (double)r;
}

#elif defined(_CEIL)
double ceil(double x)
{
	long r = x;
	if( r < x )	r++;
	return (double)r;
}

#elif defined(_FMOD)
double fmod(double x, double y)
{
	double quot;

	if (x == 0.0 || y == 0.0)
		return (x);

  	quot = x/y;
  	return x - (quot < 0.0 ? ceil(quot) : floor(quot)) * y;
}

#elif defined(_MODF)
double modf(double x, double *ipart)
{
	long p = (long) x;
	*ipart = p;
	return x - p;
}

#elif defined(_LDEXP)
double ldexp(double x, int i)
{
	return x * pow(2, i);
}

#elif defined(_FREXP)
double frexp(double x, int *exptr)
{
	int i = 0;
	while (x > 1) {
		x = x / 2.0;
		i++;
	}
	*exptr = i;
	return x;
}

#elif defined(_ISINF)
int isinf(double d)
{
	union {
		unsigned long long l;
		double d;
	} u;

	u.d = d;

	return (u.l == 0x7FF0000000000000ll ? 1 :
		u.l == 0xFFF0000000000000ll ? -1 : 0);
}

#elif defined(_ISNAN)
int isnan(double d)
{
	union {
		unsigned long long l;
		double d;
	} u;
	u.d = d;
	
	return (u.l == 0x7FF8000000000000ll ||
        	u.l == 0x7FF0000000000000ll || 
		u.l == 0xFFF8000000000000ll);
}

#endif
