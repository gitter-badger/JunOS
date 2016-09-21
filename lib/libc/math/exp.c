/*
 *  math/exp.c
 *
 *  This file is part of JunOS C Library.
 *  
 *  Copyright (C) 2016, Liu Xiaofeng <lxf.junos@aliyun.com>
 *  Licensed under MIT, http://opensource.org/licenses/MIT.
 */

#include <math.h>

#if defined(_EXP)
double exp(double x)			//e^x=2^(x*log(base 2) e)
{
	double r;
	__asm__("fldl2e \n\t"		// st0=log(base 2) e
		"fmulp  \n\t"
		"f2xm1  \n\t"
		"fld1   \n\t"		// st0=st0*2^st1-1
		"faddp %%st(0),%%st(1)"
		:"=&t"(r) :"f"(x));
	return r;
}

#elif defined(_POW)
double pow(double x, double y)		// x^y=2^(y*log(base 2) x)
{
	double r;
	__asm__("fyl2x \n\t"		// st0=st1*log(base 2) st0
		"f2xm1  \n\t"		// st0=st0*2^st1-1
		"fld1   \n\t"		
		"faddp %%st(0),%%st(1)"
		:"=&t"(r) :"f"(y), "f"(x));
	return r;
}

#elif defined(_LOG)
double log(double x)	// log (base e) m=log (base e) 2 * log (base 2) m
{
	double r;
	__asm__("fldln2 \n\t"		// st1=log (base e) 2
		"fxch   \n\t"		// st0,st1=st1,st0
		"fyl2x  \n\t"		// st0=st1 *log (base 2) st0
		:"=&t"(r) :"f"(x));
	return r;
}

#elif defined(_LOG10)
double log10(double x)  // log (base 10) m=log (base 10) 2 * log (base 2) m
{
	double r;
	__asm__("fldlg2 \n\t"		// st1=log (base 10) 2
		"fxch   \n\t"		// st0,st1=st1,st0
		"fyl2x  \n\t"		// st0=st1 *log (base 2) st0
		:"=&t"(r) :"f"(x));
	return r;
}

#elif defined(_SQRT)
double sqrt(double x)
{
	double r;
	__asm__("fsqrt" :"=t"(r) :"0"(x));
	return r;
}

#elif defined(_HYPOT)
double hypot(double x, double y)
{
	return sqrt(x * x + y * y);
}

#endif
