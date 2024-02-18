/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 19:17:23 by rde-mour          #+#    #+#             */
/*   Updated: 2024/02/18 19:07:05 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

typedef struct s_string
{
	int				character;
	struct s_string	*next;
}					t_buffered;

char		*gnl_free_memory(t_buffered **list);
char		*get_next_line(int fd);
void		gnl_lstadd_back(t_buffered **list, t_buffered *new);
int			gnl_lstfind_character(t_buffered *list, int character);
t_buffered	*gnl_lstlast(t_buffered *list);
t_buffered	*gnl_lstnew(int character);

#endif
