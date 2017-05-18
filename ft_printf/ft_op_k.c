/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_op_k.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 14:46:07 by msrun             #+#    #+#             */
/*   Updated: 2016/12/28 18:09:06 by msrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_op_kj(int *date, int *lenp)
{
	(date[2] > 0) ? *lenp += ft_printf("%04d", date[2]) : (void)date;
	(date[1] > 0) ? *lenp += ft_printf("-%02d", date[1]) : (void)date;
	(date[0] > 0) ? *lenp += ft_printf("-%02d", date[0]) : (void)date;
	(date[3] > 0) ? *lenp += ft_printf("T%02d", date[3]) : (void)date;
	(date[4] > 0) ? *lenp += ft_printf(":%02d", date[4]) : (void)date;
	(date[5] > 0) ? *lenp += ft_printf(":%02dZ", date[5]) : (void)date;
}

void	ft_op_ka(int *date, int *lenp)
{
	(date[0] > 0) ? *lenp += ft_printf("%04d", date[0]) : (void)date;
	(date[1] > 0) ? *lenp += ft_printf("-%02d", date[1]) : (void)date;
	(date[2] > 0) ? *lenp += ft_printf("-%02d", date[2]) : (void)date;
	(date[3] > 0) ? *lenp += ft_printf("T%02d", date[3]) : (void)date;
	(date[4] > 0) ? *lenp += ft_printf(":%02d", date[4]) : (void)date;
	(date[5] > 0) ? *lenp += ft_printf(":%02dZ", date[5]) : (void)date;
}

/*
**	Stockage de la date
*/

void	ft_op_k_date(char *str, int *date)
{
	int	i;

	i = -1;
	while (++i < 6)
		date[i] = -1;
	i = 0;
	while (!ft_isdigit(str[0]))
		++str;
	while (str[0] != 0 && i < 6)
	{
		date[i] = (int)ft_atoi(str);
		while (str[0] && ft_isdigit(str[0]) == 1)
			++str;
		while (str[0] && ft_isdigit(str[0]) == 0)
			++str;
		++i;
	}
}

/*
**	Date et heure convertie ISO aaaa-mm-jjThh:mi:ssZ
*/

void	ft_op_k(char *str, int *lenp)
{
	int date[6];

	ft_op_k_date(str, date);
	if (!str)
		return ((void)0);
	if (ft_nbrlen(date[0]) == 2)
		ft_op_kj(date, lenp);
	if (ft_nbrlen(date[0]) == 4)
		ft_op_ka(date, lenp);
}
