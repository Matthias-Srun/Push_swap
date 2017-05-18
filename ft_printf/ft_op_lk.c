/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_op_ik.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 15:54:18 by msrun             #+#    #+#             */
/*   Updated: 2016/12/28 18:04:04 by msrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	Recup la date dans le tableau
*/

void	ft_op_lk_date(char *str, int *date)
{
	int	i;

	i = -1;
	while (++i < 8)
		date[i] = -24;
	i = -1;
	while (str[0] != 0 && ++i < 6)
	{
		date[i] = (int)ft_atoi(str);
		while (str[0] && ft_isdigit(str[0]) == 1)
			++str;
		while (str[0] && i < 5 && ft_isdigit(str[0]) == 0)
			++str;
	}
	if (str[0])
	{
		date[i] = (int)ft_atoi(str++);
		while (str[0] && ft_isdigit(str[0]) == 1)
			++str;
		++str;
		if (str[0])
			date[++i] = (int)ft_atoi(str);
	}
}

/*
** Gestion fuseau +
*/

void	ft_op_lk_tzp(int *date)
{
	if (date[3] >= 24)
	{
		++date[2];
		date[3] -= 24;
		if ((date[1] % 2 && date[2] > 31) || ((!((date[1]) % 2)) &&
		date[2] > 30) || (date[1] == 2 && date[0] % 4 && date[2] > 28) ||
				(date[1] == 2 && !(date[0] % 4) && date[2] > 29))
		{
			++date[1];
			if (date[1] > 12)
			{
				date[1] = 1;
				++date[0];
			}
			date[2] = 1;
		}
	}
}

/*
** Gestion fuseau -
*/

void	ft_op_lk_tzm(int *date)
{
	if (date[3] < 0)
	{
		--date[2];
		date[3] += 24;
		if (date[2] <= 0)
		{
			--date[1];
			if (date[1] <= 0)
			{
				date[1] = 12;
				--date[0];
			}
			(!(date[1] % 2) && date[1] != 2) ? date[2] += 30 : (void)date;
			(date[1] % 2) ? date[2] += 31 : (void)date;
			(date[1] == 2 && date[0] % 4) ? date[2] += 28 : (void)date;
			(date[1] == 2 && !(date[0] % 4)) ? date[2] += 29 : (void)date;
		}
	}
}

void	ft_op_lk_timez(int *date)
{
	if (date[6] || date[7])
	{
		date[4] += date[7];
		if (date[4] < 0)
		{
			--date[3];
			date[4] += 60;
			ft_op_lk_tzm(date);
		}
		if (date[4] >= 60)
		{
			++date[3];
			date[4] -= 60;
			ft_op_lk_tzp(date);
		}
		date[3] += date[6];
		ft_op_lk_tzm(date);
		ft_op_lk_tzp(date);
	}
}

/*
** Recupere la date dans "date" et calcule ensuite en fonction du fuseau
*/

void	ft_op_lk(char *str, int *lenp)
{
	int date[8];

	if (!str)
		return ((void)0);
	ft_op_lk_date(str, date);
	(date[7] == -24) ? date[7] = 0 : (void)str;
	(date[6] == -24) ? date[6] = 0 : (void)str;
	(str[19] == 45) ? date[7] *= -1 : (void)str;
	ft_op_lk_timez(date);
	ft_op_lka(date, lenp);
}
