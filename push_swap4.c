/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 16:36:59 by msrun             #+#    #+#             */
/*   Updated: 2017/01/23 12:45:32 by msrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_swap_tool	ft_print_best31(t_swap_tool tool, int *oc_tab, int *tab)
{
	if (tool.i + 2 < tool.nb && tool.y == 0)
		if (tab[tool.i + 1] == oc_tab[tool.i + 2 - tool.y2])
		{
			write(1, ft_pa(&tool.i, tool.nb), 3);
			tool.y = 1;
		}
	if (tab[tool.i + 1] != oc_tab[tool.i + 1 - tool.y - tool.y2])
		write(1, ft_rb(tab, tool.i, tool.nb), 3);
	else
	{
		write(1, ft_pa(&tool.i, tool.nb), 3);
		if (tool.y == 1)
		{
			tool.y = 0;
			write(1, ft_sa(tab, tool.i), 3);
		}
	}
	return (tool);
}

t_swap_tool	ft_print_best32(t_swap_tool tool, int *oc_tab, int *tab)
{
	if (tool.i + 2 < tool.nb && tool.y == 0)
		if (tab[tool.i + 1] == oc_tab[tool.i + 2 - tool.y2])
		{
			write(1, ft_pa(&tool.i, tool.nb), 3);
			tool.y = 1;
		}
	if (tab[tool.i + 1] != oc_tab[tool.i + 1 - tool.y - tool.y2])
		write(1, ft_rrb(tab, tool.i, tool.nb), 4);
	else
	{
		write(1, ft_pa(&tool.i, tool.nb), 3);
		if (tool.y == 1)
		{
			tool.y = 0;
			write(1, ft_sa(tab, tool.i), 3);
		}
	}
	return (tool);
}

t_swap_tool	ft_print_best33(t_swap_tool tool, int *oc_tab, int *tab)
{
	if (tool.nb >= 90 && tool.i + 2 < tool.nb)
	{
		if (tab[tool.i + 1] != oc_tab[tool.i + 1 - tool.y - tool.y2]
				&& tab[tool.i + 1] != oc_tab[tool.i + 2 - tool.y - tool.y2]
				&& (tab[tool.i + 1] > tab[0] || !tool.y2) &&
				tab[0] != oc_tab[tool.i + 1 - tool.y - tool.y2])
		{
			++tool.y2;
			write(1, ft_pa(&tool.i, tool.nb), 3);
			write(1, ft_ra(tab, tool.i), 3);
		}
	}
	while (tab[0] == oc_tab[tool.i + 1 - tool.y2] && tool.y2)
	{
		write(1, ft_rra(tab, tool.i), 4);
		--tool.y2;
	}
	return (tool);
}

t_swap_tool	ft_print_best3(t_swap_tool tool, int *oc_tab, int *tab)
{
	tool.y = 0;
	tool.y2 = 0;
	while (!ft_check_order(tab, 0, tool.nb))
	{
		if (ft_check_order(tab, 0, tool.nb) == 1)
			break ;
		tool = ft_print_best33(tool, oc_tab, tab);
		if (ft_check_order(tab, 0, tool.nb) == 1)
			break ;
		if (!ft_len_next_nb(tab, oc_tab[tool.i + 1 - tool.y - tool.y2],
					tool.i + 1, tool.nb))
			tool = ft_print_best31(tool, oc_tab, tab);
		else
			tool = ft_print_best32(tool, oc_tab, tab);
	}
	return (tool);
}

t_swap_tool	ft_print_best2(t_swap_tool tool, int *oc_tab, int *tab)
{
	while (tool.i > 0)
	{
		if (tool.attemp > tool.besttry[0] && tool.besttry[0] != -1)
			break ;
		if (ft_check_order(tab, 0, tool.nb) == 1)
			break ;
		if (ft_len_next_nb2(tab, oc_tab[tool.i], tool.i))
		{
			if (tab[tool.i] != oc_tab[tool.i])
				write(1, ft_ra(tab, tool.i), 3);
			else
				write(1, ft_pb(&tool.i), 3);
		}
		else
		{
			if (tab[tool.i] != oc_tab[tool.i])
				write(1, ft_rra(tab, tool.i), 4);
			else
				write(1, ft_pb(&tool.i), 3);
		}
	}
	return (tool);
}
