/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 18:50:50 by msrun             #+#    #+#             */
/*   Updated: 2016/11/17 12:22:56 by msrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

static	int		ft_strncmp(const	char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] != 0 || s2[i] != 0) && i < n)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

static	size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char			*ft_strstr(const char *big, const char *little)
{
	size_t	i;

	i = 0;
	if (little[0] == 0)
		return ((char *)big);
	while (big[i])
	{
		if (big[i] == little[0])
		{
			if (ft_strncmp(big + i, little, ft_strlen(little)) == 0)
				return ((char *)big + i);
		}
		i++;
	}
	return (0);
}
