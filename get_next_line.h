#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <unistd.h>


int     get_next_line(int fd, char **line);
void    ft_putnbr(int n);
void    ft_putstr(char *str);
void    ft_putchar(char c);

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 2
#endif 

#endif