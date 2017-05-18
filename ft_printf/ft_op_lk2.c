/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_op_ik2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 17:56:13 by msrun             #+#    #+#             */
/*   Updated: 2016/12/28 18:01:39 by msrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_pmonth(int month, int *lenp)
{
	(month == 1) ? *lenp += write(1, "janvier", 7) : (void)lenp;
	(month == 2) ? *lenp += write(1, "fevrier", 7) : (void)lenp;
	(month == 3) ? *lenp += write(1, "mars", 4) : (void)lenp;
	(month == 4) ? *lenp += write(1, "avril", 5) : (void)lenp;
	(month == 5) ? *lenp += write(1, "mai", 3) : (void)lenp;
	(month == 6) ? *lenp += write(1, "juin", 4) : (void)lenp;
	(month == 7) ? *lenp += write(1, "juillet", 7) : (void)lenp;
	(month == 8) ? *lenp += write(1, "aout", 4) : (void)lenp;
	(month == 9) ? *lenp += write(1, "septembre", 9) : (void)lenp;
	(month == 10) ? *lenp += write(1, "octobre", 7) : (void)lenp;
	(month == 11) ? *lenp += write(1, "novembre", 8) : (void)lenp;
	(month == 12) ? *lenp += write(1, "decembre", 8) : (void)lenp;
}

void	ft_op_lka(int *date, int *lenp)
{
	(date[2] > -24) ? *lenp += ft_printf("%02d ", date[2]) : (void)date;
	(date[1] > -24) ? ft_pmonth(date[1], lenp) : (void)date;
	(date[0] > -24) ? *lenp += ft_printf(" %04d", date[0]) : (void)date;
	(date[3] > -24) ? *lenp += ft_printf(" %01d H", date[3]) : (void)date;
	(date[4] > -24) ? *lenp += ft_printf(" %02d min", date[4]) : (void)date;
	(date[5] > -24) ? *lenp += ft_printf(" %02d sec", date[5]) : (void)date;
}
