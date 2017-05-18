/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 16:34:36 by msrun             #+#    #+#             */
/*   Updated: 2017/01/24 16:35:12 by msrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_swap_tool	ft_find_best3(t_swap_tool tool, int *oc_tab, int *tab)
{
	tool.y = 0;
	while (!ft_check_order(tab, 0, tool.nb))
	{
		if (tool.attemp > tool.besttry[0] && tool.besttry[0] != -1)
			break ;
		if (ft_check_order(tab, 0, tool.nb) == 1)
			break ;
		if (!ft_len_next_nb(tab, oc_tab[tool.i + 1 - tool.y],
					tool.i + 1, tool.nb))
			tool = ft_find_best31(tool, oc_tab, tab);
		else
			tool = ft_find_best32(tool, oc_tab, tab);
		++tool.attemp;
	}
	return (tool);
}

t_swap_tool	ft_find_best2(t_swap_tool tool, int *oc_tab, int *tab)
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
				ft_ra(tab, tool.i);
			else
				ft_pb(&tool.i);
		}
		else
		{
			if (tab[tool.i] != oc_tab[tool.i])
				ft_rra(tab, tool.i);
			else
				ft_pb(&tool.i);
		}
		++tool.attemp;
	}
	return (tool);
}

t_swap_tool	ft_find_best1bis(t_swap_tool tool, int *oc_tab, int *tab)
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
				ft_rr(tab, tool.i, tool.nb);
				--tool.b;
			}
			else
				ft_ra(tab, tool.i);
		}
		else
		{
			(tool.i % 2) ? tool.b = 1 : (void)tab;
			ft_pb(&tool.i);
		}
		++tool.attemp;
	}
	return (tool);
}

t_swap_tool	ft_find_best1(t_swap_tool tool, int *oc_tab, int *tab)
{
	while (tool.split)
	{
		--tool.split;
		tool = ft_find_best1bis(tool, oc_tab, tab);
	}
	return (tool);
}

t_swap_tool	ft_find_best(t_swap_tool tool, int *oc_tab)
{
	int	*tab;

	tool.b = 0;
	tool.besttry[0] = -1;
	tool = ft_atmp_best(tool);
	tool.tmpnb = tool.tries;
	while (tool.tmpnb > tool.tmpminnb)
	{
		tool.split = tool.tmpnb - 1;
		if (!(tab = ft_get_nb(tool.ac, tool.av, tab, &(tool.nb))))
			tool.err = -1;
		if (tool.err == -1)
			return (tool);
		--tool.nb;
		tool.i = tool.nb;
		tool = ft_f_best(tool, oc_tab, tab);
		--tool.tmpnb;
		free(tab);
	}
	return (tool);
}
