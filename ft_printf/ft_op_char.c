/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_op_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 16:55:05 by msrun             #+#    #+#             */
/*   Updated: 2016/12/29 16:58:35 by msrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Affichage d'une chaine de carractere
*/

void	ft_use_str(const char *s, char *str, int *lenp)
{
	int	a;
	int b;

	a = 0;
	b = ft_strlen(str);
	(ft_str_0(s) != 0) ? a = ft_atoui(ft_str_0(s) + 1) : (void)a;
	if (ft_strchr(s, '.') != 0)
		((unsigned long long)(b = (int)ft_atoi(ft_strchr(s, '.')
				+ 1)) > ft_strlen(str)) ? b = ft_strlen(str) : (void)a;
	if (ft_strchr(s, '.') != 0 && !str)
		((unsigned long long)(b = (int)ft_atoi(ft_strchr(s, '.')
				+ 1)) > 6) ? b = 6 : (void)a;
	(ft_strchr(s, '-') != 0) ? a = -ft_atoui(ft_strnbr(s)) : (void)a;
	a = ft_a_strchar_equal(a, b);
	ft_get_white_strspace(a, s, b, lenp);
	(a > 0) ? ft_print_whilea(a, lenp) : (void)a;
	(!str && ft_strchr(s, '.')) ? (*lenp += write(1, "(null)", b)) : (void)a;
	(!str && !ft_strchr(s, '.')) ? (*lenp += write(1, "(null)", 6)) : (void)a;
	(str) ? *lenp += ft_putnchar(str, b) : (void)a;
	(a < 0) ? ft_print_whilea(a, lenp) : (void)a;
}

/*
**  Affichage d'un carractere
*/

void	ft_use_char(const char *s, int str, int *lenp)
{
	int a;
	int b;

	a = 0;
	b = 1;
	(ft_str_0(s) != 0) ? a = ft_atoui(ft_str_0(s) + 1) : (void)a;
	(ft_strchr(s, '-') != 0) ? a = -ft_atoui(ft_strnbr(s)) : (void)a;
	a = ft_a_strchar_equal(a, b);
	ft_get_white_strspace(a, s, b, lenp);
	(a > 0) ? ft_print_whilea(a, lenp) : (void)a;
	*lenp += write(1, &str, 1);
	(a < 0) ? ft_print_whilea(a, lenp) : (void)a;
}

void	ft_op_prct(const char *s, int *lenp)
{
	int	a;
	int b;

	a = 0;
	b = 1;
	(ft_str_0(s) != 0) ? a = ft_atoui(ft_str_0(s) + 1) : (void)a;
	if (ft_strchr(s, '.') != 0 && (ft_strchr(s, '.') + 1)[0] >= '0' &&
			(ft_strchr(s, '.') + 1)[0] <= '9')
		((b = ft_atoi(ft_strchr(s, '.') + 1)) > 1) ?
			b = 1 : (void)a;
	(ft_strchr(s, '-') != 0) ? a = -ft_atoui(ft_strnbr(s)) : (void)a;
	a = ft_a_strchar_equal(a, b);
	ft_get_white_strspace(a, s, b, lenp);
	(a > 0) ? ft_print_whilea(a, lenp) : (void)a;
	*lenp += write(1, "%", 1);
	(a < 0) ? ft_print_whilea(a, lenp) : (void)a;
}

void	ft_use_lchar(wint_t c, int *lenp)
{
	int b;

	b = -1;
	if (c > 127)
		ft_print_wchar(c, lenp, &b);
	else
		*lenp += write(1, &c, 1);
}

void	ft_random_char(const char *s, int *lenp)
{
	int	a;
	int	b;

	a = 0;
	b = 1;
	(ft_str_0(s) != 0) ? a = ft_atoui(ft_str_0(s) + 1) : (void)a;
	(ft_strchr(s, '-') != 0) ? a = -ft_atoui(ft_strnbr(s)) : (void)a;
	a = ft_a_strchar_equal(a, b);
	ft_get_white_strspace(a, s, b, lenp);
	(a > 0) ? ft_print_whilea(a, lenp) : (void)a;
	ft_putchar(s[ft_strlen(s) - 1]);
	*lenp += 1;
	(a < 0) ? ft_print_whilea(a, lenp) : (void)a;
}
