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
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *str);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_substr(char const *s, unsigned int start, size_t len);

#ifndef BUF_SIZE
# define BUF_SIZE 8
#endif

#endif
