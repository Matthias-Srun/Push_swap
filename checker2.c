/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 16:45:02 by msrun             #+#    #+#             */
/*   Updated: 2017/01/24 12:45:03 by msrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		ft_use_op2(int *tab, char *line, int len, int y)
{
	if (!ft_strcmp(line, "sa"))
		ft_sa(tab, y);
	else if (!ft_strcmp(line, "sb"))
		ft_sb(tab, y, len);
	else if (!ft_strcmp(line, "ss"))
		ft_ss(tab, y, len);
	else if (!ft_strcmp(line, "pb"))
		ft_pb(&y);
	else if (!ft_strcmp(line, "pa"))
		ft_pa(&y, len);
	else if (!ft_strcmp(line, "ra"))
		ft_ra(tab, y);
	else if (!ft_strcmp(line, "rb"))
		ft_rb(tab, y, len);
	else if (!ft_strcmp(line, "rr"))
		ft_rr(tab, y, len);
	else if (!ft_strcmp(line, "rra"))
		ft_rra(tab, y);
	else if (!ft_strcmp(line, "rrb"))
		ft_rrb(tab, y, len);
	else if (!ft_strcmp(line, "rrr"))
		ft_rrr(tab, y, len);
	else
		return (-3);
	return (y);
}

int		ft_check_tab(int *tab, int len, int y)
{
	int	i;

	i = 0;
	ft_printf("\033[0m");
	while (i < len)
	{
		if (tab[i] < tab[i + 1])
		{
			write(1, "KO\n", 3);
			return (-1);
		}
		i++;
	}
	if (y == len)
		write(1, "OK\n", 3);
	else
	{
		write(1, "KO\n", 3);
		return (-1);
	}
	return (0);
}

void	ft_fill_statab(int *statab, int *tab, int len)
{
	int	i;

	i = 0;
	while (i < len + 1)
	{
		statab[i] = tab[i];
		i++;
	}
}

void	ft_cprint_pile2(int i, t_cpile tool, int pos)
{
	((pos + 1) > (tool.len + 1) - (pos + 1)) ? tool.a = i : (void)tool.a;
	((pos + 1) < (tool.len + 1) - (pos + 1)) ? tool.b = i : (void)tool.b;
	i = -1;
	while ((pos - tool.a - ++i >= 0 || pos + 1 + tool.b + i <= tool.len))
	{
		if (pos > tool.pos && i == 0 && tool.a == 0)
			ft_printf("\033[32m");
		(tool.tab[pos - tool.a - i] == tool.statab[pos - tool.a - i]) ?
			ft_printf("%-5d ", tool.tab[pos - tool.a - i]) :
			ft_printf("\033[32m%-5d\033[0m ", tool.tab[pos - tool.a - i]);
		ft_printf("\033[0m");
		if (pos < tool.pos && i == 0 && tool.b == 0)
			ft_printf("\033[32m");
		(tool.tab[pos + 1 + tool.b + i] == tool.statab[pos + 1 + tool.b + i]) ?
			ft_printf("%5d\n", tool.tab[pos + 1 + tool.b + i]) :
			ft_printf("\033[32m%5d\033[0m\n", tool.tab[pos + 1 + tool.b + i]);
		ft_printf("\033[0m");
	}
}

void	ft_cprint_pile3(int i, t_cpile tool, int pos)
{
	if (pos >= tool.len - pos)
	{
		if (pos > tool.pos && i == 0)
			ft_printf("\033[32m");
		(tool.tab[pos - i] == tool.statab[pos - i]) ?
			ft_printf("%-5d      \n", tool.tab[pos - i]) :
			ft_printf("\033[32m%-5d\033[0m      \n", tool.tab[pos - i]);
		ft_printf("\033[0m");
	}
	if (pos < tool.len - pos)
	{
		if (pos < tool.pos && i == 0)
			ft_printf("\033[32m");
		(tool.tab[pos + 1 + i] == tool.statab[pos + 1 + i]) ?
			ft_printf("      %5d\n", tool.tab[pos + 1 + i]) :
			ft_printf("      \033[32m%5d\033[0m\n", tool.tab[pos + 1 + i]);
		ft_printf("\033[0m");
	}
}
