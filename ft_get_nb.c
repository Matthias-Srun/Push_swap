/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_nb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 11:59:36 by msrun             #+#    #+#             */
/*   Updated: 2017/02/03 16:59:32 by msrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int	ft_check_arg(char *str)
{
	int i;

	i = 0;
	if (str[0] == '-' || str[0] == '+')
		++i;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] > '9' || str[i] < '0')
			return (0);
		++i;
	}
	return (1);
}

int	*ft_get_nb(int ac, char **av, int *tab, int *nb)
{
	int	i;

	i = 0;
	*nb = ac - 1;
	if (!(tab = (int*)ft_memalloc(sizeof(int) * ac)))
		return (0);
	while (--ac)
	{
		if (!ft_check_arg(av[ac]))
			return (0);
		if (ft_atoi(av[ac]) > 2147483648)
			return (0);
		tab[i] = ft_atoi(av[ac]);
		++i;
	}
	return (tab);
}

int	*ft_get_nbc(int ac, char **av, int *tab, int *nb)
{
	int	i;
	int	ag;

	ag = 0;
	i = 0;
	*nb = ac - 1;
	if (av[1][0] == '-' && (av[1][1] == 'v' || av[1][1] == 'c' ||
				av[1][1] == 't' || av[1][1] == 'p'))
	{
		ag = 1;
		--(*nb);
	}
	if (!(tab = (int*)ft_memalloc(sizeof(int) * ac)))
		return (0);
	while (--ac > ag)
	{
		if (!ft_check_arg(av[ac]))
			return (0);
		if (ft_atoi(av[ac]) > 2147483648)
			return (0);
		tab[i] = ft_atoi(av[ac]);
		++i;
	}
	return (tab);
}
