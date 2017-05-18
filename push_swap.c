/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 16:21:44 by msrun             #+#    #+#             */
/*   Updated: 2017/02/03 17:18:06 by msrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_swap_tool	ft_print_best1bis(t_swap_tool tool, int *oc_tab, int *tab)
{
	while (tool.i >= (tool.nb + 1) * tool.split / tool.tmpnb)
	{
		if ((tool.attemp > tool.besttry[0] && tool.besttry[0] != -1)
				|| ft_check_order(tab, 0, tool.nb))
			break ;
		if (tab[tool.i] > oc_tab[(tool.nb + 1) * tool.split / tool.tmpnb])
		{
			if (tool.b)
			{
				write(1, ft_rr(tab, tool.i, tool.nb), 3);
				--tool.b;
			}
			else
				write(1, ft_ra(tab, tool.i), 3);
		}
		else
		{
			(tool.i % 2) ? tool.b = 1 : (void)tab;
			write(1, ft_pb(&tool.i), 3);
		}
	}
	return (tool);
}

t_swap_tool	ft_print_best1(t_swap_tool tool, int *oc_tab, int *tab)
{
	while (tool.split)
	{
		--tool.split;
		tool = ft_print_best1bis(tool, oc_tab, tab);
	}
	return (tool);
}

void		ft_print_best(t_swap_tool tool, int *oc_tab)
{
	int *tab;

	tab = 0;
	tool.b = 0;
	tool.tmpnb = tool.besttry[1];
	tool.split = tool.tmpnb - 1;
	tab = ft_get_nb(tool.ac, tool.av, tab, &(tool.nb));
	tool.nb--;
	tool.i = tool.nb;
	tool.attemp = 0;
	tool = ft_print_best1(tool, oc_tab, tab);
	tool = ft_print_best2(tool, oc_tab, tab);
	tool = ft_print_best3(tool, oc_tab, tab);
	tool = ft_print_best4(tool);
	free(tab);
}

int			main(int ac, char *av[])
{
	int			*oc_tab;
	int			nb;
	t_swap_tool	tool;

	oc_tab = 0;
	nb = 0;
	tool.av = av;
	tool.ac = ac;
	if (!(oc_tab = ft_get_nb(ac, av, oc_tab, &nb)))
		return (write(2, "Error\n", 6));
	ft_tab_oc(oc_tab, nb);
	if (ft_check_double(oc_tab, nb))
		return (write(2, "Error\n", 6));
	if (nb <= 1)
		return (0);
	if (ft_print_l(ac, av) > 0)
		return (0);
	tool.nb = nb;
	(ac < 9001) ? tool = ft_find_best(tool, oc_tab) : tool;
	(ac >= 9001) ? tool.besttry[1] = 54 : tool.besttry[1];
	if (tool.err == -1)
		return (0);
	ft_print_best(tool, oc_tab);
	free(oc_tab);
	return (0);
}
