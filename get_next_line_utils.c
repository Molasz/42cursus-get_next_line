/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 11:40:24 by molasz-a          #+#    #+#             */
/*   Updated: 2024/01/25 00:26:48 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	char *res;
	int		i;

	i = 0;
	res = malloc(sizeof (char) * ((ft_strlen(s1) + ft_strlen(s2) + 1)));	
	if (!res)
		return (NULL);
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	while (s2[i])
	{
		res[i] = s2[i];
		i++;
	}
	if (s2)
		free(s2);
	res[i] = '\0';
	return (res);
}

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
	lst->line = 0;
	lst->end = 0;
	lst->buff = NULL;
	lst->next = NULL;
	if (files)
		lst->next = files;
	files = lst;
	return (lst);
}
