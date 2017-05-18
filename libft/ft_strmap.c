/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 15:31:06 by msrun             #+#    #+#             */
/*   Updated: 2016/11/17 12:16:13 by msrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
{
	char	*news;
	size_t	i;

	if (s)
	{
		news = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
		if (news)
		{
			i = 0;
			while (s[i])
			{
				news[i] = f((char)(s[i]));
				i++;
			}
			news[i] = 0;
			return (news);
		}
	}
	return (0);
}
