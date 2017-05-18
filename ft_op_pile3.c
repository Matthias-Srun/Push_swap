/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_op_pile3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 18:54:54 by msrun             #+#    #+#             */
/*   Updated: 2017/01/18 18:55:41 by msrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_ra(int *tab, int y)
{
	int	tmp;
	int	cpt;

	if (y > 0)
	{
		cpt = y;
		tmp = tab[y];
		tab[y] = tab[y - 1];
		while (--cpt > 0)
			tab[cpt] = tab[cpt - 1];
		tab[0] = tmp;
	}
	return ("ra\n");
}

char	*ft_rb(int *tab, int y, int len)
{
	int	tmp;
	int	cpt;

	if (y + 2 <= len)
	{
		cpt = y + 1;
		tmp = tab[y + 1];
		tab[y + 1] = tab[y + 2];
		while (++cpt < len)
			tab[cpt] = tab[cpt + 1];
		tab[len] = tmp;
	}
	return ("rb\n");
}

char	*ft_rr(int *tab, int y, int len)
{
	int	tmp;
	int	cpt;

	if (y > 0)
	{
		cpt = y;
		tmp = tab[y];
		tab[y] = tab[y - 1];
		while (--cpt > 0)
			tab[cpt] = tab[cpt - 1];
		tab[0] = tmp;
	}
	if (y + 2 <= len)
	{
		cpt = y + 1;
		tmp = tab[y + 1];
		tab[y + 1] = tab[y + 2];
		while (++cpt < len)
			tab[cpt] = tab[cpt + 1];
		tab[len] = tmp;
	}
	return ("rr\n");
}
