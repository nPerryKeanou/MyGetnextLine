# MyGetnextLine
 get_next_line is a school 42 project. Write a function that returns a read line from a file descriptor.

 
• Des appels successifs à votre fonction get_next_line() doivent vous permettre de lire l’intégralité du fichier texte référencé par le descripteur de fichier, une ligne à la fois.
• Votre fonction doit retourner la ligne qui vient d’être lue.
S’il n’y a plus rien à lire, ou en cas d’erreur, elle doit retourner NULL.
• Assurez-vous que votre fonction se comporte correctement qu’elle lise un fichier ou qu’elle lise sur l’entrée standard.
• Important : Vous devez toujours retourner la ligne qui a été lue suivie du \n la terminant, sauf dans le cas où vous avez atteint la fin du fichier et que ce dernier ne se termine pas par un \n.
• Le fichier d’en-tête get_next_line.h doit contenir au minimum le prototype de la fonction.
• Le fichier get_next_line_utils.c vous servira à ajouter des fonctions supplé- mentaires nécessaires à la réalisation de votre get_next_line().
•Votre programme doit compiler avec l’option : -D BUFFER_SIZE=n
Cette macro définie à l’invocation du compilateur servira à spécifier la taille du buffer lors de vos appels à read() dans votre fonction get_next_line().
Cette valeur sera modifiée lors de la peer-evaluation et par la Moulinette dans le but de tester votre rendu.
• Votre programme sera donc compilé de la manière suivante (exemple ci-dessous avec une taille de buffer de 42) :
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 <files>.c
• Nous considérons que get_next_line() a un comportement indeterminé si, entre deux appels, le fichier pointé par le descripteur de fichier a été modifié, alors que le premier fichier n’a pas été lu en entier.
• Nous considérons aussi que get_next_line() a un comportement indeterminé en cas de lecture d’un fichier binaire. Cependant, si vous le souhaitez, vous pouvez rendre ce comportement cohérent.

• La libft n’est pas autorisée pour ce projet.
• La fonction lseek() est interdite.
• Les variables globales sont interdites.

Du fait de sa simplicité, le projet get_next_line laisse peu de place aux bonus, mais nous sommes sûrs que vous avez beaucoup d’imagination. Si vous avez réussi la partie obligatoire, alors n’hésitez pas à faire les bonus pour aller plus loin.
Voici les bonus à réaliser :
• Faites get_next_line() avec une seule variable statique.
• Complétez get_next_line() en lui permettant de gérer plusieurs fd.
Par exemple, si les fd 3, 4 et 5 sont accessibles en lecture, alors il est possible de les lire chacun leur tour sans jamais perdre les contenus lus sur chacun des fd, et sans retourner la mauvaise ligne.
Vous devriez pouvoir appeler get_next_line() une fois avec le fd 3, puis le 4, le 5, puis à nouveau le 3, à nouveau le 4, etc.


-----------------------------------------------------------------------------------------------------------------------------------------



Un file descriptor (descripteur de fichier) est un entier qui représente une "connexion" vers un fichier ou un objet semblable à un fichier, dans le contexte des systèmes d'exploitation de type Unix (comme Linux et macOS). Ce n'est pas le fichier lui-même, mais plutôt une référence abstraite qui permet au système d'exploitation d'identifier et de gérer ce fichier.

Un file descriptor peut représenter différents types d'objets, tels que des fichiers, des sockets, des tubes (pipes), des périphériques, etc. Les trois descripteurs de fichiers standard les plus courants sont :

0 (stdin) : Le descripteur standard d'entrée. Il est associé au clavier par défaut.
1 (stdout) : Le descripteur standard de sortie. Il est associé à l'écran par défaut.
2 (stderr) : Le descripteur standard d'erreur. Il est également associé à l'écran par défaut.
Lorsque vous ouvrez un fichier ou que vous créez une connexion réseau, le système d'exploitation vous attribue un file descriptor pour représenter cette connexion. Vous pouvez ensuite utiliser ce file descriptor pour effectuer des opérations de lecture, d'écriture ou d'autres opérations associées à ce fichier ou à cet objet.

En résumé, un file descriptor est une référence numérique associée à un fichier ou à une ressource semblable à un fichier, et il est utilisé pour interagir avec cette ressource à travers les appels système appropriés.







La fonction get_next_line est une fonction qui permet de lire une ligne d'un fichier, une ligne à la fois.

La fonction fonctionne comme suit :

Elle ouvre le fichier en mode lecture seule.
Elle lit le fichier jusqu'à ce qu'elle rencontre un caractère de fin de ligne (\n).
Elle stocke la ligne lue dans une variable statique.
Elle ferme le fichier.
Elle retourne la ligne lue à l'appelant.
La fonction get_next_line est répétée jusqu'à ce que le fichier soit vide ou qu'une erreur se produise.

La variable statique buf est utilisée pour stocker la ligne lue. La fonction get_next_line utilise la variable buf pour savoir où démarrer la lecture au prochain appel de la fonction.

Voici un diagramme qui illustre le fonctionnement de la fonction get_next_line :

                           |
                           |
                           |
         Ouverture du    |
         fichier         |
                           |
                           |
                           |
         Lecture du     |
         fichier         |
                           |
                           |
                           |
         Stockage de la |
         ligne lue      |
                           |
                           |
                           |
         Fermeture du   |
         fichier         |
                           |
                           |
                           |
         Retour de la   |
         ligne lue      |
                           |
                           |
                           |


Le buffer de read() est vide au début. Au fur et à mesure que read() lit des octets, il les stocke dans le buffer. Une fois la lecture terminée, le buffer contient tous les octets qui ont été lus.