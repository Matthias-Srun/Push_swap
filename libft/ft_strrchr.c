/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 18:38:52 by msrun             #+#    #+#             */
/*   Updated: 2016/11/17 12:21:06 by msrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static	int	ft_strlen(const char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char		*ft_strrchr(const char *s, int c)
{
	int i;
	int len;

	len = ft_strlen(s);
	i = 0;
	while (len - i + 1)
	{
		if (s[len - i] == c)
			return ((char *)s + (len - i));
		i++;
	}
	return (0);
}
