/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tool4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 14:43:04 by msrun             #+#    #+#             */
/*   Updated: 2016/12/29 16:55:57 by msrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_a_strchar_equal(int a, int strnb)
{
	if (a > 0)
	{
		a = (a - strnb);
		if (a < 0)
			return (0);
	}
	if (a < 0)
	{
		a = (a + strnb);
		if (a > 0)
			return (0);
	}
	return (a);
}

void	ft_if_diese(const char *s, unsigned long long i, int *lenp, int *b)
{
	if (ft_strchr(s, '#') && i)
	{
		*lenp += write(1, "0", 1);
		++(*b);
	}
	if (ft_strchr(s, '#') && i == 0 && ft_strchr(s, '.'))
	{
		*lenp += write(1, "0", 1);
		++(*b);
	}
}

int		ft_return_no_sp(const char *s)
{
	int i;

	i = 0;
	while (s[i] == 32)
		i++;
	return (i + 1);
}

/*
** Print les espaces ou 0 en fonction de la valeur de 'a'
*/

int		ft_print_whilea(int a, int *lenp)
{
	if (a > 0)
	{
		while (a > 0)
		{
			*lenp += write(1, "0", 1);
			a--;
		}
	}
	if (a < 0)
	{
		while (a < 0)
		{
			*lenp += write(1, " ", 1);
			a++;
		}
	}
	return (0);
}

int		ft_wstrlen(wchar_t *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[0])
	{
		if (str[0] < 127)
			++i;
		else if (str[0] < 2048)
			i += 2;
		else if (str[0] < 65536)
			i += 3;
		else if (str[0] < 2097152)
			i += 4;
		++str;
	}
	return (i);
}
