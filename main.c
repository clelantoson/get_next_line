// #include <unistd.h>
// #include <stdlib.h>
// #include <stdio.h>
// #include <fcntl.h>
// #include <string.h>

// #include "get_next_line.h"

// int main()
// {
//     int ret;
//     char *line;
// 	int fd;

//     line = 0;
// 	fd = open("prout", O_RDONLY);
//     ret = get_next_line(fd, &line);
//     while (ret > 0)
//     {
//         write(1, line, strlen(line));
//         write(1, "\n", 1);
//         free(line);
//         line = 0;
//         ret = get_next_line(fd, &line);
//     }
//     if (ret == 0)
//     {
//         write(1, line, strlen(line));
//         write(1, "\n", 1);
//         free(line);
//         line = 0;
//     }
// }

#include <stdio.h>
#include "get_next_line.h"
int main()
{
	int fd;
	char *line;

	fd = open("prout", O_RDONLY);
	printf("0 - open success\n");
	while(get_next_line(fd, &line))
	{
		printf("main - line = %s\n", line);
	}
	printf("main - OEF line = %s\n", line); //qd ca return 0 a l'eof
	free(line);
	close(fd);
}
