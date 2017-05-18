/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 16:03:48 by msrun             #+#    #+#             */
/*   Updated: 2016/11/17 12:16:47 by msrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char))
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
				news[i] = f(i, (char)(s[i]));
				i++;
			}
			news[i] = 0;
			return (news);
		}
	}
	return (0);
}
