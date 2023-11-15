/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 20:02:02 by rde-mour          #+#    #+#             */
/*   Updated: 2023/11/15 17:33:43 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(int argc, char **argv)
{
	char		*gnl;
	int			fd;

	if (argc == 1)
		fd = 1;
	else
		fd = open(argv[1], O_RDONLY);
	if (fd < 1)
		return (0);
	gnl = get_next_line(fd);
	while (gnl)
	{
		printf("%s", gnl);
		if (gnl)
			free(gnl);
		gnl = get_next_line(fd);
	}
	if (fd > 1)
		close(fd);
	return (0);
}
