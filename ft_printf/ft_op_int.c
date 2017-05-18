/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_op_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 16:52:42 by msrun             #+#    #+#             */
/*   Updated: 2016/12/28 13:21:49 by msrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**  Fonction pour 'n'
*/

void	ft_op_n(int *nb, int *lenp)
{
	*nb = *lenp;
}

/*
** Affichage d'un unsigned
*/

void	ft_use_u_nbr(const char *s, unsigned long long i, int *lenp)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	if (ft_str_0(s) != 0)
		a = ft_atoui(ft_str_0(s) + 1);
	if (ft_strchr(s, '-') != 0)
		b = -ft_atoui(ft_strnbr(s));
	if (ft_strchr(s, '.'))
		a = ft_atoui(ft_strchr(s, '.') + 1);
	a = ft_a_equal_to(a, i);
	ft_get_ui_white_space(a, s, i, lenp);
	b += a + ft_nbrlen(i);
	(a > 0 && i) ? ft_print_whilea(a, lenp) : (void)a;
	ft_print_if_ui(s, i, a, lenp);
	(b < 0) ? ft_print_whilea(b, lenp) : (void)a;
}

/*
** Affichage d'un nombre signed
*/

void	ft_if_i_neg(long long *i, int *lenp, int *b)
{
	*lenp += write(1, "-", 1);
	++(*b);
	*i = -(*i);
}

void	ft_use_signed_nbr(const char *s, long long i, int *lenp)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	if (i == -4611686018427387904 * 2)
		return ((void)(*lenp += write(1, "-9223372036854775808", 20)));
	(ft_strchr(s, ' ') && i >= 0 && ft_strchr(s, '+') == 0) ?
		*lenp += write(1, " ", 1) : (void)a;
	a = ft_ia_is(s, i, &b);
	(ft_strchr(s, ' ') && i >= 0 && !ft_strchr(s, '+') &&
	!ft_strchr(s, '.')) ? --a : (void)a;
	if (ft_strchr(s, '+') != 0 && i >= 0)
		a = ft_thereisplus(s, i, a, lenp);
	a = ft_a_equal_to(a, i);
	ft_get_white_space(a, s, i, lenp);
	(i >= 0 && ft_strchr(s, '+')) ? write(1, "+", 1) : (void)i;
	(i >= 0 && ft_strchr(s, '+')) ? ++b : (void)i;
	b += a + ft_nbrlen(i);
	(i < 0) ? ft_if_i_neg(&i, lenp, &b) : (void)a;
	(a > 0 && i) ? ft_print_whilea(a, lenp) : (void)a;
	ft_print_if_i(s, i, a, lenp);
	(b < 0) ? ft_print_whilea(b, lenp) : (void)a;
}
