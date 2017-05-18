/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap6.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 17:31:17 by msrun             #+#    #+#             */
/*   Updated: 2017/01/25 18:12:34 by msrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_swap_tool	ft_atmp_best(t_swap_tool tool)
{
	if (tool.nb > 9000)
	{
		tool.tries = 54;
		tool.tmpminnb = 53;
	}
	else
	{
		tool.tries = 35 + tool.nb / 500;
		tool.tmpminnb = 20 + tool.nb / 500;
	}
	if (tool.nb <= 3010)
	{
		tool.tries = 35;
		tool.tmpminnb = 20;
	}
	if (tool.nb <= 2010)
		tool.tmpminnb = 10;
	if (tool.nb <= 1000)
	{
		tool.tries = 30;
		tool.tmpminnb = 0;
	}
	return (tool);
}
