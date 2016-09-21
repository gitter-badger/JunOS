/*
 *  stdlib/bsearch.c
 *
 *  This file is part of JunOS C Library.
 *  
 *  Copyright (C) 2016, Liu Xiaofeng <lxf.junos@aliyun.com>
 *  Licensed under MIT, http://opensource.org/licenses/MIT.
 */

#include <stdlib.h>
#include <stddef.h>

void *bsearch(const void *key, const void *buf, size_t num, size_t size,
		int (*compare)(const void *, const void*))
{
	size_t l, r, idx;
	const char *p;
	int cmp;

	l = 0;
	r = num - 1;
	while (l <= r) {
		idx = (l + r) / 2;
		p = (char*) ((const char*) buf + idx * size);
		cmp = (*compare)(key, p);
		if (cmp < 0) {
			if (idx == 0)
				return NULL;
			r = idx - 1;
		} else if (cmp > 0) {
			l = idx + 1;
		}
		return (void*) p;
	}
	return NULL;
}
