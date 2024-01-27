#include "get_next_line.h"


int ft_strlen(char *str){
    int i;

    i = 0;
    while(str[i] != '\0'){
        i++;
    }
    return(i);
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
    len_s1 = ft_strlen_const(s1);
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




//donc cette fn va joindre l'ancienne statique et la nouvelle lecture de read.
//il faut faire attention au première appel de strjoin car s1_tmp vaudra null, donc on devra faire un ecart et faire un malloc de 1 et puis join
//si s2 vaut null, c'est qu'il y a eu un probleme dans le read et donc normalement le probleme a du être regler avant l'appel de ft_strjoin mais par acquis
//de conscience, on va return NULL
//
//strjoin ne va pas gerer les erreurs ou quoi que ce soit, on va lui laisser son boulot normale.
//je vais plutot créer une autre fonction qui va gerer le cas de s1_tmp null ou uatre?
char *ft_strjoin(char *s1_tmp, char *s2_buf){
    int i;
    int j;
    char *str;

    i = 0;
    j = 0;
    str = (char*)malloc((ft_strlen(s1_tmp) + ft_strlen(s2_buf) + 1) * sizeof(char*));
    if(str == NULL)
    {
        return(NULL);
    }
    //si s1_tmp est valide, sinon , on passe direct au deuxieme
    while(s1_tmp[i] != '\0')
    {
        str[i] = s1_tmp[i];
        i++;
    }
    //s1_tmp[i] == '\0' donc on et str[i] ici ne vaut rien, on doit lui passer l'autre s2
    while(s2_buf[j] != '\0')
    {
        str[i] = s2_buf[j];
        i++;
        j++;
    }
    str[i] = '\0';
    //donc ici on join les deux chaines de caraceteres dans le char* str.
    //on peut maintenant, le retourner.
    return(str);
    //il ne faudra pas oublier de le free dans la fn gnl qui va donner ce return à la static.
    //mais si s1 ou s2 n'exsite pas ou valennt null ?
}


//cette fonction va créer un espace mémoire de la taille de BUFFER_SIZE car on va copier le buf de read.
//Cette fn va aider a la boucle de read et join pour la static
//Je peux juste utiliser une strdup et strcpy pour le debut de a fn read and join.