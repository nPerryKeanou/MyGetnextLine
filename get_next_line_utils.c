#include "get_next_line.h"


size_t ft_strlen(char *str){
    size_t i;

    i = 0;
    while(str[i] != '\0'){
        i++;
    }
    return(i);
}

char    *ft_strrchr(char *s, int c){
    size_t i;
    size_t len_s;

    i = ft_strlent(s);
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



//donc cette fn va joindre l'ancienne statique et la nouvelle lecture de read.
//il faut faire attention au première appel de strjoin car s1_tmp vaudra null, donc on devra faire un ecart et faire un malloc de 1 et puis join
//si s2 vaut null, c'est qu'il y a eu un probleme dans le read et donc normalement le probleme a du être regler avant l'appel de ft_strjoin mais par acquis
//de conscience, on va return NULL
char *ft_strjoin(char *s1_tmp, char *s2_buf){
    int i;
    int j;
    char *line_to_return;

    i = 0;
    j = 0;
    line_to_return = NULL;
    if(s2_buf == NULL){
        return(NULL);
    }
    if(s1_tmp == NULL){//donc c'est le premier appel et on dois donner un espace mémoire pour utiliser ft_strjoin
        line_to_return = (char*)malloc(1 * sizeof(char*));
        if(line_to_return == NULL)
        {
            return(NULL);
        }
    }
    line_to_return = (char*)malloc((ft_strlen(s1_tmp) + ft_strlen(s2_buf) + 1) * sizeof(char*));
    if(line_to_return == NULL)
    {
        return(NULL);
    }
    //ici on va copier ce qu'il y a dans s1 vers line_to_return
    //puis on copier ce qu'il y a dans s2 vers line_to_return
    while(s1_tmp[i] != '\0'){
        line_to_return[i] = s1_tmp[i];
        i++;
    }
    //ici s1_tmp[i] == '\0' mais on doit passer au dessus pour continuer a ajouter la s2_buf dans line_to_return
    //donc je stoppe la lecture de s1_tmp car il est fini. mais j'incrémente i de 1 pour continuer l'ajout.
    i++;
    while(s2_buf[j] != '\0'){
        line_to_return[i] = s2_buf[j];
        i++;
        j++;
    }
    //maintenant que tout a été copier dans line_to_return, je peux lui ajouter le char final et le return.
    line_to_return[i] = '\0';
    //donc ici line_to_return vaut la concatenation de s1 + s2. AVEC ou SANS le char '\n'.
    //et je vais la return
    *s1_tmp = line_to_return;
    return(s1_tmp);
    //return(s1_tmp);
    //free(line_to_return);
    /*
            Oui, vous avez raison, on ne free pas line_to_return dans la version modifiée du code.
            La raison en est que la variable statique s1_tmp est une variable persistante, ce qui signifie qu'elle existera pendant toute la durée de vie du programme. Par conséquent, la mémoire allouée pour line_to_return sera libérée automatiquement lorsque la variable s1_tmp sera détruite.
    */
    //mais quand est ce que je dois free line_to_return ?
    //Car dans cette fonction, je cree un nouveau char* et je lui alloue un nouvel espace mémoire.
    
    // Je pourrais donc copier la valeur de line_to_return dans la static que j'ai passé en paramêtre et ensuite free l'allocation de mémorie.
    //et ne rien return.
}