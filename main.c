#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include "get_next_line.h"

// int main()
// {
// 	int fd;
// 	char *line;

// 	fd = open("zut", O_RDONLY);
// 	//printf("0 - open success\n");
// 	while(get_next_line(fd, &line))
// 	{
// 		printf("main - line = %s\n", line);
// 		free(line);
// 	}
// 	printf("main - OEF line = %s\n", line); //qd ca return 0 a l'eof
// 	free(line);
// 	close(fd);

// //	while(1);
// }

int main()
{
	int fd;
    int ret;
    char *line;

    line = 0;
    ret = get_next_line(fd, &line);
    while (ret > 0)
    {
        write(1, line, strlen(line));
        write(1, "\n", 1);
        free(line);
        line = 0;
        ret = get_next_line(fd, &line);
    }
    if (ret == 0)
    {
        write(1, line, strlen(line));
        write(1, "\n", 1);
        free(line);
        line = 0;
    }
}
