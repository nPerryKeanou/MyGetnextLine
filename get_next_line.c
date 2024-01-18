#include "get_next_line.h"
/*
    Les fonctions open() et close() sont fondamentales en programmation informatique. Elles permettent l'ouverture et la fermetures de ressoureces
    , telles que des fichiers, des sockets ou des connexion réseau.
*/


/**
 * 
 * 1) Donc soit on lit sur l'entrée standard soit on lit depuis un fichiers ou les deux en même temps.
 * 2) Il faut parcourir le fichier tant que l'on tombe sur un '\0', un EOF ou un NULL.
 * 3) IL faut stocker la ligne parcourut dans un buffer.
 * 4) Il faut afficher cette ligne qui est stocké dans un buffer.
 * Et recommencer le processus.

 * 1-2 : On recupére fd pour savoir si on doit lire sur l'entre standard ou dans un fichier précis.
*/

//!!!!!!!!!!!!!!!!!!!!!!!!! utiliser memeset ou boucler mo-même pour mettre toutes les valeurs char à 0 lors de la créations d'un tab de char pour être sur qu'il n'y a pas de valeurs qui traine.

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
    //il faut savoir utilisser l'ouverture et fermeture des fichiers sans open et clsoe.
}

int    get_stdout(int fd, char *buffer, int size_buffer, int staticCountbuffer)
{

}

char    *get_next_line(int fd){
    char *buffer;//buffer sera l'endroit ou l'on va stocker la string parcourut jusque \0 et sera lu par la fn. Elle sera utiliser par read().
                //buffer doit allouer de la nouvelle mémoire à chaque fois que l'on appel car elle termine toujours pas \0
                //On ne lui ajoute pas de la valeur, une fois que buf est lu, on le free et le remalloc.
                
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