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


//!!!!!!!!!!!!!!!!!!!!!!!!!!!!ATTENTION cette fn crée un espace mémoire et le return pour une variable dans la fonction principal, quand dois free cette espace ?
char    *ft_get_line_return(char **s_line_static){
    char    *tmp_line_return;
    int i;
    int j;

    tmp_line_return = NULL;
    i = 0;
    j = 0;
    while(s_line_static[i] != '\0'){
        if(s_line_static[i] == '\n')
        {
            j = i;
        }
        i++;
    }
    if(j > 0){
        tmp_line_return = (char*)malloc((j + 1) * sizeof(char*));
        if(tmp_line_return == NULL){
            return(NULL);
        }
    }
    i = 0;
    while(i < j){
        tmp_line_return[i] = s_line_static[i];
        i++;
    }
    tmp_line_return[i] = '\0';
    return(tmp_line_return);
}


///////////////////////////////////////////////////////
//malloc recu par ft_strjoin
//malloc crée pour le buf de la fn read. Vérifie comment gerer l'espace mémoire de la fn read, si elle le fait elle même ou si on doit free a chaque appel de la fn
//Dans tout les cas, on devra free le char* buf crée. Quand ?
char    *ft_get_static(char **line_static, int boole_read, int fd)
{
    int nb_read;
    char    *tmp;
    char    *buf;

    nb_read = 0;
    if(!*line_static){
        tmp = NULL;
    }else{
        tmp = *line_static;
    }
    buf = (char*)malloc((BUFFER_SIZE + 1) * sizeof(char*));
    if(buf == NULL)
    {
        return(NULL);
    }
    //donc ici j'utilise la fn read tant que son buffer ne contient pas de char '\0' ou que read n'a pas fini le fichier.
    //En meme temps, j'ajoute à la static, ce que read lit dans son buf grâce à la fonction ft_strjoin.
    while(!ft_strrchr(buf, '\n') || nb_read != 0)
    {
        nb_read = read(fd, buf, BUFFER_SIZE);
        if(nb_read < 0)
        {
            return(NULL);
        }
        tmp = ft_strjoin(tmp,buf);
        if(tmp == NULL){//ici vérifier ce que fais ft_strjoin en cas d'erreur pour ne pas oublier ou ne pas free une variable deja free.
            return(NULL);
        }
    }
    //ici on est soit tombé sur un char '\0' soit read a fini sa lecture.
    //donc on doit return le char* qui contient les lectures de read.
    //donc ici on a un malloc. Et ft_strjoin nous envoies aussi un malloc. Ce malloc sera free lorsque que nous ferons un free de la static car nous donnons à l'adresse d la static, la line de ft_strjoin.
    return(tmp);

}

char *get_next_line(int fd){
    static char     **line_static;
    char            *line_return;
    char            *tmp_static;
    int             boole_read;
    

    if(fd < 0 || BUFFER_SIZE < 1)
    {
        return(0);
    }
    boole_read = 1;
    while(boole_read == 1)
    {
        //line_static sera créé dans gnl et alloué dans get_static.
        //on lui donne donc l'emplacement de la variable static en paramêtre.
        //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! ATTENTION, ici dans cette fn je passe l'adresse du pointeur de line static en paramêtre, je lui donne la valeur de tmp_ft_strjoin et puis je retourne line_static.
        line_static = ft_get_static(&line_static, boole_read, fd);
        //ici attention a ce que lie_static n'ai pas une allocation de mémoire qui à été fait avant que l'on tombe sur une erreur.
        if(line_static == NULL || boole_read == 0)
        {
            return(0);
        }
        //ici on est soit tombé sur un char '\0' soit read a fini sa lecture.
        //donc on doit récuperer les chars jusqu'a l'octet '\n' qui sont dans la statique et les donner au une tmp à return.
        //ceci se fera avec la fn get_line_return
        //Que faire si c'est la fin du fichiers et que read vaut 0 ?
        //rien en change au déroulement de cette fonction, on devra voir plus tard a tout free et ne plus pouvoir utiliser les fn car le fichiers sera fini.
        line_return = ft_get_line_return(&line_static);
    }
    return(line_return);
}



