/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 15:27:41 by msrun             #+#    #+#             */
/*   Updated: 2016/11/18 12:24:32 by msrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *b, int c, size_t len)
{
	size_t				i;
	unsigned	char	convc;
	char				*strb;

	if (!b)
		return (NULL);
	convc = c;
	strb = b;
	i = 0;
	while (i < len)
	{
		strb[i] = convc;
		i++;
	}
	return (b);
}
