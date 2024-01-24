/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 11:39:30 by molasz-a          #+#    #+#             */
/*   Updated: 2024/01/24 17:26:11 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	t_file	*file;

	file = get_file(fd);
	if (!file)
		return (NULL);
	
	return (NULL);
}

int	main(void)
{
	get_next_line(4);
	get_next_line(2);
	get_next_line(4);
	get_next_line(3);
	return (0);
}
