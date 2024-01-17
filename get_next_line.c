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

void    get_stdin(int fd, char *buffer, size_t size_buffer)
{
    
}

void    get_stdout(int fd, char *buffer, size_t size_buffer)
{

}

char    *get_next_line(int fd){
    char *buffer;
    size_t size_buffer;
    static int staticCountbuffer;

    staticCountbuffer = 0;
    if(fd == 0){
        //entrée standard.
        get_stdin(fd, buffer, size_buffer);

    }else if(fd == 1){
        //sortie standard.
        get_stdout(fd, buffer, size_buffer);
    }else{
        //
    }
}