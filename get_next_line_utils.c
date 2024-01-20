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

char    *ft_strchr(char    *s, int c){
    size_t i;
    size_t len_s;

    i = 0;
    len_s = ft_strlen(s);
    if(s == NULL){
        return(NULL);
    }
    if((unsigned char)c == '\0'){
        //retourne direct la fin du la str s.
        return((char*)s+len_s);
    }
    while(*(s) != '\0'){
        if(*(s) == (unsigned char)c){
            //on retourne donc l'endroit, l'espace mémoire, où se trouve la premiere occurence. Et non sa valeur.
            //C'est pour ca que l'on convertit avec (char*), pour récuperer non la valeur mais l'adresse.
            //En résumé, (char*)s est une conversion de type, tandis que *s est une opération de déréférencement qui donne accès à la valeur à laquelle s pointe.
            return((char*)s);
        }
        s++;
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

char    *ft_strjoin(char *s1, char *s2){
    printf("-------------------------------------- 1.2  4.5.1 ----------------------------\n");
    size_t i;
    size_t j;
    char *str;
    printf("-------------------------------------- 1.2  4.5.2 ----------------------------\n");
    if(!s1){
        s1 = (char*)malloc(1 * sizeof(char));
        if(!s1 || !s2){
            return(NULL);
        }
        s1[0] = '\0';
    }
    i = 0;
    j = 0;
    printf("-------------------------------------- 1.2  4.5.3 ----------------------------\n");
    str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1 * sizeof(char));
    printf("-------------------------------------- 1.2  4.5.4 ----------------------------\n");
    if(str == NULL){
        return(NULL);
    }
    if(s1){
        while(s1[i] != '\0'){
            str[i] = s1[i];
            i++;
        }
    }
    while(s2[j] != '\0'){
        str[i] = s2[j];
        i++;
        j++;
    }
    printf("-------------------------------------- 1.2  4.5.7 ----------------------------\n");
    str[ft_strlen(s1) + ft_strlen(s2)] = '\0';
    free(s1);
    printf("-------------------------------------- 1.2  4.5.8 ----------------------------\n");
    return(str);
}