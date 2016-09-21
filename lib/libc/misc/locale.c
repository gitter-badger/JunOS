/*
 *  misc/locale.c
 *
 *  This file is part of JunOS C Library.
 *  
 *  Copyright (C) 2016, Liu Xiaofeng <lxf.junos@aliyun.com>
 *  Licensed under MIT, http://opensource.org/licenses/MIT.
 */

#include <locale.h>
#include <limits.h> 
#include <stddef.h>
#include <string.h>

static struct lconv __lc={
	.decimal_point     = ".",
	.thousands_sep     = "" ,
	.grouping          = "" ,
	.int_curr_symbol   = "",
	.currency_symbol   = "",
	.mon_decimal_point = "",
	.mon_thousands_sep = "",
	.mon_grouping      = "",
	.positive_sign     = "",
	.negative_sign     = "",
	.int_frac_digits   = CHAR_MAX,
	.frac_digits       = CHAR_MAX,
	.p_cs_precedes     = CHAR_MAX,
	.p_sep_by_space    = CHAR_MAX,
	.n_cs_precedes     = CHAR_MAX,
	.n_sep_by_space    = CHAR_MAX,
	.p_sign_posn       = CHAR_MAX,
	.n_sign_posn       = CHAR_MAX,
};

struct lconv * localeconv(void)
{
	return &__lc;
}

char *setlocale(int category, const char *locale)
{
	if (!locale)
		return "C";
	if (*locale && strcmp(locale, "C"))
		return (char *) NULL;

	switch (category) {
	case LC_ALL:
	case LC_CTYPE:
	case LC_COLLATE:
	case LC_TIME:
	case LC_NUMERIC:
	case LC_MONETARY:
	case LC_MESSAGES:
		return *locale ? (char *) locale : "C";
	default:
		return (char *) NULL;
	}
}
