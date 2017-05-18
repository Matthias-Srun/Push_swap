/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 16:48:03 by msrun             #+#    #+#             */
/*   Updated: 2017/02/03 17:11:12 by msrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_print_cpile1(t_cpile tool, int pos)
{
	int	i;

	i = 0;
	while (pos + 1 + i <= tool.len || pos - i >= 0)
	{
		if ((pos + 1) - i == (tool.len + 1) - (pos + 1) ||
				(tool.len + 1) - (pos + 1) - i == (pos + 1))
		{
			ft_cprint_pile2(i, tool, pos);
			break ;
		}
		ft_cprint_pile3(i, tool, pos);
		++i;
	}
}

void	ft_print_pile(int *tab, int pos, int len, int *statab)
{
	static	t_cpile	tool;

	ft_printf("\033[0m");
	if (tool.pos == 0 && pos == len)
		tool.pos = len;
	tool.a = 0;
	tool.b = 0;
	tool.len = len;
	tool.tab = tab;
	tool.statab = statab;
	ft_print_cpile1(tool, pos);
	ft_printf("_____ _____\n  A     B\n");
	ft_printf("{red}");
	ft_fill_statab(statab, tab, len);
	tool.pos = pos;
}

void	ft_print_pile2(int *tab, int pos, int len, int i)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	while (pos + 1 + i <= len || pos - i >= 0)
	{
		if ((pos + 1) - i == (len + 1) - (pos + 1) ||
				(len + 1) - (pos + 1) - i == (pos + 1))
		{
			((pos + 1) > (len + 1) - (pos + 1)) ? a = i : (void)a;
			((pos + 1) < (len + 1) - (pos + 1)) ? b = i : (void)b;
			i = 0;
			while (pos - a - i >= 0 || pos + 1 + b + i <= len)
			{
				ft_printf("%-5d %5d\n", tab[pos - a - i], tab[pos + 1 + b + i]);
				i++;
			}
			break ;
		}
		(pos >= len - pos) ? ft_printf("%-5d      \n", tab[pos - i]) : i;
		(pos < len - pos) ? ft_printf("      %5d\n", tab[pos + 1 + i]) : i;
		++i;
	}
}

void	ft_op_v(int *tab, int y, int len)
{
	ft_printf("\033[0m");
	ft_printf("\n");
	ft_print_pile2(tab, y, len, 0);
	ft_printf("_____ _____\n  A     B  \n\n");
	ft_printf("{red}");
}

void	ft_op_vc(int *tab, int y, int len, int *statab)
{
	ft_printf("\n");
	ft_print_pile(tab, y, len, statab);
	ft_printf("\n");
}
