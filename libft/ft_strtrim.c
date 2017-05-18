/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 17:27:45 by msrun             #+#    #+#             */
/*   Updated: 2016/11/16 17:49:07 by msrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_len(const char *s)
{
	int i;
	int len;

	i = 0;
	len = 0;
	while (len == 0 && s[i])
	{
		if (s[i] != ' ' && s[i] != '\n' && s[i] != '\t')
			len++;
		i++;
	}
	while (s[i])
	{
		len++;
		i++;
	}
	while ((s[i] == 0 || s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && len)
	{
		len--;
		i--;
	}
	len++;
	return (len);
}

char		*ft_strtrim(char const *s)
{
	int		i;
	int		y;
	int		len;
	char	*str;

	if (s == NULL)
		return (NULL);
	len = ft_len(s);
	str = (char *)malloc(sizeof(char) * len + 1);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	y = 0;
	while (y < len)
		str[y++] = s[i++];
	str[y] = 0;
	return (str);
}
