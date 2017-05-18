/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 16:41:57 by msrun             #+#    #+#             */
/*   Updated: 2016/11/14 18:06:03 by msrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*news;

	i = 0;
	if (s)
	{
		news = (char *)malloc(sizeof(char) * len + 1);
		if (news)
		{
			while (i + start < start + (unsigned int)len)
			{
				news[i] = s[i + start];
				i++;
			}
			news[i] = 0;
			return (news);
		}
	}
	return (0);
}
