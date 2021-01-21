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

int get_next_line(int fd, char **line)
{
    (void)line;
    (void)fd;
    return (0); 
}

int main()
{
    int fd;

    fd = open("prout", O_RDONLY);
    ft_putnbr(fd);
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