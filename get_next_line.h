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

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1024
#endif


int ft_strlen(char *str);


char    *ft_strrchr(char *s, int c);
char    *ft_strdup(char  *s1);
char *ft_strjoin(char *s1_tmp, char *s2_buf);
char    *ft_get_static(int fd);
char *get_next_line(int fd);


#endif