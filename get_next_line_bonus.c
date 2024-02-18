/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 19:21:28 by rde-mour          #+#    #+#             */
/*   Updated: 2024/02/18 19:38:49 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*gnl_build_string(t_buffered **list)
{
	int			i;
	int			size;
	char		*str;
	t_buffered	*tmp;

	size = 0;
	tmp = *list;
	while (tmp && ++size && tmp->character != '\n')
		tmp = tmp -> next;
	str = (char *) malloc(sizeof(char) + size);
	if (!str)
		return (gnl_free_memory(list));
	i = 0;
	while (*list && i < size)
	{
		tmp = *list;
		*(str + i++) = (*list)->character;
		*list = (*list)->next;
		free(tmp);
	}
	*(str + i) = '\0';
	return (str);
}

static char	*read_next_line(t_data *file)
{
	ssize_t		i;

	i = 0;
	if ((file->buffered && gnl_lstfind_character(file->buffered, '\n')))
		return (gnl_build_string(&file->buffered));
	while (i < BUFFER_SIZE)
		*(file->buffer + i++) = 0;
	file -> status = read(file -> fd, file->buffer, BUFFER_SIZE);
	if (file->status == -1 || file->fd == -1)
		return (gnl_free_memory(&file->buffered));
	i = 0;
	if (file -> status)
		while (i < file->status)
			gnl_lstadd_back(&file->buffered, gnl_lstnew(*(file->buffer + i++)));
	if (file -> status)
		return (read_next_line(file));
	else if (file->buffered)
		return (gnl_build_string(&file->buffered));
	return (0);
}

static char	*gnl_free_all_memory(t_data file[])
{
	size_t	i;

	i = 0;
	while (file && i < 1024)
	{
		if (file[i].buffered)
			gnl_free_memory(&file[i].buffered);
		i++;
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static t_data	file[1024];
	char			*str;

	if (fd < 0 || fd > 1023)
		return (gnl_free_all_memory(file));
	file[fd].buffer = (char *) malloc(1 + BUFFER_SIZE * sizeof(char));
	if (!file[fd].buffer)
		return (gnl_free_all_memory(file));
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
	if (file[fd].buffer)
		free(file[fd].buffer);
	return (str);
}
