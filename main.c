#include "get_next_line.h"

int main(void)
{
    char *line;
    int fd1;
    int fd2;
    int fd3;
    fd1 = open("test1", O_RDONLY);
    fd2 = open("test2", O_RDONLY);
    fd3 = open("test3", O_RDONLY);
    int i = 0;
    while (i < 7)
	{
        printf("ok\n");
		line = get_next_line(fd1);
		printf("line [%02d]: %s", i, line);
		free(line);
		line = get_next_line(fd2);
		printf("line [%02d]: %s", i, line);
		free(line);
		line = get_next_line(fd3);
		printf("line [%02d]: %s", i, line);
		free(line);
		i++;
	}
	close(fd1);
	close(fd2);
	close(fd3);
    return(0);
}