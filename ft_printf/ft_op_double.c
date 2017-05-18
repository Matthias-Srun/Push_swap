/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_op_double.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 16:40:55 by msrun             #+#    #+#             */
/*   Updated: 2016/12/21 17:15:11 by msrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Fonction pour 'e' et 'E'
*/

void	ft_op_e2(const char *s, double nb, int *lenp)
{
	double	ftmp;
	long	dtmp;
	int		e;

	e = ft_nbrlen((long)nb);
	while (nb > 10)
		nb /= 10;
	ftmp = (nb - (long)nb + 1) * 100000000;
	dtmp = (long)ftmp;
	if (dtmp % 100 >= 50)
	{
		dtmp = dtmp / 100;
		dtmp++;
	}
	else
		dtmp = dtmp / 100;
	ft_putchar((ft_itoa((long)nb))[0]);
	ft_putchar('.');
	ft_putnbr_spec(dtmp, lenp);
	(s[0] == 'e') ? write(1, "e+", 2) : (void)e;
	(s[0] == 'E') ? write(1, "E+", 2) : (void)e;
	(e < 10) ? write(1, "0", 1) : (void)e;
	*lenp += ft_putnbr(e - 1) + 5;
}

void	ft_op_e(const char *s, double nb, int *lenp)
{
	if (nb < 0)
	{
		write(1, "-", 1);
		*lenp += 1;
		nb = -nb;
	}
	ft_op_e2(s, nb, lenp);
}

/*
** Fonction pour 'G' et 'g' si le float est grand
*/

void	ft_ge6(const char *s, double nb, int *lenp, int e)
{
	double	ftmp;
	long	dtmp;

	while (nb > 10)
		nb /= 10;
	ftmp = (nb - (long)nb + 1) * 10000000;
	dtmp = (long)ftmp;
	if (dtmp % 100 >= 50)
	{
		dtmp = dtmp / 100;
		dtmp++;
	}
	else
		dtmp = dtmp / 100;
	ft_putchar((ft_itoa((long)nb))[0]);
	ft_putchar('.');
	ft_putnbr_spec(dtmp, lenp);
	(s[0] == 'g') ? write(1, "e+", 2) : (void)e;
	(s[0] == 'G') ? write(1, "E+", 2) : (void)e;
	(e < 10) ? write(1, "0", 1) : (void)e;
	*lenp += ft_putnbr(e - 1) + 5;
}

/*
** Fonction pour 'G' et 'g' si le float est petit
*/

void	ft_ge0(double nb, int *lenp, int e)
{
	double	ftmp;
	long	dtmp;

	ftmp = (nb - (long)nb + 1) * (10000000);
	dtmp = (long)ftmp;
	if (dtmp % (10 * ft_power(10, e)) >= (5 * ft_power(10, e)))
	{
		dtmp = dtmp / (10 * ft_power(10, e));
		dtmp++;
	}
	else
		dtmp = dtmp / (10 * ft_power(10, e));
	*lenp += ft_putnbr((long long)nb);
	if (dtmp / 10 * ft_power(10, e) - ft_power(10, 6 - e))
		ft_putnbr_spec2(dtmp, lenp);
}

/*
** Fonction pour 'G' et 'g'
*/

void	ft_op_g(const char *s, double nb, int *lenp)
{
	if (nb < 0)
	{
		*lenp += 1;
		write(1, "-", 1);
		nb = -nb;
	}
	if (ft_nbrlen((long)nb) > 6)
		ft_ge6(s, nb, lenp, ft_nbrlen((long)nb));
	else
		ft_ge0(nb, lenp, ft_nbrlen((long)nb));
}
