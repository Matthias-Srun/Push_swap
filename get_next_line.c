/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 11:20:07 by msrun             #+#    #+#             */
/*   Updated: 2017/01/17 17:41:56 by msrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"

/*
**	Remplace le \n par un 0 et retourne 1
*/

int		ft_replace(char **line, t_fd_buf buf)
{
	int i;

	i = 0;
	while (line[0][i])
	{
		if (line[0][i] == '\n')
		{
			line[0][i] = 0;
			ft_strcpy(buf.content, ft_strchr(buf.content, '\n') + 1);
			return (1);
		}
		i++;
	}
	return (0);
}

/*
** Libere la memoire et renvoie 1 si line n'est pas vide
*/

int		ft_free_mem(char **line, t_fd_buf *buf)
{
	ft_bzero(buf->content, BUFF_SIZE + 1);
	if (line[0][0] != 0)
		return (1);
	free(buf->content);
	buf->nb_fd = 0;
	return (0);
}

/*
** Boucle tant que read ne lit pas de \n
*/

int		ft_fill_line(char **line, t_fd_buf buf, int fd)
{
	int	ret;

	while ((ret = read(fd, buf.content, BUFF_SIZE)) > 0)
	{
		buf.content[ret] = 0;
		if ((ft_realloc(line, BUFF_SIZE)) == -1)
			return (-1);
		ft_strcat(line[0], buf.content);
		if (ft_replace(line, buf) == 1)
			return (1);
	}
	if (ret == -1)
		return (-1);
	return (0);
}

/*
** Trouve la case dans buf du fd correspondant
** ou bien l'alloue s'il ne l'est pas
*/

int		ft_find_or_fill(int fd, t_fd_buf *buf)
{
	int i;

	if ((i = -1) && fd == 0)
		if (buf[0].content == 0)
		{
			if (!(buf[0].content = ft_memalloc(BUFF_SIZE + 1)))
				return (-1);
			if ((read(fd, buf[0].content, BUFF_SIZE)) == -1)
				return (-1);
		}
	while (++i < 1024)
		if (buf[i].nb_fd == fd)
			return (i);
	i = 0;
	while (++i < 1024)
		if (buf[i].nb_fd == 0)
		{
			if (!(buf[i].content = ft_memalloc(BUFF_SIZE + 1)))
				return (-1);
			buf[i].nb_fd = fd;
			if ((read(fd, buf[i].content, BUFF_SIZE)) == -1)
				return (-1);
			return (i);
		}
	return (-1);
}

/*
** Alloue la memoire a buf si premiere entree dans la fonction
** puis alloue memoire a line et remplie line avec buf
*/

int		get_next_line(const int fd, char **line)
{
	static t_fd_buf	*buf = NULL;
	int				ret;
	int				i;

	if (fd < 0 || line == NULL || BUFF_SIZE < 1)
		return (-1);
	(!buf) ? (buf = ft_memalloc(sizeof(t_fd_buf) * 1024)) : (void)ret;
	if (!buf)
		return (-1);
	if ((i = ft_find_or_fill(fd, buf)) == -1)
		return (-1);
	if ((line[0] = ft_memalloc(BUFF_SIZE + 1)) == 0)
		return (-1);
	ft_strcat(line[0], buf[i].content);
	if (ft_replace(line, buf[i]) == 1)
		return (1);
	if ((ret = ft_fill_line(line, buf[i], fd)) == 1)
		return (1);
	if (ret == -1)
		return (-1);
	return (ft_free_mem(line, &buf[i]));
}
