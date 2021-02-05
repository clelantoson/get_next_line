/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-lan <cle-lan@42.student.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 14:40:49 by cle-lan           #+#    #+#             */
/*   Updated: 2021/02/05 01:33:49 by cle-lan          ###   ########.fr       */
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
           // printf("eol found : i = %d\n", i);
            return (i);
        }
        i++;
    }
   // printf("oel not found within the str : i = %d\n", i);
    return (-1);
}

char	*stock_line(char *str, int idx_end_line, char **line)
{
	//int		idx_end_line;

	while (str[idx_end_line] && str[idx_end_line] != '\n')
		idx_end_line++;
	if (idx_end_line < ft_strlen(str))
	{
		*line = ft_substr(str, 0, idx_end_line);
		str = ft_substr(str, idx_end_line + 1, ft_strlen(str));
	}
	else
	{
		*line = str;
		str = NULL;
	}
	return (str);
}

// char *ft_stock_in_line(char *str, int idx_end_line, char **line)
// {
//     int len;

//     len = ft_strlen(str);
//    // printf("len = %d\n", len);
//      printf("idx_end_line = %d\n", idx_end_line);
//     while (str[idx_end_line] != '\n' && str[idx_end_line])
// 		idx_end_line++;
//     if (idx_end_line < len) //tant que i est inf a ma len
// 	{
//     printf("idx_end_line = %d\n", idx_end_line);
//     printf("len = %d\n", len);
//     printf("ft_stock_in_line - str before substr = %s\n", str);
//         *line = ft_substr(str, 0, idx_end_line);
//       //   printf("ft_stock_in_line - line after substr = %s\n", *line);
//          //printf("ft_stock_in_line - str after substr = %s\n", str);
//         // printf("ft_stock_in_line - idx_end_line = %d\n", idx_end_line);
//         str = ft_substr(str, idx_end_line + 1, ft_strlen(str));
//       //  printf("ft_stock_in_line - rest of str = %s\n", str);
//        printf("idx_end_line = %d\n", idx_end_line);
//     }
//     //printf("ft_stock_in_line - i = %d\n", i);
//     //if (i == ft_strlen(str)) //si i est == a len (qd jsuis arrive a la fin de ma str);
//     else
//     {
//         *line = str;
//         //printf("ft_stock_in_line - line eof = %s\n", *line);
//         str = NULL;
//     }
//     //je stocke ce qui reste dans str dans line
//     //+ je mets str a NULL
//     return(str);
// }


 int get_next_line(int fd, char **line)
{
	char buf[BUFFER_SIZE + 1];
	static char *str;
	int size_read;
    //char *tmp;
    int idx_end_line;

	// check if open() failed
	if ((fd < 0 || !line || BUFFER_SIZE <= 0))
		return (-1);
    while ((size_read = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[size_read] = '\0';
        //printf("1 - size_read = %d\n", size_read);
        //printf("2 - buf = %s\n", buf);
        if (!str) //on stocke dans str le buf a la premiere lecture
        {
           // tmp = str;
            str = ft_strdup(buf);
           // free(tmp);
         //   printf("3.a - gnl str1 = %s\n", str);
        }
        else //si la static est pas null, on stocke la suite de buf dans la static (avec strjoin)
        {
            str = ft_strjoin(str, buf);
        //    printf("3.b - gnl str2 = %s\n", str);
        }
       // if (ft_strchr(str, '\n')) //on verifie si on trouve un eol dans la str qui a deja ete join
		 if ((check_eol(str) >= 0))
        {
            idx_end_line = check_eol(str);
			//printf("idx_end_line %d\n", idx_end_line);
            break;
        }
	}
    if (str)
        str = stock_line(str,idx_end_line, line);
    else
    {
        //printf("ERROR - size_read < 0 = %d\n", size_read);
        *line = ft_strdup("");
        return (0);
    }
    if (str == NULL)
    	return (0);
	return (1);
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


