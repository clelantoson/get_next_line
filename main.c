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

// int	main(void) {
// 	int		fd = -1;
// 	char	*line =	NULL;
// 	int		ret;

// 	/* open file - if an error occurs here, the test will be ignored, that's not your fault ! */
// 	if ((fd = open("prout", O_RDONLY)) == -1 || read(fd, NULL, 0) == -1) {
// 		printf("fail\n");
// 		return (-1);
// 	}

// 	ret = get_next_line(fd, &line);
// 	printf("%s\n", line);
// 	printf("return value: %d\n", ret);

// 	/* cleaning up */
// 	free(line);
// 	line = NULL;
// 	close(fd);
// printf("succces\n"); //qd ca return 0 a l'eof
// 	return (0);
// }