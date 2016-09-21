LIBC_OBJ+=stdlib/abort.o   \
          stdlib/abs.o     \
	  stdlib/atexit.o  \
	  stdlib/atoi.o    \
	  stdlib/bsearch.o \
	  stdlib/exit.o    \
	  stdlib/getenv.o  \
	  stdlib/malloc.o  \
	  stdlib/rand.o    \
	  stdlib/realloc.o \
	  stdlib/calloc.o  \
	  stdlib/raise.o   \
	  stdlib/setjmp.o  \
	  stdlib/putenv.o  \
	  stdlib/div.o     \
	  stdlib/qsort.o   \
	  stdlib/setenv.o   

stdlib/abs.o:stdlib/abs.c
	$(CC) $(CFLAGS) -D_ABS -o $@   $<

stdlib/labs.o:stdlib/abs.c
	$(CC) $(CFLAGS) -D_LABS -o $@   $<

stdlib/llabs.o:stdlib/abs.c
	$(CC) $(CFLAGS) -D_LLABS -o $@   $<

stdlib/div.o:stdlib/div.c
	$(CC) $(CFLAGS) -D_DIV -o $@   $<

stdlib/ldiv.o:stdlib/div.c
	$(CC) $(CFLAGS) -D_LDIV -o $@   $<

stdlib/lldiv.o:stdlib/div.c
	$(CC) $(CFLAGS) -D_LLDIV -o $@   $<

stdlib/exit.o:stdlib/exit.c
	$(CC) $(CFLAGS) -D_EXIT -o $@   $<

stdlib/atexit.o:stdlib/exit.c
	$(CC) $(CFLAGS) -D_ATEXIT -o $@   $<
