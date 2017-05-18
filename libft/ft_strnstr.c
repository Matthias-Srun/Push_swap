/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 12:47:50 by msrun             #+#    #+#             */
/*   Updated: 2016/11/17 12:20:03 by msrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char		*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t i;

	i = 0;
	if (little[0] == 0)
		return ((char *)big);
	while (big[i] && i < len)
	{
		if (big[i] == little[0])
		{
			if (ft_strncmp(big + i, little, ft_strlen(little)) == 0 &&
					i + ft_strlen(little) < len + 1)
				return ((char *)big + i);
		}
		i++;
	}
	return (0);
}
