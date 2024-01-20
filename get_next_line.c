#include "get_next_line.h"
/*
    Les fonctions open() et close() sont fondamentales en programmation informatique. Elles permettent l'ouverture et la fermetures de ressoureces
    , telles que des fichiers, des sockets ou des connexion réseau.
*/


/**
 * 
 * 1) Donc soit on lit sur l'entrée standard soit on lit depuis un fichiers ou les deux en même temps. avec open et read
 * 2) Il faut parcourir le fichier tant que l'on tombe sur un '\0', un EOF ou un NULL. avec ft_strnstr modifier
 * 3) IL faut stocker la ligne parcourut dans un buffer. Donc je dois allouer de la mémoire par rapport a ce que read renvoie comme valeur.
 *          read retourne le nb d'octet lu ou -1 en cas d'erreur.
 * 4) Il faut afficher cette ligne qui est stocké dans un buffer.
 * Et recommencer le processus.

 * 1-2 : On recupére fd pour savoir si on doit lire sur l'entre standard ou dans un fichier précis.
*/

//!!!!!!!!!!!!!!!!!!!!!!!!! utiliser memeset ou boucler mo-même pour mettre toutes les valeurs char à 0 lors de la créations d'un tab de char pour être sur qu'il n'y a pas de valeurs qui traine.
/*
    Pour lire le fichier ligne par ligne, il faut appeler la fonction get_next_line à répétition jusqu'à ce que la fonction retourne NULL. Cela signifie que la fonction n'a pas pu lire de ligne supplémentaire.


- je vais essaier d'avoir une seul statique, qui sera un int. Ce sera le retour de read, et au prochain appel, repartira à partir de ce int index.
- Pour ce faire, je peux stocker le buffer et pour lire la derniere ligne recun je peux lancer une fn qui va afficher les chars en la dernier et l'avant dernierx occurence de \0
Comme ca j'ai pas besoin d'index. Et j'aurais la taille pour le malloc.
*/

char    *ft_new_final_line(char *final_line){
    int i;
    int j;
    char   *new_line;

    i = 0;
    while(final_line[i] != '\0' && final_line[i] != '\n'){
        i++;
    }
    if(!final_line[i]){
        free(final_line);
        return(NULL);
    }
    new_line = (char*)malloc((ft_strlen(final_line) - i + 1) * sizeof(char));
    if(!new_line){
        return(NULL);
    }
    i++;
    j = 0;
    while(final_line[j]){
        new_line[j] = final_line[i];
        j++;
        i++;
    }
    new_line[j] = '\0';
    free(final_line);
    return(new_line);
}


char    *ft_new_line(char *final_line)
{
    int i;
    char *new_line;

    i = 0;
    //La condition if (!final_line[i]) vérifie si le caractère à l'index i de la chaîne final_line est nul ('\0'). En langage C, la fin d'une chaîne de caractères est marquée par un caractère nul.
    if(!final_line[i]){
        return(NULL);
    }
    while(final_line[i] != '\0' && final_line[i] != '\n'){
        i++;
    }
    new_line = (char*)malloc((i + 2) * sizeof(char));
    if(new_line == NULL)
    {
        return(NULL);
    }
    i = 0;
    while(final_line[i] != '\0' && final_line[i] != '\n')
    {
        new_line[i] = final_line[i];
        i++;
    }
    if(final_line[i] == '\n'){
        new_line[i] = final_line[i];
        i++;
    }
    new_line[i] = '\0';
    return(new_line);
}

//gnl_p_t ici on récupere les octets de fd jusqu'a '\0' et on le donne final_line.
//cependant read à fortement avancer et peut-être même dépasser de plusieurs char le '\0'.

char    *ft_read_and_return_final_line(int fd, char *final_line){
    printf("-------------------------------------- 1.2  1 ----------------------------\n");
    char *line;
    int fd_read;

    line = NULL;
    line = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char*));//Allocation de mémoire de la taille de la macro BUFFER_SIZE.
    printf("-------------------------------------- 1.2  2 ----------------------------\n");
    if(!line)
    {
        return(NULL);
    }
    printf("-------------------------------------- 1.2  3 ----------------------------\n");
    fd_read = 1;//Genre de booleen pour lancer la boucle de fd_read une première fois.
    printf("-------------------------------------- 1.2  4 ----------------------------\n");
    while(!ft_strchr(line, '\n') && fd_read != 0)
    {
        printf("-------------------------------------- 1.2  4.2 ----------------------------\n");
        fd_read = read(fd, line, BUFFER_SIZE);//lecture de fd et donné x*BUFFER_SIZE octet de fd à line.
        printf("-------------------------------------- 1.2  4.3 ----------------------------\n"); 
        if(fd_read == -1)
        {
            free(line);
            return(NULL);
        }
        printf("-------------------------------------- 1.2  4.4 ----------------------------\n");
        line[fd_read] = '\0';//on mets la dernière valeur de line à '\0' pour dire que c'est une chaine de caractere bien terminée.
        printf("-------------------------------------- 1.2  4.5 ----------------------------\n");
        final_line = ft_strjoin(final_line, line);//on donne comme valeur à notre static, la jointure de l'ancienne statique et la line lu par read.
        //On relance la boucle si line de read ne comporte pas de char '\0' et que read n'a pas retourner 0 pour dire qu'il est terminé.
        //Au deuxième appel de la boucle, line contiendra les nouveaux octets lus depuis le descripteur de fichier fd, 
        //et ces octets seront ajoutés à la fin de la variable statique final_line. 
        //La valeur de line dans la boucle reflétera les données lues lors de cet appel spécifique à read.
        printf("-------------------------------------- 1.2  4.6 ----------------------------\n");
    }
    printf("-------------------------------------- 1.2  5 ----------------------------\n");
    free(line);
    printf("-------------------------------------- 1.2  6 ----------------------------\n");
    return(final_line);
}


char    *get_next_line(int fd)
{
    printf("-------------------------------------- 1.1----------------------------\n");
    //lire le fd jusqu'au bout et afficher la lecture.
    //comment voir si c'est le premiere appel de la fonction ?
    static char *final_line;
    char    *tmp_line;
    char    *tmp;

    if(fd < 0 && BUFFER_SIZE <= 0)
    {
        return(0);// pourquoi zero est pas NULL ?
    }
    printf("-------------------------------------- 1.2----------------------------\n");
    final_line = ft_read_and_return_final_line(fd, final_line);
    printf("-------------------------------------- 1.3----------------------------\n");
    if(!final_line)
    {
        return(NULL);
    }
    printf("-------------------------------------- 1.4----------------------------\n");
    tmp_line = ft_new_line(final_line);
    printf("-------------------------------------- 1.5----------------------------\n");
    //La condition if (!tmp_line) vérifie si la variable tmp_line est égale à NULL. En langage C, NULL est généralement utilisé pour représenter un pointeur nul, c'est-à-dire qu'il ne pointe vers aucune zone de mémoire.
    if(!tmp_line){
        return(NULL);
    }
    printf("-------------------------------------- 1.6----------------------------\n");
    final_line = ft_new_final_line(final_line);
    printf("-------------------------------------- 1.7----------------------------\n");
    return(final_line);
}