/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 11:39:30 by molasz-a          #+#    #+#             */
/*   Updated: 2024/01/25 00:44:51 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	read_buffer(t_file *file)
{
	char	*str;
	int		nbuff;
	int		read_len;

	nbuff = 0;
	str = NULL;
	while(file->nbuff <= nbuff++)
		read_len = read(file->fd, str, BUFFER_SIZE);
	if (read_len < 0)
		return (1);
	else if (read_len > 0)
	{
		file->nbuff++;
		str = ft_strjoin(str, file->buff);
		if (!str)
			return (1);
		file->buff = str;
	}
	else
		file->end = 1;
	return (0);
}

static char	*buff_next_line(t_file *file)
{
	int		len;
	char	*line;

	len = 0;
	while (file->buff[len] && file->buff[len] != '\n')
		len++;
	if ()
	return
}

char	*get_next_line(int fd)
{
	t_file	*file;
	char	*next_line;

	file = get_file(fd);
	if (!file)
		return (NULL);
	if (!file->buff)
	{
		if(read_buffer(file))
			return (NULL);
	}
	else
	{
		next_line = buff_next_line(file);
	}

	return (next_line);
}
