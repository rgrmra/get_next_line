/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 19:17:23 by rde-mour          #+#    #+#             */
/*   Updated: 2023/11/15 15:20:11 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

typedef struct s_string
{
	char			character;
	struct s_string	*next;
}					t_buffered;

char		*free_memory(t_buffered **list);
char		*get_next_line(int fd);
void		lstadd_back(t_buffered **list, t_buffered *new);
int			lstfind_character(t_buffered *list, char character);
t_buffered	*lstlast(t_buffered *list);
t_buffered	*lstnew(char character);

#endif
