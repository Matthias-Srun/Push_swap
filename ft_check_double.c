/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_double.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 18:35:52 by msrun             #+#    #+#             */
/*   Updated: 2017/01/23 18:28:33 by msrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_check_double(int *tab, int nb)
{
	int	i;

	i = 0;
	while (i + 1 < nb)
	{
		if (tab[i] == tab[i + 1])
			return (1);
		++i;
	}
	return (0);
}

void	ft_tab_oc(int *oc_tab, int nb)
{
	int	i;
	int	tmp;

	i = 0;
	while (i < nb - 1)
	{
		if (oc_tab[i] < oc_tab[i + 1])
		{
			tmp = oc_tab[i];
			oc_tab[i] = oc_tab[i + 1];
			oc_tab[i + 1] = tmp;
			(i) ? --i : i;
		}
		else
			++i;
	}
}
