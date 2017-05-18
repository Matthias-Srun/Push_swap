/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 17:36:07 by msrun             #+#    #+#             */
/*   Updated: 2016/11/18 12:19:36 by msrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*buffs1;
	const unsigned char	*buffs2;

	if (!s1 || !s2)
		return (0);
	buffs1 = s1;
	buffs2 = s2;
	i = 0;
	while (i < n)
	{
		if (buffs1[i] != buffs2[i])
			return (buffs1[i] - buffs2[i]);
		i++;
	}
	return (0);
}
