#include <stdio.h>
#include "get_next_line.h"
int main()
{
	int fd;
	char *line;

	fd = open("prout", O_RDONLY);
	while(get_next_line(fd, &line))
	{
		printf("line = %s\n", line);
	}
	free(line);
	close(fd);
}
