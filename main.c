#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>

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

	fd = open("zut", O_RDONLY);
	printf("0 - open success\n");
	while(get_next_line(fd, &line))
	{
		printf("main - line = %s\n", line);
	}
	printf("main - OEF line = %s\n", line); //qd ca return 0 a l'eof
	free(line);
	close(fd);
}


#include <fcntl.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int				get_next_line(int fd, char **line);

int main()
{
	int		fd;
	int		i;
	int		j;
	char	*line = 0;

	j = 1;
	printf("\n==========================================\n");
	printf("========== TEST 1 : The Alphabet =========\n");
	printf("==========================================\n\n");

	if (!(fd = open("files/huge_alphabet", O_RDONLY)))
	{
		printf("\nError in open\n");
		return (0);
	}
	while ((i = get_next_line(fd, &line)) > 0)
	{
		printf("|%s\n", line);
		free(line);
		j++;
	}
	printf("|%s\n", line);
	free(line);
	close(fd);

	if (i == -1)
		printf ("\nError in Fonction - Returned -1\n");
	else if (j == 1056)
		printf("\nRight number of lines\n");
	else if (j != 1056)
		printf("\nNot Good - Wrong Number Of Lines\n");
	j = 1;
	printf("\n==========================================\n");
	printf("========= TEST 8 : SUPER FAT FILE ========\n");
	printf("==========================================\n\n");

	if (!(fd = open("files/huge_file", O_RDONLY)))
	{
		printf("\nError in open\n");
		return (0);
	}
	while ((i = get_next_line(fd, &line)) > 0)
	{
		printf("|%s\n", line);
		free(line);
		j++;
	}
	printf("|%s\n", line);
	free(line);
	close(fd);

	if (i == -1)
		printf ("\nError in Fonction - Returned -1\n");
	else if (j == 2916)
		printf("\nRight number of lines\n");
	else if (j != 2916)
		printf("\nNot Good - Wrong Number Of Lines\n");
	j = 1;
	printf("\n==========================================\n");
	printf("======== TEST 8 : SUPER LONG LINE ========\n");
	printf("==========================================\n\n");

	if (!(fd = open("files/huge_line", O_RDONLY)))
	{
		printf("\nError in open\n");
		return (0);
	}
	while ((i = get_next_line(fd, &line)) > 0)
	{
		printf("%s\n", line);
		free(line);
		j++;
	}
	printf("%s\n", line);
	free(line);
	close(fd);

	if (i == -1)
		printf ("\nError in Fonction - Returned -1\n\n");
	else if (j == 1)
		printf("\nRight number of lines\n\n");
	else if (j != 1)
		printf("\nNot Good - Wrong Number Of Lines\n\n");
	return (0);
}
