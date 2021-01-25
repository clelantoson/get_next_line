/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-lan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 14:40:49 by cle-lan           #+#    #+#             */
/*   Updated: 2021/01/21 14:40:56 by cle-lan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUF_SIZE 4096

int get_next_line(int fd, char **line)
{
    (void)line;
    (void)fd;
    return (0); 
}

int main()
{
    int fd;
    int retread;
    char buf[BUF_SIZE + 1];

    fd = open("prout", O_RDONLY | O_CREAT, S_IRUSR | S_IWUSR);
    if (fd == -1)
    {
        ft_putstr("open() failed\n");
        return (1);
    }
    retread = read(fd, buf, BUF_SIZE);
    buf[retread] = '\0';
    ft_putnbr(retread);
    ft_putstr(buf);
    if (close(fd) == -1)
    {
        ft_putstr("close() failed\n");
        return (1);
    }
    return (0); 
}


// Paramètres
// #1. le file descriptor sur lequel lire
// #2. La valeur de ce qui a été lu

// 1 : Une ligne a été lue
// 0 : La fin de fichier a été atteinte
// -1 : Une erreur est survenue

// Ecrivez une fonction qui retourne une ligne lue
// depuis un file descriptor, sans le retour à la
// ligne