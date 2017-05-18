/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 15:10:00 by msrun             #+#    #+#             */
/*   Updated: 2017/01/13 17:56:19 by msrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>

# define BUFF_SIZE 100

int				get_next_line(const int fd, char **line);
int				ft_realloc(char **str, size_t size);

typedef struct	s_fd_buf
{
	char	*content;
	int		nb_fd;
}				t_fd_buf;

#endif
