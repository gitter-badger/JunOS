/*
 *  stdlib.h
 * 
 *  This file is part of JunOS C Library.
 *
 *  Copyright (C) 2016, Liu Xiaofeng <lxf.junos@aliyun.com>
 *  Licensed under MIT, http://opensource.org/licenses/MIT.
 */

#ifndef _STDLIB_H
#define _STDLIB_H

#include <stddef.h>

typedef struct {
	int quot;
	int rem;
} div_t;

typedef struct {
	long quot;
	long rem;
} ldiv_t;

typedef struct {
	long long quot;
	long long rem;
} lldiv_t;

extern char **environ;

extern int    abs(int i);
extern void * malloc(long nbytes);
extern void * realloc(void *ptr, size_t size);
extern void * calloc(size_t nelem, size_t elsize);
extern void   free(void *p);
extern char * getenv(const char *name);
extern int    setenv(const char *name, const char* value, int rewrite);
extern int    unsetenv(const char *name);
extern void   exit(int exit_code);
extern int    rand(void);
extern void   srand(unsigned int seed);

extern long strtol(const char *str, char **endptr, int base);
extern long long strtoll(const char *str, char **endptr, int base);
extern unsigned long strtoul(const char *str, char **endptr, int base);
extern unsigned long long strtoull(const char *str, char **endptr, int base);

extern float strtof(const char *ptr, char **endptr);
extern double strtod(const char *ptr, char **endptr);
extern long double strtold(const char *ptr, char **endptr);

extern void abort(void);
extern int atoi(const char *s);
extern long atol(const char *s);

extern div_t div(int numer, int denom);
extern ldiv_t ldiv(long numer, long denom);

#define EXIT_SUCCESS	0
#define EXIT_FAILURE	1

#include <stdio.h>
static inline int system(char *s)
{
	fprintf(stderr,"function system unimplite");
	return -1;
}

#endif
