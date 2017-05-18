/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_op_convert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 16:48:17 by msrun             #+#    #+#             */
/*   Updated: 2016/12/29 16:46:25 by msrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**  Affichage d'un nombre en octal
*/

void	ft_op_o(const char *s, unsigned long long i, int *lenp)
{
	int		a;
	char	*nbstr;
	char	*tmp;
	int		b;

	tmp = ft_utoa(i);
	nbstr = ft_convert_base2(tmp, "0123456789", "01234567");
	ft_a_is(s, &b, &a);
	a = ft_a_str_equal(a, nbstr, s);
	ft_get_white_uspace(a, s, nbstr, lenp);
	ft_if_diese(s, i, lenp, &b);
	(a > 0) ? ft_print_whilea(a, lenp) : (void)a;
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

/*
** Affichage de l'addresse
*/

void	ft_use_nbradd(const char *s, unsigned long long i, int *lenp)
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
	*lenp += write(1, "0x", 2);
	b += 2;
	b += a + ft_strlen(nbstr);
	(a > 0 && i != 0) ? ft_print_whilea(a, lenp) : (void)a;
	if (i == 0)
		if (!(ft_strchr(s, '.') != 0 && ft_atoi(ft_strchr(s, '.') + 1) == 0))
		{
			(a > 0) ? ft_print_whilea(a - 1, lenp) : (void)a;
			ft_print_conv_0(lenp);
			++b;
		}
	*lenp += ft_putstr(nbstr);
	(b < 0) ? ft_print_whilea(b, lenp) : (void)a;
	free(nbstr);
	free(tmp);
}

/*
**  Covertion d'un nombre en binaire (le premier chiffre est le signe)
**  0 = positif, 1 = negatif
*/

void	ft_bin_switch(int i, char *nbstr)
{
	while (nbstr[++i] != 0)
		if (nbstr[i] == '1')
			nbstr[i] = '0';
		else if (nbstr[i] == '0')
			nbstr[i] = '1';
	while (--i >= 0)
		if (nbstr[i] == '0')
		{
			nbstr[i] = '1';
			break ;
		}
		else
			nbstr[i] = '0';
}

void	ft_nb_to_binary(long long nb, int *lenp)
{
	char	*nbstr;
	int		i;
	char	*tmp;

	tmp = ft_itoa(nb);
	i = 0;
	(nb < 0) ? write(1, "1", 1) : write(1, "0", 1);
	(nb < 0) ? i = -1 : (void)i;
	(nb < 0) ? nb = -nb : (void)i;
	nbstr = ft_convert_base(tmp, "0123456789", "01");
	if (i == -1)
		ft_bin_switch(i, nbstr);
	*lenp += ft_putstr(nbstr);
	free(nbstr);
	free(tmp);
}

/*
**  Convertion d'une chaine de carractere qui contient
**  le nombre, sa base, ainsi que la base dans laquel la convertir
*/

void	ft_nb_to_b(char *nbstr, int *lenp)
{
	char	**s;
	char	*tmp;

	s = ft_strsplit(nbstr, '|');
	tmp = ft_convert_base(s[0], s[1], s[2]);
	if (s && tmp)
	{
		*lenp += ft_putstr(tmp);
		free(tmp);
		free(s[0]);
		free(s[1]);
		free(s[2]);
		free(s);
	}
}
