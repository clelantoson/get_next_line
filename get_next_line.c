/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cle-lan <cle-lan@42.student.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 14:40:49 by cle-lan           #+#    #+#             */
/*   Updated: 2021/02/05 01:48:23 by cle-lan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*stock_line(char *str, char **line)
{
    int idx;
	char *tmp;

    idx = 0;
	while (str[idx] && str[idx] != '\n')
		idx++;
	if (idx < ft_strlen(str))
	{
		*line = ft_substr(str, 0, idx);
		tmp = str;
		str = ft_substr(str, idx + 1, ft_strlen(str));
		free(tmp);
	}
	else
	{
		*line = str;
		str = NULL;
	}
	return (str);
}

 int get_next_line(int fd, char **line)
{
	char buf[BUFFER_SIZE + 1];
	static char *str;
	int size_read;

	if (fd < 0 || !line || BUFFER_SIZE <= 0 || read(fd, buf, 0) < 0) // check if open() failed
		return (-1);
    while ((size_read = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[size_read] = '\0';
        if (!str) //on stocke dans str le buf a la premiere lecture
            str = ft_strdup(buf);
        else //si la static est pas null, on stocke la suite de buf dans la static (avec strjoin)
			str = ft_strjoin(str, buf);
        if (ft_strchr(str, '\n')) //on verifie si on trouve un eol dans la str qui a deja ete join
            break;
	}
    if (str)
        str = stock_line(str, line);
    else
    {
        *line = ft_strdup("");
        return (0);
    }
    if (str == NULL)
    	return (0);
	return (1);
}