/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 16:31:29 by msrun             #+#    #+#             */
/*   Updated: 2017/01/19 18:45:47 by msrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** ordre croissant
*/

int			ft_check_order(int *tab, int pos, int len)
{
	int	i;

	i = pos - 1;
	while (++i < len)
		if (tab[i] < tab[i + 1])
		{
			--i;
			break ;
		}
	if (i == len)
		return (1);
	return (0);
}

int			ft_len_next_nb(int *tab, int oc_tab, int i, int len)
{
	int	pos;

	pos = i;
	while (tab[pos] != oc_tab)
		++pos;
	pos -= i;
	if (pos > (len - i) / 2)
		return (1);
	return (0);
}

int			ft_len_next_nb2(int *tab, int oc_tab, int i)
{
	int	pos;

	pos = 0;
	while (tab[pos] != oc_tab)
		++pos;
	if (pos > i / 2)
		return (1);
	return (0);
}

int			ft_next_nb3(int *tab, int min, int i)
{
	int	first;
	int	last;
	int	pos;

	pos = 0;
	while (tab[pos] < i)
	{
		if (tab[pos] > min)
		{
			first = pos;
			break ;
		}
		++pos;
	}
	while (tab[pos] < i)
	{
		if (tab[pos] > min)
			last = pos;
		++pos;
	}
	last = i - last;
	if (first > last)
		return (1);
	return (0);
}

t_swap_tool	ft_find_best4(t_swap_tool tool)
{
	while (tool.i < tool.nb)
	{
		if (tool.attemp > tool.besttry[0] && tool.besttry[0] != -1)
			break ;
		ft_pa(&tool.i, tool.nb);
		++tool.attemp;
	}
	if (tool.attemp < tool.besttry[0] || tool.besttry[0] == -1)
	{
		tool.besttry[0] = tool.attemp;
		tool.besttry[1] = tool.tmpnb;
	}
	return (tool);
}
