/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 18:38:18 by msrun             #+#    #+#             */
/*   Updated: 2016/11/15 17:17:35 by msrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				i;
	unsigned char		*bd;
	const unsigned char	*bs;

	bd = dst;
	bs = src;
	if (bd > bs)
	{
		i = 0;
		while (i < len)
		{
			bd[len - i - 1] = bs[len - i - 1];
			i++;
		}
	}
	if (bs > bd)
	{
		i = 0;
		while (i < len)
		{
			bd[i] = bs[i];
			i++;
		}
	}
	return (dst);
}
