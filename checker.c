/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 16:42:52 by msrun             #+#    #+#             */
/*   Updated: 2017/02/03 18:18:29 by msrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_check_ac3_1(char *s)
{
	int i;

	if (s[0] != 45 || (s[0] == 45 && !s[1]))
		return (-1);
	i = 0;
	while (s[++i])
		if (s[i] != 'v' && s[i] != 'c' && s[i] != 't' && s[i] != 'p')
			return (-1);
	if (ft_check_ac3_2(s, 45) == -1)
		return (-1);
	if (ft_check_ac3_2(s, 'v') == -1)
		return (-1);
	if (ft_check_ac3_2(s, 'c') == -1)
		return (-1);
	if (ft_check_ac3_2(s, 't') == -1)
		return (-1);
	if (ft_check_ac3_2(s, 'p') == -1)
		return (-1);
	return (0);
}

int	ft_check_ac3(char *s)
{
	int op;

	op = 0;
	if (ft_check_ac3_1(s) == -1)
		return (-1);
	if (ft_strchr(s, 'v'))
		op += 1;
	if (ft_strchr(s, 'c'))
		op += 2;
	if (ft_strchr(s, 't'))
		op += 4;
	if (ft_strchr(s, 'p'))
		op += 8;
	return (op);
}

int	ft_check1_ac(int ac, char *av[])
{
	int op;

	op = 0;
	if (ac == 1)
		return (-1);
	if (av[1][0] == '-' && (av[1][1] == 'v' || av[1][1] == 'c' ||
				av[1][1] == 't' || av[1][1] == 'p'))
	{
		if ((op = ft_check_ac3(av[1])) == -1)
		{
			write(2, "usage: checker [-vctp] [string]\n", 32);
			return (-1);
		}
	}
	return (op);
}

int	ft_check_doublenb(int ac, char **av)
{
	int	*oc_tab;
	int	nb;

	oc_tab = 0;
	if (!(oc_tab = ft_get_nbc(ac, av, oc_tab, &nb)))
		return (-1);
	ft_tab_oc(oc_tab, nb);
	if (ft_check_double(oc_tab, nb))
	{
		free(oc_tab);
		return (-1);
	}
	free(oc_tab);
	return (0);
}

int	main(int ac, char *av[])
{
	int	*tab;
	int len;
	int atp;
	int op;

	tab = 0;
	if ((op = ft_check1_ac(ac, av)) == -1)
		return (-1);
	if (!(tab = ft_get_nbc(ac, av, tab, &len)))
		return (ft_printf("Error\n"));
	atp = 0;
	if (ft_check_doublenb(ac, av) == -1)
		return (ft_printf("Error\n"));
	len--;
	ft_use_op_p(op);
	if ((atp = ft_use_op(tab, len, len, op)) == -1)
		return (ft_printf("\033[0mError\n"));
	if (op == 4 || op == 5 || op == 6 || op == 7 || op == 12 ||
			op == 13 || op == 14 || op == 15)
		ft_printf("Number of operations = %d\n", atp);
	free(tab);
	return (0);
}
