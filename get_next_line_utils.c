#include "get_next_line.h"

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

size_t  ft_strlen(char *s){
    size_t i;

    i = 0;
    while(s[i] != '\0'){
        i++;
    }
    return(i);
}

size_t  ft_strlen_const(const char *s){
    size_t i;

    i = 0;
    while(s[i] != '\0'){
        i++;
    }
    return(i);
}

/**
 * strnstr :

Description : La fonction strnstr() localise la première occurrence de la chaîne de caractères null-terminée needle dans la chaîne de caractères haystack, 
où au plus len caractères sont recherchés. 
Les caractères qui apparaissent après un caractère \0 ne sont pas recherchés.
Valeur de retour : Si needle est une chaîne vide, la fonction retourne haystack. 
Si needle n'est trouvé nulle part dans les premiers len caractères de haystack, la fonction retourne NULL. 
Sinon, un pointeur sur le premier caractère de la première occurrence de needle dans les premiers len caractères est renvoyé.
 * 
*/

char    *ft_strnstr(const char *haystack, const char *needle, size_t len){
    size_t i;
    size_t tmp;
    size_t len_hays;
    size_t len_need;

    i = 0;
    len_hays = ft_strlen_const(haystack);
    len_need = ft_strlen_const(needle);
    if(len_need == 0){
        return((char *)haystack);
    }
    while(i < len && i + len_need <= len){
        if(haystack[i] == needle[0]){
            tmp = 0;
            while(tmp < len_need && haystack[i + tmp] == needle[tmp]){
                tmp++;
            }
            if(tmp == len_need){
                return((char *)haystack + i);
            }
        }
        i++;
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

char    *ft_strjoin(const char *s1, const char *s2){
    size_t len_s1;
    size_t len_s2;
    size_t i;
    size_t j;
    char *str;

    len_s1 = ft_strlen_const(s1);
    len_s2 = ft_strlen_const(s2);
    i = 0;
    j = 0;
    str = (char *)malloc(len_s1 + len_s2 + 1 * sizeof(char));
    if(s1 == NULL || s2 == NULL || str == NULL){
        return(NULL);
    }
    while(s1[i] != '\0'){
        str[i] = s1[i];
        i++;
    }
    while(s2[j] != '\0'){
        str[i] = s2[j];
        i++;
        j++;
    }
    str[i] = '\0';
    return(str);
}