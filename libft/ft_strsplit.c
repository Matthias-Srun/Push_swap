/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 18:24:20 by msrun             #+#    #+#             */
/*   Updated: 2016/11/17 12:11:15 by msrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

static int	ft_nb_word(char const *str, char c)
{
	int i;
	int nbword;

	i = 0;
	nbword = 0;
	if (str[0] != c)
		nbword = 1;
	if (str[0] == 0)
		return (0);
	while (str[i])
	{
		if (str[i] == c && str[i + 1] != c && str[i + 1] != 0)
			nbword++;
		i++;
	}
	return (nbword);
}

static int	ft_len(const char *s, char c)
{
	int i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static char	*ft_word(char *wordsplit, char const *s, char c)
{
	int i;

	i = 0;
	while (s[i] != c && s[i] != 0)
	{
		wordsplit[i] = s[i];
		i++;
	}
	wordsplit[i] = 0;
	return (wordsplit);
}

static void	ft_fill(char const *s, char c, char **wordsplit)
{
	size_t	i;
	int		nbword;

	nbword = 0;
	i = 0;
	while (nbword < ft_nb_word(s, c))
	{
		while (s[i] == c && s[i] != 0)
			i++;
		if (s[i] != c)
		{
			wordsplit[nbword] = malloc(sizeof(char) * (ft_len(s + i, c)));
			wordsplit[nbword] = ft_word(wordsplit[nbword], s + i, c);
			nbword++;
		}
		while (s[i] != c && s[i] != 0)
			i++;
	}
	wordsplit[nbword] = 0;
}

char		**ft_strsplit(char const *s, char c)
{
	char	**wordsplit;

	if (s == NULL)
		return (NULL);
	wordsplit = (char **)malloc(sizeof(char*) * (ft_nb_word(s, c) + 1));
	if (wordsplit == 0)
		return (NULL);
	ft_fill(s, c, wordsplit);
	return (wordsplit);
}
