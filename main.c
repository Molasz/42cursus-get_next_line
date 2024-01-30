/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 12:11:20 by molasz-a          #+#    #+#             */
/*   Updated: 2024/01/30 18:52:16 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

void	test(int fd)
{
	char	*s;

	s = get_next_line(fd);
	printf("(%d): %s|\n", fd, s);
	if (s)
		free(s);
}

int	main(int argc, char **argv)
{
	int	fd;

	if (argc > 1)
		fd = open(argv[1], O_RDONLY);
	else
		fd = open("test/empty.txt", O_RDONLY);
	test(fd);
	test(fd);
	test(fd);
	test(fd);
	return (0);
}
