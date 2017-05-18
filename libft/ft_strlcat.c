/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 16:11:33 by msrun             #+#    #+#             */
/*   Updated: 2017/01/06 16:45:31 by msrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t			ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t len;
	size_t lens;

	if (!dst || !src)
		return (0);
	len = ft_strlen(dst);
	lens = ft_strlen(src);
	i = 0;
	while (i + len < size - 1 && src[i])
	{
		dst[i + len] = src[i];
		i++;
	}
	dst[i + len] = 0;
	if (size < len)
		return (lens + size);
	if (size < len + lens)
		return (len + lens);
	if (lens + len <= size)
		return (ft_strlen(src) + len);
	return (0);
}
