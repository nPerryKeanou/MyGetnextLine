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

Les fonctions open() et close() sont des fonctions fondamentales en programmation informatique. Elles permettent d'ouvrir et de fermer des ressources, telles que des fichiers, des sockets ou des connexions réseau.

