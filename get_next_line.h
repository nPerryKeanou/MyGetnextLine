#ifndef GET_NEXT_LINE
#define GET_NEXT_LINE

#include "unistd.h"
#include "stdio.h"
#include "stdlib.h"
#include "stddef.h"
#include "limits.h"
#include "tcl.h"
#include "fcntl.h"
#include <sys/types.h>

#define BUFFER_SIZE 1024

char    *get_next_line(int fd);
char    *ft_strnstr(const char *haystack, const char *needle, size_t len);
char    *ft_strdup(char  *s1);
char    *ft_strjoin(const char *s1, const char *s2);


size_t  ft_strlen(char *s);
size_t  ft_strlen_const(const char *s);


#endif