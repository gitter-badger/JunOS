LIBC_OBJ+=string/memchr.o  	\
	  string/memrchr.o 	\
	  string/memcpy.o  	\
	  string/memccpy.o  	\
	  string/memcmp.o  	\
          string/memset.o  	\
	  string/memmove.o 	\
          string/strlen.o  	\
          string/strnlen.o  	\
	  string/strcat.o  	\
	  string/strncat.o  	\
	  string/strcpy.o  	\
	  string/strncpy.o  	\
	  string/strcmp.o  	\
	  string/strncmp.o  	\
	  string/stricmp.o 	\
	  string/strnicmp.o 	\
	  string/strchr.o   	\
	  string/strrchr.o  	\
	  string/strstr.o   	\
	  string/strerror.o 	\
	  string/strpbrk.o  	\
	  string/strcspn.o  	\
	  string/strspn.o   	\
	  string/strcoll.o  	\

string/memchr.o:string/memchr.c
	$(CC) $(CFLAGS) -D_MEMCHR -o $@   $<

string/memrchr.o:string/memchr.c
	$(CC) $(CFLAGS) -D_MEMRCHR -o $@   $<

string/memcpy.o:string/memcpy.c
	$(CC) $(CFLAGS) -D_MEMCPY -o $@   $<

string/memccpy.o:string/memcpy.c
	$(CC) $(CFLAGS) -D_MEMCCPY -o $@   $<

string/strcat.o:string/strcat.c
	$(CC) $(CFLAGS) -D_STRCAT -o $@   $<

string/strncat.o:string/strcat.c
	$(CC) $(CFLAGS) -D_STRNCAT -o $@  $<

string/strlen.o:string/strlen.c
	$(CC) $(CFLAGS) -D_STRLEN -o $@   $<

string/strnlen.o:string/strlen.c
	$(CC) $(CFLAGS) -D_STRNLEN -o $@  $<

string/strcpy.o:string/strcpy.c
	$(CC) $(CFLAGS) -D_STRCPY -o $@  $<

string/strncpy.o:string/strcpy.c
	$(CC) $(CFLAGS) -D_STRNCPY -o $@  $<

string/strcmp.o:string/strcmp.c
	$(CC) $(CFLAGS) -D_STRCMP -o $@  $<

string/strncmp.o:string/strcmp.c
	$(CC) $(CFLAGS) -D_STRNCMP -o $@  $<

string/stricmp.o:string/strcmp.c
	$(CC) $(CFLAGS) -D_STRICMP -o $@  $<

string/strnicmp.o:string/strcmp.c
	$(CC) $(CFLAGS) -D_STRNICMP -o $@  $<

string/strchr.o:string/strchr.c
	$(CC) $(CFLAGS) -D_STRCHR -o $@  $<

string/strrchr.o:string/strchr.c
	$(CC) $(CFLAGS) -D_STRRCHR -o $@  $<
