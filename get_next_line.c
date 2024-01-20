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

char    *get_next_line(int fd)
{
    //lire le fd jusqu'au bout et afficher la lecture.
    static char *final_line;
    char    tmp_line[BUFFER_SIZE];
    char    *tmp;
    int fd_read;
    int i;
    int len_final_line;

    i = 0;
    len_final_line = ft_strlen(final_line);
    fd_read = read(fd, tmp_line, BUFFER_SIZE);
    if(fd_read <= 0)
    {
        return(NULL);
    }
    //final_line = (char*)malloc((BUFFER_SIZE + len_final_line + 1) * sizeof(char*));
    if(!final_line)
    {
        return(NULL);
    }
    if(len_final_line == 0)//si la longueur de statuc line == 0, ca veut dire ue c'est la premiere fois que l'on utilise. Donc on la rempli normalement.
    {
        final_line = ft_strdup(tmp_line);
        if(!final_line)
        {
            return(NULL);
        }
    }
    else//si la len de final_line est != de 0, on doit ajouter les char de line à partir de la fin de final_line.
    {
        tmp = ft_strjoin(final_line, tmp_line);
        free(final_line);
        final_line = tmp;
        if(!final_line)
        {
            return(NULL);
        }
    }
    // fn qui va afficher ce que final_tmp contient pour voir la différence avec tmp_line.
    if(final_line)
    {
        ft_putstr(final_line);
    }
    return(final_line);
}