/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 13:17:24 by msrun             #+#    #+#             */
/*   Updated: 2016/11/18 12:26:03 by msrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char		*ft_strcat(char *s1, const char *s2)
{
	size_t	i;
	size_t	y;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	y = ft_strlen(s1);
	while (s2[i])
	{
		s1[y + i] = s2[i];
		i++;
	}
	s1[y + i] = 0;
	return (s1);
}
