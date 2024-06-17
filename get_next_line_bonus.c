/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 19:21:28 by rde-mour          #+#    #+#             */
/*   Updated: 2024/06/17 20:19:48 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*gnl_build_string(t_buffered **list)
{
	int			i;
	int			size;
	char		*str;
	t_buffered	*tmp;

	if (!list || !(*list))
		return (NULL);
	size = gnl_lstfind_character(*list, '\n', END_LINE);
	str = (char *) malloc(sizeof(char) * size);
	if (!str)
		return (gnl_lstclear(list));
	i = 0;
	tmp = *list;
	while (--size)
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
	if (gnl_lstfind_character(file->buffered, '\n', NEW_LINE))
		return (gnl_build_string(&file->buffered));
	file -> status = read(file->fd, file->buffer, BUFFER_SIZE);
	if (file->status < 0)
		return (gnl_lstclear(&file->buffered));
	i = 0;
	while (i < file->status)
		gnl_lstadd_back(&file->buffered, *(file->buffer + i++));
	if (!file->status)
		return (gnl_build_string(&file->buffered));
	return (read_next_line(file));
}

static char	*gnl_lstclear_all(t_data file[])
{
	size_t	i;

	if (!file)
		return (NULL);
	i = 0;
	while (i < 1024)
	{
		if (file[i].buffered)
			gnl_lstclear(&file[i].buffered);
		i++;
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static t_data	file[1024];
	char			*str;

	if (fd < 0 || fd > 1023)
		return (gnl_lstclear_all(file));
	file[fd].buffer = (char *) malloc(BUFFER_SIZE * sizeof(char));
	if (!file[fd].buffer)
		return (gnl_lstclear_all(file));
	file[fd].fd = fd;
	str = read_next_line(&file[fd]);
	if (file[fd].buffer)
		free(file[fd].buffer);
	return (str);
}
