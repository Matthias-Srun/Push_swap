/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_op_pile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 13:06:51 by msrun             #+#    #+#             */
/*   Updated: 2017/01/18 18:55:38 by msrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_sa(int *tab, int y)
{
	int	tmp;

	if (y > 0)
	{
		tmp = tab[y];
		tab[y] = tab[y - 1];
		tab[y - 1] = tmp;
	}
	return ("sa\n");
}

char	*ft_sb(int *tab, int y, int len)
{
	int	tmp;

	if (y + 2 <= len)
	{
		tmp = tab[y + 1];
		tab[y + 1] = tab[y + 2];
		tab[y + 2] = tmp;
	}
	return ("sb\n");
}

char	*ft_ss(int *tab, int y, int len)
{
	int	tmp;

	if (y > 0)
	{
		tmp = tab[y];
		tab[y] = tab[y - 1];
		tab[y - 1] = tmp;
	}
	if (y + 2 <= len)
	{
		tmp = tab[y + 1];
		tab[y + 1] = tab[y + 2];
		tab[y + 2] = tmp;
	}
	return ("ss\n");
}

char	*ft_pb(int *y)
{
	if (*y > -1)
		--(*y);
	return ("pb\n");
}

char	*ft_pa(int *y, int len)
{
	if (*y < len)
		*y += 1;
	return ("pa\n");
}
