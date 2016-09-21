/*
 *  junos/string.h    -- kernel string inline function.
 *
 *  This file is part of JunOS Operating System.
 *
 *  Copyright (C) 2016, Liu Xiaofeng <lxf.junos@aliyun.com>
 *  Licensed under MIT, http://opensource.org/licenses/MIT.
 */

#ifndef _JUNOS_STRING_H
#define _JUNOS_STRING_H

static inline void memset(void *s, int c, size_t size)
{
	__asm__("rep stosb" ::"D"(s), "a"(c), "c"(size));
}

static inline void memcpy(void *dst, void *src, size_t size)
{
	__asm__("rep movsb":: "D"(dst), "S"(src), "c"(size));
}

static inline size_t strlen(char *s)
{
	char *p = (char*) s;
	while (*p)
		p++;
	return (size_t) (p - s);
}

static inline int strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2) {
		s1++;
		s2++;
	}

	return (int)(*s1 - *s2);
}

static inline int strncmp(char *s1, char *s2, size_t n)
{
	while (n--) {
		if (*s1 && (*s1 == *s2)) {
			s1++;
			s2++;
		} else {
			return (*s1 - *s2);
		}
	}
	return 0;
}

static inline char * strncpy(char *dst, char *src, size_t n)
{
	char *t = dst;
	while (n-- && (*t++ = *src++))
		;
	return dst;
}

#endif	/* _JUNOS_STRING_H */
