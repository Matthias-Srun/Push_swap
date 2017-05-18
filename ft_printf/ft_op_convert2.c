/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_op_convert2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 14:03:50 by msrun             #+#    #+#             */
/*   Updated: 2016/12/28 13:12:07 by msrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**  Affichage d'un nombre en hexa/HEXA
*/

void	ft_op_sx(const char *s, unsigned long long i, int *lenp)
{
	int		a;
	char	*nbstr;
	char	*tmp;
	int		b;

	tmp = ft_utoa(i);
	nbstr = ft_convert_base2(tmp, "0123456789", "0123456789abcdef");
	ft_a_is(s, &b, &a);
	a = ft_a_str_equal(a, nbstr, s);
	ft_get_white_uspace(a, s, nbstr, lenp);
	(ft_strchr(s, '#') && i != 0) ? *lenp += write(1, "0x", 2) : (void)a;
	(ft_strchr(s, '#') && i != 0) ? b += 2 : (void)a;
	(a > 0 && i != 0) ? ft_print_whilea(a, lenp) : (void)a;
	if (i == 0)
		if (!(ft_strchr(s, '.') != 0 && ft_atoi(ft_strchr(s, '.') + 1) == 0))
		{
			(a > 0) ? ft_print_whilea(a - 1, lenp) : (void)a;
			ft_print_conv_0(lenp);
			++b;
		}
	*lenp += ft_putstr(nbstr);
	b += a + ft_strlen(nbstr);
	(b < 0) ? ft_print_whilea(b, lenp) : (void)a;
	free(nbstr);
	free(tmp);
}

void	ft_op_bx(const char *s, unsigned long long i, int *lenp)
{
	int		a;
	char	*nbstr;
	char	*tmp;
	int		b;

	tmp = ft_utoa(i);
	nbstr = ft_convert_base2(tmp, "0123456789", "0123456789ABCDEF");
	ft_a_is(s, &b, &a);
	a = ft_a_str_equal(a, nbstr, s);
	ft_get_white_uspace(a, s, nbstr, lenp);
	(ft_strchr(s, '#') && i != 0) ? *lenp += write(1, "0X", 2) : (void)a;
	(ft_strchr(s, '#') && i != 0) ? b += 2 : (void)a;
	(a > 0 && i != 0) ? ft_print_whilea(a, lenp) : (void)a;
	if (i == 0)
		if (!(ft_strchr(s, '.') != 0 && ft_atoi(ft_strchr(s, '.') + 1) == 0))
		{
			(a > 0) ? ft_print_whilea(a - 1, lenp) : (void)a;
			ft_print_conv_0(lenp);
			++b;
		}
	*lenp += ft_putstr(nbstr);
	b += a + ft_strlen(nbstr);
	(b < 0) ? ft_print_whilea(b, lenp) : (void)a;
	free(nbstr);
	free(tmp);
}

void	ft_print_conv_0(int *lenp)
{
	write(1, "0", 1);
	*lenp += 1;
}
