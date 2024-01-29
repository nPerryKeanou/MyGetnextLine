#include "get_next_line.h"

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

void    ft_putstr(char *str)
{
    int i;

    i = 0;
    while(i < ft_strlen(str))
    {
        ft_putchar(str[i]);
        i++;
    }
}


int ft_strlen(char *str){
    int i;

    i = 0;
    while(str[i] != '\0'){
        i++;
    }
    return(i);
}

char *ft_strcpy(char *dest, char *src){
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}


char    *ft_strrchr(char *s, int c){
    int i;
    int len_s;

    i = ft_strlen(s);
    len_s = ft_strlen(s);
    if(s == NULL){
        return(NULL);
    }
    if((unsigned char)c == '\0'){
        return((char*)s+i);
    }
    while(i > 0){
        if(s[i] == (unsigned char)c){
            return((char*)s+i);
        }
        i--;
    }
    return(NULL);
}


char    *ft_strdup(char  *s1){
    size_t i;
    size_t len_s1;
    char    *new_s1;

    i = 0;
    len_s1 = ft_strlen(s1);
    new_s1 = (char *)malloc(len_s1 + 1 * sizeof(char));
    if(new_s1 == NULL){
        return (NULL);
    }
    while(i < len_s1){
        new_s1[i] = s1[i];
        i++;
    }
    new_s1[i] = '\0';
    return(new_s1);
}

char *ft_strjoin(char *s1_tmp, char *s2_buf){
    int i;
    int j;
    int k;
    char *str;

    i = 0;
    j = 0;
    k = 0;
    str = (char*)malloc((ft_strlen(s1_tmp) + ft_strlen(s2_buf) + 1) * sizeof(char));
    if(str == NULL)
    {
        return(NULL);
    }
    while(s1_tmp[i] != '\0')
    {
        if(i == 0 && s1_tmp[i] == '\n')
        {
            i++;
        }
        str[k] = s1_tmp[i];
        k++;
        i++;
    }
    while(s2_buf[j] != '\0')
    {
        str[k] = s2_buf[j];
        k++;
        j++;
    }
    str[k] = '\0';
    return(str);
}