/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 11:41:05 by msrun             #+#    #+#             */
/*   Updated: 2016/12/29 13:05:54 by msrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_len_nb(unsigned long long n)
{
	int i;

	i = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static void	ft_fill(char *nb, unsigned long long n)
{
	int i;

	i = ft_len_nb(n);
	nb[i] = 0;
	while (n)
	{
		nb[i - 1] = n % 10 + 48;
		n /= 10;
		i--;
	}
}

char		*ft_utoa(unsigned long long n)
{
	char	*nb;

	nb = (char*)malloc(sizeof(char) * (ft_len_nb(n)) + 1);
	if (nb)
	{
		if (n == 0)
		{
			nb[0] = '0';
			nb[1] = 0;
			return (nb);
		}
		ft_fill(nb, n);
		return (nb);
	}
	return (0);
}
