#include "get_next_line.h"


int main() {
    int fd;
    char *line;
    int i;

    i = 0;
    // Ouvrir le fichier en lecture (assurez-vous d'avoir un fichier texte existant)
    fd = open("test1", O_RDONLY);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    // Lire et afficher chaque ligne du fichier
    while ((line = get_next_line(fd)) != NULL && i < 40) {
        printf("---------------------------------------------------------- %d ---------------------------------------------- \n", i);
        printf("%s\n", line);
        free(line);
        i++;
    }

    // Fermer le fichier
    close(fd);

    return 0;
}