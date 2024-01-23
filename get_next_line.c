#include "get_next_line.h"

/**
 * Cette fonction va retourner la nouvelle valeur de final_line, qui est le reste de la lecture de read apres '\n'.
 * Car il est possible que read à lu plus d'octets qu'il ne fallait.
 */
char *ft_new_final_line(char *final_line) {
    int i = 0;
    int j = 0;
    char *new_line;

    // On incrémente la variable i du nombre d'octets parcourus dans final_line jusqu'à ce que l'on tombe sur un octet qui vaut '\n' ou la fin de chaîne ('\0').
    while (final_line[i] != '\0' && final_line[i] != '\n') {
        i++;
    }

    // Si final_line[i] vaut '\0', cela signifie que nous avons atteint la fin de la chaîne, nous libérons la mémoire de final_line et retournons NULL.
    if (!final_line[i]) {
        free(final_line);
        return NULL;
    }

    // On alloue l'espace mémoire pour la nouvelle chaîne qui contient la partie de final_line après '\n' ou jusqu'à la fin de la chaîne.
    new_line = (char*)malloc((ft_strlen(final_line) - i + 1) * sizeof(char));
    if (!new_line) {
        return NULL;
    }

    // On incrémente la variable i pour passer au-dessus de l'octet qui vaut '\0' ou '\n'.
    i++;

    // On copie les octets de final_line dans new_line à partir de '\n' + 1.
    while (final_line[i] != '\0') {
        new_line[j] = final_line[i];
        j++;
        i++;
    }

    new_line[j] = '\0';

    // On libère l'ancienne valeur de final_line et on alloue de la mémoire suffisante avant de copier new_line dans final_line.
    free(final_line);
    final_line = (char*)malloc((ft_strlen(new_line) + 1) * sizeof(char));
    if (!final_line) {
        free(new_line);
        return NULL;
    }

    // On copie new_line dans final_line.
    ft_strcpy(final_line, new_line);

    // On libère la mémoire de new_line.
    free(new_line);

    // On retourne la nouvelle valeur de final_line.
    return final_line;
}


/**
 * Cete fonction va retouner une nouvelle de caractères.
 * Cette nouvelle chaine, sera en sorte, la final_chaine jusqu'a l'octet qui vaut '\n'.
 * 
 */
char    *ft_new_line(char *final_line)
{
    int i;
    char *new_line;

    i = 0;
    //ON vérifie si l'index de final_line est NULL, si oui, on retourne NULL.
    if(!final_line[i]){
        return(NULL);
    }
    //On incrémente la variable i tant que l'index de final_line est différent ddes chars '\0' et '\n'.
    //Cette variable va nous donner la valeur pour l'allocation de l'esp&ce mémoire de la chaine de caractère.
    while(final_line[i] != '\0' && final_line[i] != '\n'){
        i++;
    }
    //On alloue l'espace mémoire de new_line avec la variable i et on lui ajoute deux octets.
    new_line = (char*)malloc((i + 2) * sizeof(char));
    if(new_line == NULL)
    {
        return(NULL);
    }
    i = 0;
    //On remet la variable i à 0 et on parcourt la final_line tant que la valeur de l'index est différent des chars '\0' et '\n'.
    //En parcourant cette variable, on donne à notre nouvelle chaine allouée en amont, la valeur des chars des index parcourut.
    while(final_line[i] != '\0' && final_line[i] != '\n')
    {
        new_line[i] = final_line[i];
        i++;
    }
    //Si le char de l'index i égale '\n', sait que ca ne sert à rien d'aller plus loin.
    //La boucle s'est arrété. On lui assigne à la main cette valeur, on incrémente de 1 et on lui donnera le char de fin de chaîne.
    if(final_line[i] == '\n'){
        new_line[i] = final_line[i];
        i++;
    }
    new_line[i] = '\0';
    //on retourne la nouvelle chaine de caractere.
    return(new_line);
}



/**
 * Cette function va renvoyer une nouvelle chaine de caractère.
 * Cette nouvelle chaine est la lecture de read selon le BUFFER_SIZE ou si on trouve un octet égale au char '\n' + l'ancienne chaien final_line.
*/
char    *ft_read_and_return_final_line(int fd, char *final_line){
    char *line;
    int fd_read;
    //On met *line à NULL pour être sûr de démrrer sur de bonnes bases.
    line = NULL;
    line = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char*));//Allocation de mémoire de la taille du BUFFER_SIZE donné ou de celui dans le gnl.h.
    if(!line)
    {
        return(NULL);
    }
    //Donner 1 comme valeur à fd_read car celui ci lancera notre lecture. Dans la boucle, lorsque read aura fini la lecture, il vaudra 0.
    if(final_line == NULL){
        fd_read = read(fd, line, BUFFER_SIZE);
        if(fd_read == -1)
        {
            free(line);
            return(NULL);
        }
        if(fd_read == 0){
            return(line);
        }
        line[fd_read] = '\0';
        final_line= ft_strjoin(final_line, line);
        if(final_line == NULL)
        {
            free(final_line);
            free(line);
            return(NULL);
        }

    }
    //ICI line vaudra deja les X octet de BUFFER_SIZE
    //Tant qu'un octet de line ne vaut pas la valeur le char '\n' ou que read re vaut pas 0 en atteignant la fin du fichier.
    //dans cette condition de boucle, on boucle tant qu'octet de line ne vaut pas '\n' ou que read est différent de 0.
    //En lancant cette conditon, read fait une première lecture.
    //while(!ft_strchr(line, '\n') && read(fd, line, BUFFER_SIZE) != 0)
    while(!ft_strchr(line, '\n') && fd_read != 0)
    {
        //fd_read vaudra le retour de read(), qui sera le nb d'octet lu soit par la valeur de BUFFER_SIZE soit par le retour de read qui sera 0 car il aura fini le fichier. 
        //fd_read = read(fd, line, BUFFER_SIZE);
        //Si fd_read vaut moins 1, c'est qu'il y a eu une erreur dans la lecture.
        //On devra donc free l'espace mémoire de *line que nous avons malloc en amont et retourner NULL.
        fd_read = read(fd, line, BUFFER_SIZE);
        if(fd_read == -1)
        {
            free(line);
            return(NULL);
        }
        if(fd_read == 0){
            return(line);
        }
        //On donne le char '\0' de fin de chaine à *line pour préciser que c'est une chaîne de caractères.
        //On lui donne donc la longueur parcourut par read. En sachant que les tableau commence toujours à l'index 0.
        line[fd_read] = '\0';
        //On change la valeur de final_line avec ce que read à lu et stocker dans le buffer *line.
        final_line= ft_strjoin(final_line, line);
        if(final_line == NULL)
        {
            free(final_line);
            free(line);
            return(NULL);
        }
        
    }
    //Après avoir changer la valeur de final_line en ajoutant ce que read à lu et stocké dans *line, on free l'espace mémoire donné à *line.
    //free(line); est ce vraiment nécessaire ?

    //On retourne la nouvelle chaine final_line.
    return(final_line);
}






/**
 * la fonction get_next_line(int fd) retourne une ligne lu.
 * En utilisant une variable statique, on peux lire tout un 'fichier' selon le nombre de fois que l'on appel la g_n_l.
 * 
 * 
 *
*/
//////////////////////////////////////////////////////JE DOIS BOUCLER MA GNL ET QANDD CELLE CI EST FINI, JE DOIS FREE MA STATIQUE ., C'EST LA LA FUITE DE MÉMOIRE
char    *get_next_line(int fd)
{
    static char *final_line;
    char    *tmp_line;

    final_line = NULL;
    tmp_line = NULL;
    //vérification du fd et de BUFFER_SIZE.
    //Si le fd est plus petit que 0, cela est un erreur.
    //Si BUFFER_SIZE est plus petit ou égale à 0, cela ne sert à rien d'aller plus loin.
    if(fd < 0 && BUFFER_SIZE <= 0)
    {
        // pourquoi zero est pas NULL ?
        //icin nous retournons une erreur est non un NULL car NULL est généralement utilisé pour représenter un pointeur.
        return(0);
    }
    //Changement de la valeur de la statique avec la fonction ft_read_and_return_final_line(). 
    final_line = ft_read_and_return_final_line(fd, final_line);
    //Si la fonction ft_read_and_return_final_line à retourner un char* NULL, on retourne NULL et on arrête la fonction.
    if(!final_line)
    {
        return(NULL);
    }
    //Changement de la valeur de tmp_line avec la fonction ft_new_line().
    tmp_line = ft_new_line(final_line);
    //La condition if (!tmp_line) vérifie si la variable tmp_line est égale à NULL. En langage C, NULL est généralement utilisé pour représenter un pointeur nul, c'est-à-dire qu'il ne pointe vers aucune zone de mémoire.
    if(!tmp_line){
        return(NULL);
    }
    //Changement de la valeur de la statique final_line avec la fonction ft_new_final_line().
    final_line = ft_new_final_line(final_line);
    //Retour de gnl en renvoyant le char* final_line.
    return(tmp_line);
}