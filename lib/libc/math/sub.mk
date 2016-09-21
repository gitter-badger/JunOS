LIBC_OBJ+=math/sin.o 	\
          math/cos.o  	\
          math/tan.o  	\
          math/asin.o  	\
          math/acos.o  	\
          math/atan.o  	\
          math/atan2.o 	\
          math/sinh.o  	\
          math/cosh.o  	\
          math/tanh.o  	\
          math/asinh.o  \
          math/acosh.o 	\
          math/atanh.o  \
          math/exp.o   	\
          math/pow.o   	\
          math/log.o   	\
          math/log10.o  \
          math/sqrt.o  	\
          math/hypot.o  \
          math/fabs.o  	\
          math/floor.o 	\
          math/ceil.o  	\
          math/fmod.o   \
          math/modf.o  	\
          math/ldexp.o 	\
          math/frexp.o 	\
          math/isinf.o 	\
          math/isnan.o     \
          math/__divdi3.o  \
          math/__udivdi3.o \
          math/__moddi3.o  \
          math/__umoddi3.o

math/sin.o:math/sin.c
	@$(CC) $(CFLAGS) -D_SIN -o $@  $<

math/cos.o:math/sin.c
	@$(CC) $(CFLAGS) -D_COS -o $@  $<

math/tan.o:math/sin.c
	@$(CC) $(CFLAGS) -D_TAN -o $@  $<

math/asin.o:math/sin.c
	@$(CC) $(CFLAGS) -D_ASIN -o $@  $<

math/acos.o:math/sin.c
	@$(CC) $(CFLAGS) -D_ACOS -o $@  $<

math/atan.o:math/sin.c
	@$(CC) $(CFLAGS) -D_ATAN -o $@  $<

math/atan2.o:math/sin.c
	@$(CC) $(CFLAGS) -D_ATAN2 -o $@  $<

math/sinh.o:math/sinh.c
	@$(CC) $(CFLAGS) -D_SINH -o $@  $<

math/cosh.o:math/sinh.c
	@$(CC) $(CFLAGS) -D_COSH -o $@  $<

math/tanh.o:math/sinh.c
	@$(CC) $(CFLAGS) -D_TANH -o $@  $<

math/asinh.o:math/sinh.c
	@$(CC) $(CFLAGS) -D_ASINH -o $@  $<

math/acosh.o:math/sinh.c
	@$(CC) $(CFLAGS) -D_ACOSH -o $@  $<

math/atanh.o:math/sinh.c
	@$(CC) $(CFLAGS) -D_ATANH -o $@  $<

math/exp.o:math/exp.c
	@$(CC) $(CFLAGS) -D_EXP -o $@  $<

math/pow.o:math/exp.c
	@$(CC) $(CFLAGS) -D_POW -o $@  $<

math/log.o:math/exp.c
	@$(CC) $(CFLAGS) -D_LOG -o $@  $<

math/log10.o:math/exp.c
	@$(CC) $(CFLAGS) -D_LOG10 -o $@  $<

math/sqrt.o:math/exp.c
	@$(CC) $(CFLAGS) -D_SQRT -o $@  $<

math/hypot.o:math/exp.c
	@$(CC) $(CFLAGS) -D_HYPOT -o $@  $<

math/fabs.o:math/other.c
	@$(CC) $(CFLAGS) -D_FABS -o $@  $<

math/floor.o:math/other.c
	@$(CC) $(CFLAGS) -D_FLOOR -o $@  $<

math/ceil.o:math/other.c
	@$(CC) $(CFLAGS) -D_CEIL -o $@  $<

math/fmod.o:math/other.c
	@$(CC) $(CFLAGS) -D_FMOD -o $@  $<

math/modf.o:math/other.c
	@$(CC) $(CFLAGS) -D_MODF -o $@  $<

math/ldexp.o:math/other.c
	@$(CC) $(CFLAGS) -D_LDEXP -o $@  $<

math/frexp.o:math/other.c
	@$(CC) $(CFLAGS) -D_FREXP -o $@  $<

math/isinf.o:math/other.c
	@$(CC) $(CFLAGS) -D_ISINF -o $@  $<

math/isnan.o:math/other.c
	@$(CC) $(CFLAGS) -D_ISNAN -o $@  $<
     