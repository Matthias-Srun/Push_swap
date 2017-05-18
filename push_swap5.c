/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 13:49:17 by msrun             #+#    #+#             */
/*   Updated: 2017/01/24 16:31:25 by msrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_swap_tool	ft_find_best31(t_swap_tool tool, int *oc_tab, int *tab)
{
	if (tool.i + 2 < tool.nb && tool.y == 0)
		if (tab[tool.i + 1] == oc_tab[tool.i + 2])
		{
			tool.y = 1;
			ft_pa(&tool.i, tool.nb);
		}
	if (tab[tool.i + 1] != oc_tab[tool.i + 1 - tool.y])
		ft_rb(tab, tool.i, tool.nb);
	else
	{
		ft_pa(&tool.i, tool.nb);
		if (tool.y == 1)
		{
			tool.y = 0;
			ft_sa(tab, tool.i);
		}
	}
	return (tool);
}

t_swap_tool	ft_find_best32(t_swap_tool tool, int *oc_tab, int *tab)
{
	if (tool.i + 2 < tool.nb && tool.y == 0)
		if (tab[tool.i + 1] == oc_tab[tool.i + 2])
		{
			tool.y = 1;
			ft_pa(&tool.i, tool.nb);
		}
	if (tab[tool.i + 1] != oc_tab[tool.i + 1 - tool.y])
		ft_rrb(tab, tool.i, tool.nb);
	else
	{
		ft_pa(&tool.i, tool.nb);
		if (tool.y == 1)
		{
			tool.y = 0;
			ft_sa(tab, tool.i);
		}
	}
	return (tool);
}

int			ft_print_l(int ac, char **av)
{
	int	*tab;
	int	nb;

	tab = 0;
	nb = 0;
	if (!(tab = ft_get_nb(ac, av, tab, &nb)))
		return (write(2, "Error\n", 6));
	if (nb != 3)
	{
		free(tab);
		return (0);
	}
	if (tab[2] > tab[1] && tab[2] > tab[0])
		write(1, ft_ra(tab, 2), 3);
	if (tab[1] > tab[0] && tab[1] > tab[2])
		write(1, ft_rra(tab, 2), 4);
	if (tab[2] > tab[1])
		write(1, ft_sa(tab, 2), 3);
	free(tab);
	return (1);
}

t_swap_tool	ft_print_best4(t_swap_tool tool)
{
	while (tool.i < tool.nb)
	{
		if (tool.attemp > tool.besttry[0] && tool.besttry[0] != -1)
			break ;
		write(1, ft_pa(&tool.i, tool.nb), 3);
	}
	if (tool.attemp < tool.besttry[0] || tool.besttry[0] == -1)
	{
		tool.besttry[0] = tool.attemp;
		tool.besttry[1] = tool.tmpnb;
	}
	return (tool);
}

t_swap_tool	ft_f_best(t_swap_tool tool, int *oc_tab, int *tab)
{
	tool.attemp = 0;
	tool = ft_find_best1(tool, oc_tab, tab);
	tool = ft_find_best2(tool, oc_tab, tab);
	tool = ft_find_best3(tool, oc_tab, tab);
	tool = ft_find_best4(tool);
	return (tool);
}
