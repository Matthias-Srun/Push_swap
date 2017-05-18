/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 16:19:00 by msrun             #+#    #+#             */
/*   Updated: 2016/11/18 12:13:02 by msrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*strb;

	if (s)
	{
		strb = s;
		i = 0;
		while (i < n)
		{
			strb[i] = 0;
			i++;
		}
	}
}