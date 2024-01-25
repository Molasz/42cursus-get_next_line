/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molasz-a <molasz-a@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 12:11:20 by molasz-a          #+#    #+#             */
/*   Updated: 2024/01/25 18:21:30 by molasz-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

void	test(int fd)
{
	char	*s;

	s = get_next_line(fd);
	printf("(%d): %s|\n", fd, s);
	free(s);
}

int	main(void)
{
	int		test1;
	int		test2;
	int		test3;
	int		test4;
	int		test5;

	test1 = open("test/normal.txt", O_RDONLY);
	test2 = open("test/empty.txt", O_RDONLY);
	test3 = open("test/onlynl.txt", O_RDONLY);
	test4 = open("test/nonl.txt", O_RDONLY);
	test5 = open("test/1char.txt", O_RDONLY);
	test(test1);
	test(test1);
	test(test1);
	test(test2);
	test(test2);
	test(test2);
	test(test3);
	test(test3);
	test(test3);
	return (0);
}
