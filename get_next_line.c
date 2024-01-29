
#include "get_next_line.h"

char    *ft_new_static(char *line_static_param, char *line_return_param)
{
    char    *str_new_static;
    int i;
    int len_total;
    int j;

    str_new_static = NULL;
    i = 0;
    len_total = ft_strlen(line_static_param) - ft_strlen(line_return_param);
    str_new_static = (char*)malloc((len_total + 1) * sizeof(char));
    if(str_new_static == NULL)
        return(NULL);
    j = ft_strlen(line_return_param);
    while(i < len_total)
    {
        str_new_static[i] = line_static_param[j];
        i++;
        j++;
    }
    str_new_static[i] = '\0';
    return(str_new_static);
}

char    *ft_get_line_return(char *line_static_param)
{
    char    *line_to_return;
    int i;
    int j;

    line_to_return = NULL;
    i = 0;
    j = 0;
    if(line_static_param[i] == '\n')
    {
        while(line_static_param[i] == '\n')
        {
            i++;
        }
    }
    while(line_static_param[i] != '\n' && line_static_param[i] != '\0')
        i++;
    line_to_return = (char*)malloc((i + 1) * sizeof(char));
    if(line_to_return == NULL)
        return(NULL);
    while(j < i)
    {
        line_to_return[j] = line_static_param[j];
        j++;
    }
    line_to_return[j] = '\0';
    return(line_to_return);
}

char    *ft_get_static(int fd, char *tmp_line_static, size_t *nb_read_param)
{    
    char    *str;
    char    *buf;
    
    str = NULL;
    buf = (char*)malloc((BUFFER_SIZE) * sizeof(char));
    if(buf == NULL)
    {
        return(NULL);
    }
    if(*nb_read_param > 0 && (tmp_line_static == NULL || !tmp_line_static))
    {
        *nb_read_param = read(fd, buf, BUFFER_SIZE - 1);
        if(*nb_read_param <= 0)
        {
            free(buf);
            return(NULL);
        }
        buf[*nb_read_param] = '\0';
        str = ft_strdup(buf);
        if(str == NULL)
        {
            free(buf);
            return(NULL);
        }
        str[ft_strlen(str)] = '\0';
        tmp_line_static = (char*)malloc((ft_strlen(str) + 1) * sizeof(char));
        if(tmp_line_static == NULL)
        {
            free(str);
            free(buf);
            return(NULL);
        }
        tmp_line_static = ft_strcpy(tmp_line_static, str);
        free(str);
    }
    while(ft_strrchr(tmp_line_static, '\n') == NULL && *nb_read_param > 0)
    {
        *nb_read_param = read(fd, buf, BUFFER_SIZE);
        if(*nb_read_param <= 0)
        {
            free(buf);
            return(NULL);
        }   
        buf[*nb_read_param] = '\0';
        tmp_line_static = ft_strjoin(tmp_line_static, buf);
        if(tmp_line_static == NULL)
        {
            free(buf);
            return(NULL);
        }
    }
    free(buf);
    return(tmp_line_static);
}


char    *get_next_line(int fd)
{
    static char *line_static;
    char        *line_return;
    size_t         nb_read;

    if(fd < 0 && BUFFER_SIZE <= 0)
    {
        if(line_static)
            free(line_static);
        return(NULL);
    }
    nb_read = 1;
    line_static = ft_get_static(fd, line_static, &nb_read);
    if(line_static == NULL)
    {
        if(line_static)
        {
            free(line_static);
        }
        return(NULL);
    }
    line_return = ft_get_line_return(line_static);
    if(line_return == NULL)
    {
        if(line_static)
            free(line_static);
        return(NULL);
    }
    if(nb_read == 0)
    {
        if(line_static)
            free(line_static);
        if(line_return)
            free(line_return);
        return(line_return);
    }
    line_static = ft_new_static(line_static, line_return);
    if(line_static == NULL)
    {
        if(line_static)
            free(line_static);
        if(line_return)
            free(line_return);
        return(NULL);
    }
    return(line_return);
}