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
    int fd_read;
    int nb_read;
    static int index;//int qui stock une copie de la valeur de retour de  read, on repartira à partir de lui au prochain appel de gnl.
    char *buffer[BUFFER_SIZE];//char* qui stock la ligne lu dans le fichier et la retour

    fd_read = open(fd, O_RDONLY);
    if(fd_read < 0)
    {
        return(NULL);
    }
    //ici il faut faire une boucle pour dire ou arreter la lecture avec read.
    // ex while()
    nb_read = read(fd_read, buffer, BUFFER_SIZE);
    if(nb_read < 0){
        return(NULL);
    }
    close(fd_read);
    return(buffer);
}