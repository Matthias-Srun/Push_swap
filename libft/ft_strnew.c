/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 13:53:58 by msrun             #+#    #+#             */
/*   Updated: 2016/11/12 13:33:09 by msrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char	*strmal;
	size_t	i;

	strmal = malloc(size + 1);
	i = 0;
	if (strmal)
	{
		while (i < size + 1)
		{
			strmal[i] = 0;
			i++;
		}
		return (strmal);
	}
	return (0);
}
