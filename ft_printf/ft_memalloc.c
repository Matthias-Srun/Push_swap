/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 18:17:12 by msrun             #+#    #+#             */
/*   Updated: 2016/12/29 13:08:30 by msrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_memalloc(size_t size)
{
	void	*addmalloc;
	char	*charmem;
	size_t	i;

	i = 0;
	addmalloc = malloc(size);
	charmem = addmalloc;
	if (!addmalloc)
		return (0);
	while (i < size)
	{
		charmem[i] = 0;
		i++;
	}
	return (addmalloc);
}
