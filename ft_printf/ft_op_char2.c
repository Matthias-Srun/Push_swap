/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_op_char2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 12:18:25 by msrun             #+#    #+#             */
/*   Updated: 2016/12/29 17:02:01 by msrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_wchar2(long long nb, int *lenp, int *b)
{
	if (b > 0 && !(*b - 1 && *b - 1 - 1 && *b - 1 - 1 - 1))
		return ((void)(*b = 0));
	(*b) ? *b -= ft_putchar(nb / 262144 + 240) : (void)b;
	(*b) ? *b -= ft_putchar(nb % 262144 / 4096 + 128) : (void)b;
	(*b) ? *b -= ft_putchar(nb % 262144 % 4096 / 64 + 128) : (void)b;
	(*b) ? *b -= ft_putchar(nb % 262144 % 4096 % 64 + 128) : (void)b;
	return ((void)(*lenp += 4));
}

void	ft_print_wchar(long long nb, int *lenp, int *b)
{
	if (nb < 2048)
	{
		if (b > 0 && !(*b - 1))
			return ((void)(*b = 0));
		(*b) ? *b -= ft_putchar(nb / 64 + 192) : (void)b;
		(*b) ? *b -= ft_putchar(nb % 64 + 128) : (void)b;
		return ((void)(*lenp += 2));
	}
	if (nb < 65536)
	{
		if (b > 0 && !(*b - 1 && *b - 1 - 1))
			return ((void)(*b = 0));
		(*b) ? *b -= ft_putchar(nb / 4096 + 224) : (void)b;
		(*b) ? *b -= ft_putchar(nb % 4096 / 64 + 128) : (void)b;
		(*b) ? *b -= ft_putchar(nb % 4096 % 64 + 128) : (void)b;
		return ((void)(*lenp += 3));
	}
	if (nb < 2097152)
		ft_print_wchar2(nb, lenp, b);
}

void	ft_use_lstr2(const char *s, wchar_t *str, int *lenp, int b)
{
	int	i;

	i = 0;
	if (ft_strchr(s, '.') != 0)
		b = (int)ft_atoi(ft_strchr(s, '.') + 1);
	while (str[i] && b)
	{
		if (str[i] > 127)
			ft_print_wchar(str[i], lenp, &b);
		else
		{
			ft_putchar(str[i]);
			--b;
			*lenp += 1;
		}
		i++;
	}
}

int		ft_wstr_canbeprint(int b, wchar_t *str)
{
	int	i;

	i = -1;
	if (!str)
		return (0);
	while (str[++i] && b > 0)
	{
		if (str[i] < 127)
			--b;
		else if (str[i] < 2048)
			b -= 2;
		else if (str[i] < 65536)
			b -= 3;
		else if (str[i] < 2097152)
			b -= 4;
	}
	if (!str[i] || str[i - 1] < 127)
		return (0);
	if (str[i - 1] < 2048)
		return (2 + b);
	if (str[i - 1] < 65536)
		return (3 + b);
	if (str[i - 1] < 2097152)
		return (4 + b);
	return (0);
}

void	ft_use_lstr(const char *s, wchar_t *str, int *lenp)
{
	int	a;
	int	b;

	a = 0;
	b = ft_wstrlen(str);
	(ft_str_0(s) != 0) ? a = ft_atoui(ft_str_0(s) + 1) : (void)a;
	if (ft_strchr(s, '.') != 0)
		((b = (int)ft_atoi(ft_strchr(s, '.')
			+ 1)) > ft_wstrlen(str)) ? b = ft_wstrlen(str) : (void)a;
	if (ft_strchr(s, '.') != 0 && !str)
		((b = (int)ft_atoi(ft_strchr(s, '.') + 1)) > 6)
			? b = 6 : (void)a;
	(ft_strchr(s, '-') != 0) ? a = -ft_atoui(ft_strnbr(s)) : (void)a;
	(b) ? b -= ft_wstr_canbeprint(b, str) : (void)a;
	a = ft_a_strchar_equal(a, b);
	ft_get_white_strspace(a, s, b, lenp);
	(a > 0) ? ft_print_whilea(a, lenp) : (void)a;
	(!str && ft_strchr(s, '.')) ? (*lenp += write(1, "(null)", b)) : (void)a;
	(!str && !ft_strchr(s, '.')) ? (*lenp += write(1, "(null)", 6)) : (void)a;
	(str) ? ft_use_lstr2(s, str, lenp, b) : (void)a;
	(a < 0) ? ft_print_whilea(a, lenp) : (void)a;
}
