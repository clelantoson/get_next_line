/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-lan <cle-lan@42.student.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 14:40:49 by cle-lan           #+#    #+#             */
/*   Updated: 2021/01/26 00:01:59 by cle-lan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

#define BUF_SIZE 10

int get_next_line(int fd, char **line)
{
	char *buf;
	static char *str[OPEN_MAX];
	int retread;

	fd = open("prout", O_RDONLY);
	// check if open() failed
	if (fd < 0)
		return (-1);

	while ((retread = read(fd, buf, BUF_SIZE)))
	{
		buf[retread] = '\0';
		ft_putnbr(retread);
		ft_putstr(buf);
	}

return (0);
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
