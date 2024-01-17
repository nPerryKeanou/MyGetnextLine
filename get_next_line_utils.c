#include "get_next_line.h"

size_t  ft_strlen(char *s){
    size_t i;

    i = 0;
    while(s[i] != '\0'){
        i++;
    }
    return(i);
}

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

void    ft_putstr(char *str)
{
    while(*str != '\0'){
        write(1, &str, 1);
        str++;
    }
}


