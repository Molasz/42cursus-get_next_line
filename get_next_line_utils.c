/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 11:40:24 by molasz-a          #+#    #+#             */
/*   Updated: 2024/01/24 17:27:45 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_file	*get_file(int fd)
{
	static t_file	*files = NULL;
	t_file			*lst;

	if (files)
	{
		lst = files;
		while (lst)
		{
			if (lst->fd == fd)
				return (lst);
			lst = lst->next;
		}
	}
	lst = malloc(sizeof (t_file));
	if (!lst)
		return (NULL);
	lst->fd = fd;
	if (files)
		lst->next = files;
	files = lst;
	return (lst);
}

void	read_buffer(t_file *file)
{
	if (file->buffer)
	{

	}
	else
	{
		if (read(file->fd, file->buffer, BUFFER_SIZE) < 0)
			return (NULL);
	}
}
