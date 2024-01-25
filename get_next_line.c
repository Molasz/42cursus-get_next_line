/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 11:39:30 by molasz-a          #+#    #+#             */
/*   Updated: 2024/01/25 18:19:10 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	read_buffer(t_file *file)
{
	char	*str;
	int		read_len;

	str = malloc(BUFFER_SIZE + 1);
	if (!str)
		return (1);
	read_len = read(file->fd, str, BUFFER_SIZE);
	if (read_len < 0)
		return (1);
	else if (read_len > 0)
	{
		if (read_len < BUFFER_SIZE)
			file->end = 1;
		str[read_len] = '\0';
		str = ft_strjoin(file->buff, str);
		if (!str)
			return (1);
		file->buff = str;
	}
	else
		file->end = 1;
	return (0);
}

static int	newline_buff(t_file *file)
{
	int	i;

	if (!file->buff)
		return (0);
	i = 0;
	while (file->buff[i])
	{
		if (file->buff[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

static int	calc_buff(t_file *file, int line_len)
{
	char	*res;
	int		i;

	res = malloc(ft_strlen(file->buff) - line_len + 1);
	if (!res)
		return (1);
	i = 0;
	while (file->buff[i + line_len])
	{
		res[i] = file->buff[i + line_len];
		i++;
	}
	res[i] = '\0';
	free(file->buff);
	file->buff = res;
	return (0);
}

static char	*buff_next_line(t_file *file)
{
	char	*line;
	int		len;
	int		i;

	while (!newline_buff(file) && !file->end)
	{
		if (read_buffer(file))
			return (NULL);
	}
	if (file->end && !ft_strlen(file->buff))
		return (NULL);
	len = 0;
	while (file->buff[len] != '\n' && file->buff[len] != '\0')
		len++;
	line = malloc(len + 1);
	if (!line)
		return (NULL);
	line[len] = '\0';
	i = -1;
	while (++i <= len)
		line[i] = file->buff[i];
	if (calc_buff(file, i))
		return (NULL);
	return (line);
}

char	*get_next_line(int fd)
{
	t_file	*file;
	char	*next_line;

	if (fd < 0)
		return (NULL);
	file = get_file(fd);
	if (!file)
		return (NULL);
	next_line = buff_next_line(file);
	return (next_line);
}
