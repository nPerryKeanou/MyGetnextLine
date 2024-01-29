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


char    *get_next_line(int fd);
char    *ft_get_static(int fd, char *tmp_line_static, size_t *nb_read_param);
char    *ft_get_line_return(char *line_static_param);
char    *ft_new_static(char *line_static_param, char *line_return_param);
char    *ft_strrchr(char *s, int c);
char    *ft_strdup(char  *s1);
char *ft_strjoin(char *s1_tmp, char *s2_buf);
char *ft_strcpy(char *dest, char *src);

void    ft_putchar(char c);
void    ft_putstr(char *str);

int ft_strlen(char *str);


#endif