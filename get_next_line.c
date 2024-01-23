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
            je pourrais donc le free des que ma static aura éteit strjoin.
            --- Ne pas directement changer les valeurs des chars car cela peut amener des erreur. toujours utiliser des copies et bien malloc et free.

        ((((( ok donc ici on a notre static.  )))))

    1.2) maintenant, on doit récuperer notre static et lui extirper la line qui va être retourner.
        Cette line donc, va valoir les octets jusqu'au '\n'.

*/

