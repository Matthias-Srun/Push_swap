/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_op_int2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 13:17:12 by msrun             #+#    #+#             */
/*   Updated: 2016/12/28 13:17:49 by msrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_if_ui(const char *s, unsigned long long i, int a, int *lenp)
{
	if (i == 0)
		if (!(ft_strchr(s, '.') != 0 && ft_atoi(ft_strchr(s, '.') + 1) == 0))
		{
			(a > 0) ? ft_print_whilea(a, lenp) : (void)a;
			ft_print_conv_0(lenp);
		}
	if (i)
		*lenp += ft_putunbr(i);
}

void	ft_print_if_i(const char *s, long long i, int a, int *lenp)
{
	if (i == 0)
		if (!(ft_strchr(s, '.') != 0 && ft_atoi(ft_strchr(s, '.') + 1) == 0))
		{
			(a > 0) ? ft_print_whilea(a, lenp) : (void)a;
			ft_print_conv_0(lenp);
		}
	if (i)
		*lenp += ft_putnbr(i);
}
