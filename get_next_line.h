/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 19:17:23 by rde-mour          #+#    #+#             */
/*   Updated: 2024/03/16 10:03:22 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2048 
# endif

typedef struct s_string
{
	int				character;
	struct s_string	*next;
}					t_buffered;

enum	e_end
{
	NEW_LINE,
	END_LINE
};

char		*get_next_line(int fd);
char		*gnl_lstclear(t_buffered **list);
void		gnl_lstadd_back(t_buffered **list, int character);
int			gnl_lstfind_character(t_buffered *list, int character, int eof);

#endif
