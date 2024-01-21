#include "get_next_line.h"

int main(void)
{
    int fd1;
    fd1 = open("test1", O_RDONLY);
    int i = 0;
    while (i < 7)
	{
		printf("get_next_line %d --> %s\n", i, get_next_line(fd1));
        i++;
	}
	close(fd1);
    return(0);
}