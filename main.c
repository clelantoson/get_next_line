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
		printf("line = %s\n", line);
	}
	printf("line = %s\n", line); //qd ca return 0 a l'eof
	free(line);
	close(fd);
}
