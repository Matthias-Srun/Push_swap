/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_op_pile2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 18:53:30 by msrun             #+#    #+#             */
/*   Updated: 2017/01/18 18:54:50 by msrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_rra(int *tab, int y)
{
	int	tmp;
	int	cpt;

	if (y > 0)
	{
		cpt = -1;
		tmp = tab[0];
		while (++cpt < y)
			tab[cpt] = tab[cpt + 1];
		tab[y] = tmp;
	}
	return ("rra\n");
}

char	*ft_rrb(int *tab, int y, int len)
{
	int	tmp;
	int	cpt;

	if (y + 1 < len)
	{
		cpt = len + 1;
		tmp = tab[len];
		while (--cpt > y + 1)
			tab[cpt] = tab[cpt - 1];
		tab[y + 1] = tmp;
	}
	return ("rrb\n");
}

char	*ft_rrr(int *tab, int y, int len)
{
	int	tmp;
	int	cpt;

	if (y > 0)
	{
		cpt = -1;
		tmp = tab[0];
		while (++cpt < y)
			tab[cpt] = tab[cpt + 1];
		tab[y] = tmp;
	}
	if (y + 1 < len)
	{
		cpt = len + 1;
		tmp = tab[len];
		while (--cpt > y + 1)
			tab[cpt] = tab[cpt - 1];
		tab[y + 1] = tmp;
	}
	return ("rrr\n");
}
