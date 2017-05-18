/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 16:43:04 by msrun             #+#    #+#             */
/*   Updated: 2016/11/18 12:17:53 by msrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*buffdst;
	const char		*buffsrc;

	if (!dst || !src)
		return (NULL);
	buffsrc = src;
	buffdst = dst;
	i = 0;
	while (i < n)
	{
		buffdst[i] = buffsrc[i];
		i++;
	}
	return (dst);
}
