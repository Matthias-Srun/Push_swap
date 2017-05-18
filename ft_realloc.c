/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 13:03:47 by msrun             #+#    #+#             */
/*   Updated: 2017/01/14 14:06:16 by msrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdlib.h>

int	ft_realloc(char **str, size_t size)
{
	char	tmp[ft_strlen(*str) + 1];
	size_t	i;

	i = ft_strlen(*str) + size + 1;
	ft_strcpy(tmp, *str);
	free(*str);
	if (!(*str = ft_memalloc(i)))
		return (-1);
	ft_strcpy(*str, tmp);
	str[0][i] = 0;
	return (0);
}
