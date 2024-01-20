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
char    *ft_strchr(char    *s, int c);
char    *ft_strjoin(char *s1, char *s2);
char    *ft_new_line(char *final_line);
char    *ft_new_final_line(char *final_line);


size_t  ft_strlen(char *s);
size_t  ft_strlen_const(const char *s);


#endif