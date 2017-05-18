/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checking2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 16:07:47 by msrun             #+#    #+#             */
/*   Updated: 2016/12/29 14:22:41 by msrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check6(const char *s, va_list arg, int *i)
{
	int p;

	p = ft_strlen(s) - 1;
	if (s[p] == 't')
		return (ft_nb_to_b(va_arg(arg, char*), i));
	if (s[p] == 'f' || s[p] == 'F')
		return (ft_op_f(va_arg(arg, double), i));
	if (s[p] == 'e' || s[p] == 'E')
		return (ft_op_e(s, va_arg(arg, double), i));
	if (s[p] == 'g' || s[p] == 'G')
		return (ft_op_g(s, va_arg(arg, double), i));
	if (s[p] == 'n')
		return (ft_op_n(va_arg(arg, int*), i));
	if (s[p - 1] == 'l' && s[p] == 'k')
		return (ft_op_lk(va_arg(arg, char*), i));
	if (s[p] == 'k')
		return (ft_op_k(va_arg(arg, char*), i));
	ft_random_char(s, i);
}

void	ft_check5(const char *s, va_list arg, int *i)
{
	int p;

	p = ft_strlen(s) - 1;
	if (s[p] == 'p')
		return (ft_use_nbradd(s, va_arg(arg, unsigned long long), i));
	if ((s[p - 1] == 'l' && s[p] == 's') || s[p] == 'S')
		return (ft_use_lstr(s, va_arg(arg, wchar_t*), i));
	if (s[p] == 's')
		return (ft_use_str(s, va_arg(arg, char*), i));
	if ((s[p - 1] == 'l' && s[p] == 'c') || s[p] == 'C')
		return (ft_use_lchar(va_arg(arg, wint_t), i));
	if (s[p] == 'c')
		return (ft_use_char(s, va_arg(arg, int), i));
	if (s[p] == '%')
		return (ft_op_prct(s, i));
	ft_check6(s, arg, i);
}
