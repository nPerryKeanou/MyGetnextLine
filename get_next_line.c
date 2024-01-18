#include "get_next_line.h"

/**
 * 
 * 1) Donc soit on lit sur l'entrée standard soit on lit depuis un fichiers ou les deux en même temps.
 * 2) Il faut parcourir le fichier tant que l'on tombe sur un '\0', un EOF ou un NULL.
 * 3) IL faut stocker la ligne parcourut dans un buffer.
 * 4) Il faut afficher cette ligne qui est stocké dans un buffer.
 * Et recommencer le processus.

 * 1-2 : On recupére fd pour savoir si on doit lire sur l'entre standard ou dans un fichier précis.
*/

int    get_stdin(int fd, char *buffer,  int size_buffer, int staticCountbuffer)
{
    int returnCountRead;
    int i;

    //ici read va lire tout le fichiers d'une traite, nous nous voulons qu'il s'arrete lorsqu'il rencontre " \0 "  || EOF || SIZE_BUFFER DONNER EN ARGUMENT DE LA FN MAIN
    returnCountRead = read(fd, (unsigned char)buffer, size_buffer);
    i = 0;
    //ici il faut boucler la lecture de l'entré standard jusqu'au moment ou l'on tombe sur \0 - eof - ou size_buff=...
    //a chque incrémentation, on va incrémentation, on va incrémenter le int statique.
    //lorsque l'on va retourner la fn, on va soit ici incrémente de 1 la statique ici ou dans une autre fn mais il faut incrémenter de 1 pour passer au char suivant.( si le char a passer est \Ø ou size_buffer=...)
    //Pour ne pas recommencer a zero à chaque fois, il faut commencer à partir de la valeur de la statique.
    //Donc la condition de la boucle, ce n'est pas ( tant que i != ...) mais (tant que statique != ...). On travail directement sur la statique.
    //          avoir ce qui est le plus prudent, de bosser sur une copie de la statique ou de l'incrémeter directement.
    //on doit quand même utiliser un i pour allouer de la mémoire.
    //Est ce qu'on doit allouer de la mémoire et stocker les chars lu pour les retourer et garder tout ce qu'on a lu dans la meme variables. Et reallouer de la mémoire av ce qu'il y a deja come char lu ?
    // ou alors on doit juste allouer de la mémoire pour une phrase par une phrase ?
    //ou alors on ne doit pas allouer et juste retourner ce qu'on lit ?
}

int    get_stdout(int fd, char *buffer, int size_buffer, int staticCountbuffer)
{

}

char    *get_next_line(int fd){
    char *buffer;
    int size_buffer;
    static int staticCountbuffer;

    staticCountbuffer = 0;
    if(fd == 0){
        //entrée standard.
        get_stdin(fd, buffer, size_buffer, staticCountbuffer);

    }else if(fd == 1){
        //sortie standard.
        get_stdout(fd, buffer, size_buffer, staticCountbuffer);
    }else{
        //
    }
}