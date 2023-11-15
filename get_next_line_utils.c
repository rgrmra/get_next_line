/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 19:37:59 by rde-mour          #+#    #+#             */
/*   Updated: 2023/11/15 17:48:38 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_buffered	*lstnew(char character)
{
	t_buffered	*new;

	new = (t_buffered *) malloc(1 * sizeof(t_buffered));
	if (!new)
		return (0);
	new -> character = character;
	new -> next = 0;
	return (new);
}

t_buffered	*lstlast(t_buffered *list)
{
	if (!list)
		return (0);
	while (list -> next != 0)
		list = list -> next;
	return (list);
}

void	lstadd_back(t_buffered **list, t_buffered *new)
{
	if (!list || !new)
		return ;
	if (!(*list))
		*list = new;
	else
		lstlast(*list)->next = new;
}

int	lstfind_character(t_buffered *list, char character)
{
	while (list)
	{
		if (list -> character == character)
			return (1);
		list = list -> next;
	}
	return (0);
}

char	*free_memory(t_buffered **list)
{
	t_buffered	*tmp;

	while (*list)
	{
		tmp = *list;
		*list = (*list)-> next;
		free(tmp);
	}
	return (0);
}
