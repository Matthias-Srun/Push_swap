/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 13:50:25 by msrun             #+#    #+#             */
/*   Updated: 2016/11/17 12:17:23 by msrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char		*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	y;

	i = 0;
	y = ft_strlen(s1);
	while (i < n && s2[i])
	{
		s1[y + i] = s2[i];
		i++;
	}
	s1[y + i] = 0;
	return (s1);
}
