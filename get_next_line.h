#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <unistd.h>
#include <limits.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>


int		get_next_line(int fd, char **line);
void	ft_putnbr(int n);
void	ft_putstr(char *str);
void	ft_putchar(char c);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char    *ft_stock_in_line(char *str, int idx_end_line, char **line);

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 8
# define FD_SIZE 4096
#endif

#endif
