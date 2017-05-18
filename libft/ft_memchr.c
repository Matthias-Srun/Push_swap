/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 17:17:12 by msrun             #+#    #+#             */
/*   Updated: 2016/11/18 12:18:52 by msrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t					i;
	const unsigned char		*buffs;
	unsigned char			buffc;

	if (s == NULL && n == 0)
		return (NULL);
	buffs = s;
	buffc = c;
	i = 0;
	while (buffs[i] && i < n)
	{
		if (buffs[i] == buffc)
			return ((void *)s + i);
		i++;
	}
	if (buffs[i] == c && c == 0)
		return ((void*)s + i);
	return (0);
}
