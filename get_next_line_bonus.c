/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 19:21:28 by rde-mour          #+#    #+#             */
/*   Updated: 2023/11/15 19:22:16 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*build_string(t_buffered **list)
{
	int			i;
	int			size;
	char		*str;
	t_buffered	*tmp;

	size = 0;
	tmp = *list;
	while (tmp && ++size && tmp -> character != '\n')
		tmp = tmp -> next;
	str = (char *) malloc(size + 1);
	if (!str)
		return (free_memory(&(*list)));
	i = 0;
	while (*list && i < size)
	{
		tmp = *list;
		*(str + i++) = (*list)-> character;
		*list = (*list)-> next;
		free(tmp);
	}
	*(str + i) = '\0';
	return (str);
}

static char	*read_next_line(t_data *file)
{
	ssize_t		i;

	i = 0;
	if ((file -> buffered && lstfind_character(file -> buffered, '\n')))
		return (build_string(&file -> buffered));
	file -> status = read(file -> fd, file -> buffer, BUFFER_SIZE);
	if (file -> status == -1 || file -> fd == -1)
		return (free_memory(&file -> buffered));
	i = 0;
	if (file -> status)
		while (i < file -> status)
			lstadd_back(&file -> buffered, lstnew(*(file -> buffer + i++)));
	if (file -> status)
		return (read_next_line(file));
	else if (file -> buffered)
		return (build_string(&file -> buffered));
	return (0);
}

char	*get_next_line(int fd)
{
	static t_data	file[1024];
	char			*str;

	if (fd < 0 || fd > 1023)
		return (0);
	file[fd].buffer = (char *) malloc(1 + BUFFER_SIZE * sizeof(char));
	if (!file[fd].buffer)
		return (free_memory(&file[fd].buffered));
	if (!file[fd].initiated)
	{
		file[fd].initiated = 'y';
		file[fd].fd = fd;
		file[fd].buffered = 0;
		file[fd].status = 0;
	}
	str = read_next_line(&file[fd]);
	if (!file[fd].buffered)
		file[fd].initiated = 0;
	free(file[fd].buffer);
	return (str);
}
