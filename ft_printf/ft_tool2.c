/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tool2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 17:02:38 by msrun             #+#    #+#             */
/*   Updated: 2016/12/28 13:25:56 by msrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_unbrlen(unsigned long long nb)
{
	int	i;

	i = 0;
	if (nb == 0)
		return (1);
	while (nb)
	{
		i++;
		nb /= 10;
	}
	return (i);
}

int			ft_putunbr(unsigned long long n)
{
	if (n / 10)
		ft_putnbr(n / 10);
	ft_putchar(n % 10 + 48);
	return (ft_unbrlen(n));
}

/*
** Gestion du '.'
*/

const char	*ft_strnbr(const char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '.')
			return (0);
		if (s[i] <= '9' && s[i] >= '1')
			return (s + i);
		i++;
	}
	return (0);
}

/*
** Gestion du flag 0
*/

char		*ft_str_0(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if ((s[i] <= '9' && s[i] >= '1') || s[i] == '.' || s[i] == '-')
			return (0);
		if (s[i] == '0')
			return ((char *)s + i);
		i++;
	}
	return (0);
}

/*
** Re calculation de 'a' en fonction de la taille de l'argument
*/

int			ft_a_str_equal(int a, char *strnb, const char *s)
{
	if (a > 0)
	{
		a = (a - ft_strlen(strnb));
		if (!ft_strchr(s, '.') && ft_str_0(s) != 0 &&
		ft_strchr(s, '#') && ft_atoi(strnb) && ((ft_strchr(s, 'x')
				|| ft_strchr(s, 'X'))))
			a -= 2;
		(ft_strchr(s, '#') && ft_strchr(s, 'o')) ? --a : (void)a;
		if (a < 0)
			return (0);
	}
	return (a);
}
