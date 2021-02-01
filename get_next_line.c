/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-lan <cle-lan@42.student.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 14:40:49 by cle-lan           #+#    #+#             */
/*   Updated: 2021/01/29 19:53:25 by cle-lan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char check_eol(char *str)
{
    int i;

    i = 0;
    while(str[i])
    {
        if (str[i] == '\n')
        {
            printf("eol found : i = %d\n", i);
            return (i);
        }
        i++;
    }
    printf("oel not found within the str : i = %d\n", i);
    return (-1);
}


void ft_stock_in_line(char *str, int idx_end_line, char **line)
{
	int i;

	i = 0;
	printf("ft_stock_in_line - str = %s\n", str);
	printf("ft_stock_in_line - idx_end_line = %d\n", idx_end_line);
    str[idx_end_line] = '\0';
	printf("ft_stock_in_line - str after 0 = %s\n", str);
    *line = ft_strdup(str);
	printf("ft_stock_in_line - line = %s\n", *line);
}


int get_next_line(int fd, char **line)
{
	char buf[BUFFER_SIZE + 1];
	static char *str;
	int size_read;
    int idx_end_line;

    idx_end_line = 0;
	// check if open() failed
	if (fd < 0 || !line)
    {
        printf("gnl erreur\n");
		return (-1);
    }
    while ((size_read = read(fd, buf, BUFFER_SIZE)))
	{
		buf[size_read] = '\0';
        printf("1 - size_read = %d\n", size_read);
        printf("2 - buf = %s\n", buf);
        if (!str) //on stocke dans str le buf a la premiere lecture
        {
            str = ft_strdup(buf);
            printf("3.a - gnl str1 = %s\n", str);
        }
        else if (str) //si la static est pas null, on stocke la suite de buf dans la static (avec strjoin)
        {
            str = ft_strjoin(str, buf);
            printf("3.b - gnl str2 = %s\n", str);
        }
        if ((check_eol(str) >= 0)) //on verifie si on trouve un eol dans la str qui a deja ete join
    	{
			idx_end_line = check_eol(str);
			printf("coucou idx_end_line %d\n", idx_end_line);
            ft_stock_in_line(str, idx_end_line, line); 
            break;
		}
	} 
    //ft_stock_in_line(str, idx_end_line, line);  
return (1);
}



// int main()
// {
//     int fd;
//     int retread;
//     char buf[BUF_SIZE + 1];

//     fd = open("prout", O_RDONLY);
//     if (fd == -1)
//     {
//         ft_putstr("open() failed\n");
//         return (1);
//     }
//     while (retread = read(fd, buf, BUF_SIZE))
//     {
//         buf[retread] = '\0';
//         ft_putnbr(retread);
//         ft_putstr(buf);
//     }
//     ft_putnbr(retread);
//     if (close(fd) == -1)
//     {
//         ft_putstr("close() failed\n");
//         return (1);
//     }
//     return (0);
// }


// Paramètres
// #1. le file descriptor sur lequel lire
// #2. La valeur de ce qui a été lu

// 1 : Une ligne a été lue
// 0 : La fin de fichier a été atteinte
// -1 : Une erreur est survenue

// Ecrivez une fonction qui retourne une ligne lue
// depuis un file descriptor, sans le retour à la
// ligne
