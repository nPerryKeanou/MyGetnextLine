/*
    1) lire le file descriptor jusqu'a ce un octet == '\n' OU que read == 0.
    2) récuperer cette lecture et la stockr dans un static char* car c'est à partir de la fin que l'on va recommencer le read.
    3) ajouter la nouvelle static à l'ancienne.
    4) récuperet dans un nouveau char*, la static jusqu'a l'octet '\n' ou si read == 0 avant la total de buffer_size. Et afficher ce char.
    
    EN gros c'est ca. Maintenant, il faut sous catégoriser un max en petite fn.

    1) get_next_line va faire appel à plusieurs fn.
        ft_read_fd(fd) -> cette fonction va retourner le char* qui à été lu et qui est stocke dans le buffer de read. Et en même temps,
        il va changer un int pointeur qui est passer en paramêtre. Ce int pointeur sera le nb d'octet lu par read, si ce pointeur = 0, c'est le fichier est fini.
        -ici on a lu une premiere fois le fd et on a récuperer un char*. Ce char* doit être fini manuellement



    2) Comme ce char* va comporter plus d'octets qu'il ne faut,car gnl va lire jusqu'au '\n'. On doit créer un nouveau char*, et y stocker 
        x octets de static jusqu'a '\n', plus 1 pour ajoute le char '\0' manuellement.

    3) Comme gnl doit retourner ligne par ligne, elle ne retourne un char* qui se fini par le char '\n'.
       Et Comme read lui ne s'arrter pas forcement a ce char la mais peut-être plus loin, il doit modifer la static pour qu'elle ne garde plus
       que les chars qui n'ont pas étaient retourner.

    4) ATTENTION À TOUTES LES ALLOCATIONS D'ESPACES MÉMOIRES !!!!!!!!!!!!!!!!!!!!!!!
        MARQUER CHAQUE ALLOCATIONS, SUIVRES LEURS CHEMINS, SAVOIR QUAND ILS SONT UTILISÉES, RÉUTILISÉS ET QUAND ON N'A PLUS BESOIN D'EUX. 

    1.1) Dans get_next_line(int fd), je vais avoir comme variable;  - une static char* static_line qui n'aura pas de valeur au début.
                                                                    - un int nb_octet_read qui vaudra 1.
                                                                    - un char* line_tmp qui vaudra null.
                                                                    - un char* line_return qui vaudra null.

        - Je dois directement vérifier si le fd est plus grand ou égale à zero et si buffer_size et plus grand que zero.
        - Je lance la fn qui va utiliser read. Cette fn va me renvoyer un char*, ce sera la valeur de static.
            Dans cette fonction, je devrais creer un char* et lui allouer un espace mémoire de la taille du BUFFER_SIZE ou de la taille de buffer de read.
                Seulement si c'est le première appel de gnl car la static sera vide. Car au prochain appel, la static ne sera plus vide mais vaudra 
                le nb d'octet qui n'aura pas étaient renvoyer dans la line_return. Donc on devra faire un strjoin de taille_static_actuel + taille_static_buffer_read + 1.
            ICI J'AI UN MALLOC !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! Je devrais donc le free, mais quand ? Ce char est un copie de qui va être ajouter dans static, 
            je pourrais donc le free des que ma static aura éteit strjoin. Mais ca veut dire que ma static aura une mémorie alloué, même si la variable qui lui a servi a join est free.
            Je devrais faire un tmp qui va stocker le join, free l'ancienne static et lui donner la tmp qui a eu le join.
            --- Ne pas directement changer les valeurs des chars car cela peut amener des erreur. toujours utiliser des copies et bien malloc et free.

            On doit faire un malloc de taille 1 pour le premier appel de gnl car la statique sera vide.
            Mais Comment savoir i 

        ((((( ok donc ici on a notre static.  )))))

    1.2) maintenant, on doit récuperer notre static et lui extirper la line qui va être retourner.
        Cette line va donc valoir, x octets de la static. Du premier octet jusqu'a ce que octet vale '\n'.
        Je devrais donc récuperer la variable depuis la fn get_next_line en paramêtre.
        Il y aura deux boucles, la premiere qui va boucler jusqu'a octet '\n'.
        La deuxieme va boucler le nb de la premiere pour ajouter à la tmp, les octets de statique.
        !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! ICI J'AI UN MALLOC !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
            Donc attention, savoir ce qui à était alloue, qui va utiliser cette allocation, et savoir quand la free .
        Je pense que cette variable ne sera allouer que une seul fois par gnl. Car c'est la line qui l'on doit retourner.
        Donc on lui alloue de la mémoire et on la free avant la fin du fichier. Mais comment free un char* alloué alors que c'est celle-la
        que je dois return ?

        ((((( ok ici j'ai ma line à return)))))

    1.3) maintenant que j'ai la line à return, je dois modifier ma statuc pour qu'elle ne garde que les octets qui n'ont pas étaient pris en compte
         dans la line à return. Car la line à return s'arrête à l'octet '\n'.
         Donc on peut récuperer la longueut de line à return. On garde la différence entre la longueur total de static et la longueur de line à return.
         Cette différence sera le nb d'octets qui ne sera pas return et donc qui sera réutiliser dans la static.
         Pour stockrt ces octets non utilisés, je dois créer une char* et lui alloué l'espace mémoire de len_static - len len_line_à_return + 1.
         !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!ATTENTION ICI J'AI UN MALLOC!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
         VÉRIFIER QUI L'UTILISE, ET OU RÉUTILISE, OÙ IL PEUT ÊTRE FREE.
         Ensuite on doit boucler à parir de len_static - différence_len_static_len_line_à_return.
         On ajoute dans la char* alloué, les octets de static à partir de len_static - différence_len_static_len_line_à_return.
         Et on return la line. 
         Cette line sera la nouvelle statique donc on ne la free pas ici mais seulement en fin de fichier si unn condition est accepter.

            Cette condition return free static et return line en même temps, si read return 0 et a donc fini de lire le fd.


    2) Je vais avoir plusieurss malloc.
        - la static qui sera crééer dans gnl et alloué dans la fn read...
        - la line_return qui sera créer dans gnl et qui sera alloué dans la fn qui récuperer les octets de statique.
        - la tmp_static qui sera crée dans gnl mais qui sera alloué dans la fonction qui va récuperer les octets non utilisés de la statiques.

        Donc je devrais avoir trois char* alloué max ou 4 peut-être mais pas sur.

        .
        .
        .

        Il faut free les chars lorsqu'il y a une erreur ou que le programme/la fn se termine. On ne doit pas free la variable, avant, on peux changer sa valeur ou son adresse mais pas free si on la reutilise apres.

    3)  - get_next_line(int fd);
        - ft_get_static(char *line_static, );
        - ft_get_line_return();
        - ft_get_new_static(char *line_static,)


    4) Check les conditons des boucles pour savoir quand commence et quand s'arretr la fn gnl ,ect...
        Donc pour stopper gnl et free la static, je dois avoir une boolen qui sera envoye en paramêtre à la fn qui va utiliser read, 
        lorsque read aura fini de lire le fichier, la boolen envoyé en paramêtre sera modifier.
        Dans gnl si la boolen vaudra 0, on pourra return free statuc et return la line.


    Lets go comme ca et inshalla.
*/

#include "get_next_line.h"


char    *ft_get_static(int fd, char *tmp_line_static){
    //ce char* va prendre la valeur de buf de read.
    //ici on retourne un char * qui va être récuperer par la statique.
    //Donc ce char* va être en premier lieux ( vu que static ne vaut rien),
    //être la valeur du buf de read.
    //DOnc on va utiliser un strup et puis un strcpy.
    //Mais comment savoir quand faire ca et pas directement les join ?
    //On peut avoir des conditions qui vont check si  static et null ou si static[0] == 0 
    //on peux soit comparer line ici ou dans gnl direct avec des boole.
    char    *str;
    //on doit créer et alloué le buf que va utiliser read.
    char    *buf;
    int nb_read;

    str = NULL;
    buf = (char*)malloc((BUFFER_SIZE + 1) * sizeof(char*));
    if(buf == NULL)
    {
        return(NULL);
    }
    //il ne faut pas oublier que la static est la une chaine de caractere qui va être soit un ou plusieurs buffer_size à la suite jusqu'au moment où l'on tombe sur un '\n' ou que read == 0.
    //donc on doit tout de même lancer la fn read.
    //si static n'existe pas encore, on la crée avec un copie de buf.
    //sinon, on utilise ft_strjoin pour assembler l'ancienne statique et le new buf de read.
    //
    //il faut boucler pour que buf de read trouve un '\n'.
    //on va donc à chaque tour de boucle, ajouter le buf dans  une tmp de static car le buf va être changer à chaque appel de read.
    //Une fois que l'ajout est fait dans la tmp de static, on doit la chek pour voir si un de ses octets == '\n'.
    //comment faire ?
    //on peut lancer la fn_strrchr, qui retourne un pointeur lorsque l'on tombe sur un octet recherhcer.
    //Donc on peux boucler tant que ft_strrcrh nous return NULL car sa voudrait dire qu'on n'a pas trouve de '\n'
    //mais pour lancer la boucle sur cette fn, il faut que que tmp ait une valeur, donc un premier buf. et pour avoir un premier buf, il faut avoir fait un premier appel à read().
    //ici on fait le premier appel a read et on va le stocker direct dans str. Ensuite on lance la boucle de ft_strrchr() et on va utiliser read pour lire le fichier et ft_strjoin pour ajouter le buf de read avant qu'il ne change dans str.
    //si la boucle s'arrete, ca veux dire que str (qui aura un ou plusieurs buf de read) contiendra un char '\n'.
    //et ca veux dire aussi que str peux avoir le rest du buf apres le char '\n'.
    //On devra donc faire ensuite appel à une autre fn qui va récuper les chars jusqu'a '\n' et la return
    //et une autre fn, qui va changer la statique avec les autrs chars de str apres '\n'
    // et on relance gnl selon le main.
    if(tmp_line_static == NULL || !tmp_line_static)
    {
        nb_read = read(fd, buf, BUFFER_SIZE);
        if(nb_read <= 0)
        {
            return(NULL);
        }
        str = ft_strdup(buf);
        if(str == NULL)
        {
            return(NULL);
        }
        str[ft_strlen(str)] = '\0';
    }
    
    return(str);
}

char    *get_next_line(int fd)
{
    static char *line_static;
    char        *line_return;
    char        *line_tmp;
    int         i;

    //vérifier si fd est correct et qu'un buffer_size de taille correct est ok.
    if(fd < 0 && BUFFER_SIZE <= 0)
    {
        return(NULL);
    }
    //ici, il faut lancer la fn qui va lancer la boucle read et creer la statique.
    line_static = ft_get_static(fd);
}