/*
 *  math/sinh.c
 *
 *  This file is part of JunOS C Library.
 *  
 *  Copyright (C) 2016, Liu Xiaofeng <lxf.junos@aliyun.com>
 *  Licensed under MIT, http://opensource.org/licenses/MIT.
 */

#include <math.h>

#if defined(_SINH)
double sinh(double x)
{
	return (exp(x) - exp(-x)) / 2.0;
}

#elif defined(_COSH)
double cosh(double x)
{
	return (exp(x) + exp(-x)) / 2.0;
}

#elif defined(_TANH)
double tanh(double x)
{
	return (exp(x) - exp(-x)) / (exp(x) + exp(-x));
}

#elif defined(_ASINH)
double asinh(double x)
{
	return log(x + sqrt(x * x + 1));
}

#elif defined(_ACOSH)
double acosh(double x)
{
	return log(x + sqrt(x * x - 1));
}

#elif defined(_ATANH)
double atanh(double x)
{
	return log((1 + x) / (1 - x)) / 2.0;
}

#endif
