#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <unistd.h>
#include <limits.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

int		get_next_line(int fd, char **line);
void	ft_putnbr(int n);
void	ft_putstr(char *str);
void	ft_putchar(char c);

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif

#endif
