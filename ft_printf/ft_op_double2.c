/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_op_double2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 16:44:41 by msrun             #+#    #+#             */
/*   Updated: 2016/12/22 14:21:46 by msrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**  Putnbr pour float
*/

void	ft_putnbr_spec(long nb, int *lenp)
{
	char	*s;
	int		nb0;
	int		i;

	i = -1;
	nb0 = 0;
	s = ft_itoa((long long)nb);
	s++;
	while (s[++i])
		if (s[i] == '0')
			++nb0;
		else
			break ;
	while (nb0--)
	{
		*lenp += 1;
		write(1, "0", 1);
	}
	if (ft_atoi(s))
		*lenp += ft_putnbr(ft_atoi(s));
	free(--s);
}

/*
**  Affiche le nombre sans les 0 a la fin
*/

int		ft_putnbr_wo_0(long long nb)
{
	char		i[ft_nbrlen(nb) + 1];
	int			y;
	long long	tmp;

	tmp = nb;
	y = ft_nbrlen(nb) - 1;
	i[y + 1] = 0;
	while (nb)
	{
		i[y] = (int)(nb % 10 + '0');
		--y;
		nb /= 10;
	}
	y = ft_nbrlen(tmp) - 1;
	while (y >= 0 && i[y] == '0')
	{
		i[y] = 0;
		y--;
	}
	ft_putstr(i);
	return (ft_strlen(i));
}

void	ft_putnbr_spec2(long nb, int *lenp)
{
	char	*s;
	int		nb0;
	int		i;

	i = -1;
	nb0 = 0;
	s = ft_itoa((long long)nb);
	s++;
	while (s[++i])
		if (s[i] == '0')
			++nb0;
		else
			break ;
	(ft_atoi(s)) ? *lenp += 1 : (void)i;
	(ft_atoi(s)) ? ft_putchar('.') : (void)i;
	while (nb0--)
	{
		*lenp += 1;
		write(1, "0", 1);
	}
	(ft_atoi(s)) ? *lenp += ft_putnbr_wo_0(ft_atoi(s)) : (void)i;
}

/*
** Fonction pour 'f' et 'F'
*/

void	ft_op_f(double nb, int *lenp)
{
	double	ftmp;
	long	dtmp;

	(nb < 0) ? write(1, "-", 1) : (void)nb;
	(nb < 0) ? *lenp += 1 : (void)nb;
	(nb < 0) ? nb = -nb : (void)nb;
	dtmp = (long)nb;
	ftmp = nb - (double)dtmp + 1;
	ftmp = (ftmp * 100000000);
	dtmp = (long)ftmp;
	if (dtmp % 100 >= 50)
	{
		dtmp = dtmp / 100;
		dtmp++;
	}
	else
		dtmp = dtmp / 100;
	*lenp += ft_putnbr((long)nb) + 1;
	ft_putchar('.');
	ft_putnbr_spec(dtmp, lenp);
}
