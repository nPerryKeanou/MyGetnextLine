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


//gnl_p_t ici on récupere les octets de fd jusqu'a '\0' et on le donne final_line.
//cependant read à fortement avancer et peut-être même dépasser de plusieurs char le '\0'.
//Il faut donc relancer le read mais à partir de la taille de final_line.
char    *gnl_part_two(int fd, char *final_line){
    char *line;
    int fd_read;

    line = NULL;
    line = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char*));//Allocation de mémoire de la taille de la macro BUFFER_SIZE.
    if(!line)
    {
        return(NULL);
    }
    fd_read = 1;//Genre de booleen pour lancer la boucle de fd_read une première fois.
    while(!ft_strchr(line, '\n') && fd_read != 0)
    {
        fd_read = read(fd, line, BUFFER_SIZE);//lecture de fd et donné x*BUFFER_SIZE octet de fd à line. 
        if(fd_read == -1)
        {
            free(line);
            return(NULL);
        }
        line[fd_read] = '\0';//on mets la dernière valeur de line à '\0' pour dire que c'est une chaine de caractere bien terminée.
        final_line = ft_strjoin(final_line, line);//on donne comme valeur à notre static, la jointure de l'ancienne statique et la line lu par read.
        //On relance la boucle si line de read ne comporte pas de char '\0' et que read n'a pas retourner 0 pour dire qu'il est terminé.
        //Au deuxième appel de la boucle, line contiendra les nouveaux octets lus depuis le descripteur de fichier fd, 
        //et ces octets seront ajoutés à la fin de la variable statique final_line. 
        //La valeur de line dans la boucle reflétera les données lues lors de cet appel spécifique à read.
    }
    free(line);
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
    int i;



    i = 0;
    if(fd < 0 && BUFFER_SIZE <= 0)
    {
        return(0);// pourquoi zero est pas NULL ?
    }
    final_line = gnl_part_two(fd, final_line);
    //ici on a recopier la line jusqu'a '\n' dans la static. Mais maintenant, on doit recommencer le processus à partir de la longueur de final_line.
    printf("-------------------------------------- 1.1.2----------------------------\n");
    printf("-------------------------------------- 1.2----------------------------\n");
    printf("-------------------------------------- 1.3----------------------------\n");
    printf("-------------------------------------- 1.4----------------------------\n");
    printf("-------------------------------------- 1.5----------------------------\n");
    if(!final_line)
    {
        return(NULL);
    }
    printf("-------------------------------------- 1.6----------------------------\n");
    printf("-------------------------------------- 1.7----------------------------\n");
    // fn qui va afficher ce que final_tmp contient pour voir la différence avec tmp_line.
    if(final_line)
    {
        printf("-------------------------------------- 1.8----------------------------\n");
        ft_putstr(final_line);
    }
    printf("-------------------------------------- 1.9----------------------------\n");
    return(final_line);
}