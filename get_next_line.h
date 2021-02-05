#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <unistd.h>
#include <limits.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>


int		get_next_line(int fd, char **line);
char	*ft_strdup(const char *s1);
int		ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, int start, int len);
char	*ft_strchr(const char *s, int c);
char	*stock_line(char *str, char **line);

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 8
# define FD_SIZE 4096
#endif

#endif
