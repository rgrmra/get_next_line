/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 19:21:28 by rde-mour          #+#    #+#             */
/*   Updated: 2024/02/18 19:19:47 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	str = (char *) malloc(size + 1);
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

char	*get_next_line(int fd)
{
	ssize_t				i;
	ssize_t				status;
	static char			buffer[BUFFER_SIZE];
	static t_buffered	*list;

	if (fd == -1)
		return (gnl_free_memory(&list));
	if (list && gnl_lstfind_character(list, '\n'))
		return (gnl_build_string(&list));
	status = read(fd, buffer, BUFFER_SIZE);
	if (status == -1 || fd == -1)
		return (gnl_free_memory(&list));
	i = 0;
	if (status)
		while (i < status)
			gnl_lstadd_back(&list, gnl_lstnew(*(buffer + i++)));
	if (status && list)
		return (get_next_line(fd));
	else if (list)
		return (gnl_build_string(&list));
	return (0);
}
