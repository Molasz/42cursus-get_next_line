/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 11:40:24 by molasz-a          #+#    #+#             */
/*   Updated: 2024/01/30 00:24:12 by molasz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_file	*get_file(t_file *files, int fd)
{
	t_file	*file;

	file = files + fd;
	if (!file->init)
	{
		file->fd = fd;
		file->end = 0;
		file->init = 1;
		file->buff = NULL;
		files[fd] = *file;
	}
	return (file);
}

size_t	ft_strlen(char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	int		i;
	int		j;

	res = malloc((ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (s1 && s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2 && s2[j])
	{
		res[i + j] = s2[j];
		j++;
	}
	free(s2);
	if (s1)
		free(s1);
	res[i + j] = '\0';
	return (res);
}

char	*new_line(t_file *file)
{
	char	*line;
	int		len;
	int		i;

	len = 0;
	while (file->buff[len] != '\n' && file->buff[len] != '\0')
		len++;
	if (file->buff[len] == '\n')
		len++;
	if (!len)
		return (NULL);
	line = malloc(len + 1);
	if (!line)
		return (NULL);
	line[len] = '\0';
	i = 0;
	while (i < len)
	{
		line[i] = file->buff[i];
		i++;
	}
	return (line);
}

void	file_end(char *str, t_file *file)
{
	free(str);
	file->end = 1;
}
