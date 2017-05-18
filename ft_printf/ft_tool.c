/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tool.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 16:58:19 by msrun             #+#    #+#             */
/*   Updated: 2016/12/28 13:23:56 by msrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Re calculation de 'a' en fonction de la taille de l'argument
*/

int		ft_a_equal_to(int a, long long i)
{
	if (a > 0)
	{
		a -= ft_nbrlen(i);
		if (a < 0)
			return (0);
	}
	return (a);
}

/*
** Gestion du flag '+', affiche un '+' si le nombre est positif ou 0
*/

int		ft_thereisplus(const char *s, long long i, int a, int *lenp)
{
	if (i >= 0)
		*lenp += 1;
	if (!(ft_strchr(s, '.') != 0 && (ft_strchr(s, '.') + 1)[0] >= '0' &&
				(ft_strchr(s, '.') + 1)[0] <= '9'))
	{
		if (a < 0)
			a++;
		if (a > 0)
			a--;
	}
	return (a);
}

/*
** Affiche les espaces moins la longueur de nb
*/

void	ft_get_white_space(int a, const char *s, long long nb, int *lenp)
{
	int	i;
	int	nbsp;

	i = 0;
	while (s[i])
	{
		if (s[i] == '.' || s[i] == '-')
			break ;
		if (s[i] >= '1' && s[i] <= '9')
		{
			nbsp = ft_atoi(s + i) - ft_nbrlen(nb);
			(!nb && ft_strchr(s, '.') != 0 && ft_atoi(ft_strchr(s, '.')
			+ 1) == 0) ? ++nbsp : (void)a;
			if (ft_strchr(s, '+') != 0 || nb < 0 || ft_strchr(s, ' ') != 0)
				--nbsp;
			ft_print_wsp(a, nbsp, lenp);
			break ;
		}
		i++;
	}
}

void	ft_get_ui_white_space(int a, const char *s,
		unsigned long long nb, int *lenp)
{
	int	i;
	int	nbsp;

	i = 0;
	while (s[i])
	{
		if (s[i] == '.' || s[i] == '-')
			break ;
		if (s[i] >= '1' && s[i] <= '9')
		{
			nbsp = ft_atoui(s + i) - ft_unbrlen(nb);
			(!nb && ft_strchr(s, '.') != 0 && ft_atoui(ft_strchr(s, '.')
			+ 1) == 0) ? ++nbsp : (void)a;
			ft_print_wsp(a, nbsp, lenp);
			break ;
		}
		i++;
	}
}

/*
** Affiche les espaces moins la longueur de nb
*/

void	ft_get_white_uspace(int a, const char *s, char *nb, int *lenp)
{
	int	i;
	int	nbsp;

	i = 0;
	while (s[i])
	{
		if (s[i] == '.' || s[i] == '-')
			break ;
		if (s[i] >= '0' && s[i] <= '9')
		{
			nbsp = ft_atoi(s + i) - (int)ft_strlen(nb);
			if (ft_atoi(nb) == 0)
				if (!(ft_strchr(s, '.') != 0 &&
							ft_atoi(ft_strchr(s, '.') + 1) == 0))
					--nbsp;
			(s[ft_strlen(s) - 1] == 'p' || (ft_atoi(nb) &&
			ft_strchr(s, '#') && ((ft_strchr(s, 'x') ||
			ft_strchr(s, 'X'))))) ? nbsp -= 2 : (void)a;
			(ft_strchr(s, '#') && (ft_strchr(s, 'o'))) ? --nbsp : (void)a;
			ft_print_wsp(a, nbsp, lenp);
			break ;
		}
		i++;
	}
}
