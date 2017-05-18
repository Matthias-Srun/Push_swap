/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 18:40:42 by msrun             #+#    #+#             */
/*   Updated: 2016/11/08 17:16:52 by msrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*buffdst;
	const char		*buffsrc;

	buffsrc = src;
	buffdst = dst;
	i = 0;
	while (i < n)
	{
		buffdst[i] = buffsrc[i];
		if (buffsrc[i] == c)
			return (dst + i + 1);
		i++;
	}
	return (0);
}
