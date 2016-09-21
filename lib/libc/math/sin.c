/*
 *  math/sin.c
 *
 *  This file is part of JunOS C Library.
 *  
 *  Copyright (C) 2016, Liu Xiaofeng <lxf.junos@aliyun.com>
 *  Licensed under MIT, http://opensource.org/licenses/MIT.
 */

#include <math.h>

#if defined(_SIN)
double sin(double x)
{
	double r;
	__asm__("fsin" :"=t"(r) :"0"(x));
	return r;
}

#elif defined(_COS)
double cos(double x)
{
	double r;
	__asm__("fcos" :"=t"(r) :"0"(x));
	return r;
}

#elif defined(_TAN)
double tan(double x)
{
	double r1,r2;
	__asm__("fsin" :"=t"(r1) :"0"(x));
	__asm__("fcos" :"=t"(r2) :"0"(x));
	return r1/r2;
}

#elif defined(_ASIN)
double asin(double x)
{
	return atan2(x, sqrt(1 - x * x));
}

#elif defined(_ACOS)
double acos(double x)
{
	return atan2(sqrt(1 - x * x), x);
}

#elif defined(_ATAN)
double atan(double x)
{
	double r;
	__asm__("fpatan": "=&t"(r) :"f"(x),"f"(1.0));
	return r;
}

#elif defined(_ATAN2)
double atan2(double x, double y)
{
	double r;
	__asm__("fpatan": "=&t"(r) :"f"(x),"f"(y));
	return r;
}

#endif
