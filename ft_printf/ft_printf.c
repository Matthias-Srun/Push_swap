/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 13:26:36 by msrun             #+#    #+#             */
/*   Updated: 2016/12/29 13:07:31 by msrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check(const char *s, va_list arg, int *i)
{
	int	p;

	p = ft_strlen(s) - 1;
	if (s[p] == 'i' || s[p] == 'd' || s[p] == 'D')
		return (ft_check1(s, arg, i));
	if (s[p] == 'u' || s[p] == 'U')
		return (ft_check2(s, arg, i, p));
	if (s[p] == 'o' || s[p] == 'O')
		return (ft_check_o(s, arg, i));
	if (s[p] == 'x')
		return (ft_check_sx(s, arg, i));
	if (s[p] == 'X')
		return (ft_check_bx(s, arg, i));
	if (s[p] == 'b')
		return (ft_check4(s, arg, i));
	else
		return (ft_check5(s, arg, i));
}

/*
**	Compte jusqu'a une fonction
*/

int		ft_count(const char *s)
{
	int i;

	i = 0;
	while (s[0] && s[0] != 'd' && s[0] != 'i' && s[0] != 'o' && s[0] != 'x'
				&& s[0] != 'X' && s[0] != 'c' && s[0] != 'C' && s[0] != 's' &&
				s[0] != 'S' && s[0] != 'p' && s[0] != 'O' && s[0] != 'u' &&
				s[0] != 'U' && s[0] != '%' && s[0] != 'D' && s[0] != 'b' &&
				s[0] != 't' && s[0] != 'f' && s[0] != 'F' && s[0] != 'g' &&
				s[0] != 'G' && s[0] != 'e' && s[0] != 'E' && s[0] != 'n' &&
				s[0] != '%' && s[0] != 'k')
	{
		if ((s[0] < '0' || s[0] > '9') && s[0] != ' ' && s[0] != '+' && s[0]
		!= '-' && s[0] != '.' && s[0] != 'l' && s[0] != 'h' && s[0] != 'q' &&
		s[0] != 'z' && s[0] != 'j' && s[0] != '#')
			return (i + 1);
		++s;
		++i;
	}
	if (s[0] == 0)
		return (-2);
	++i;
	return (i);
}

/*
** Compte jusqu'qu prochain '}'
*/

int		ft_countbis(const char *s)
{
	int i;

	i = 0;
	while (s[0] && s[0] != '}')
	{
		++s;
		++i;
	}
	++i;
	if ((unsigned long long)i == ft_strlen(s))
		return (-10);
	return (i);
}

int		ft_do_print(const char *s, va_list arg, int *i)
{
	int		y;
	char	*tmp;

	if (s[0] == '{')
	{
		y = ft_countbis(s);
		if (!(tmp = ft_memalloc(y + 1)))
			return (0);
		ft_strncpy(tmp, s, y - 1);
		if (ft_color(tmp) == 0)
			return (0);
		free(tmp);
	}
	if (s[0] == '%')
	{
		y = ft_count(++s) + 1;
		if (y == -1)
			return (ft_return_no_sp(s));
		if (!(tmp = ft_memalloc(y)))
			return (0);
		ft_strncpy(tmp, s, y - 1);
		ft_check(tmp, arg, i);
		free(tmp);
	}
	return (y);
}

int		ft_printf(const char *s, ...)
{
	va_list	arg;
	int		i;

	i = 0;
	va_start(arg, s);
	while (s[0])
	{
		if (s[0] == '{' || s[0] == '%')
			s += ft_do_print(s, arg, &i);
		else
		{
			i += write(1, s, 1);
			++s;
		}
		if (s[0] == '{')
			i += write(1, "{", 1);
		if (s[0] == '{')
			++s;
	}
	va_end(arg);
	return (i);
}
