/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 11:41:05 by msrun             #+#    #+#             */
/*   Updated: 2016/11/18 12:31:56 by msrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_len_nb(int n)
{
	int i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		i++;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static void	ft_fill(char *nb, int n)
{
	int i;

	i = ft_len_nb(n);
	nb[i] = 0;
	if (n < 0)
	{
		n = -n;
		nb[0] = 45;
	}
	while (n)
	{
		nb[i - 1] = n % 10 + 48;
		n /= 10;
		i--;
	}
}

static void	ft_fillmin(char *nb)
{
	nb[0] = '-';
	nb[1] = '2';
	nb[2] = '1';
	nb[3] = '4';
	nb[4] = '7';
	nb[5] = '4';
	nb[6] = '8';
	nb[7] = '3';
	nb[8] = '6';
	nb[9] = '4';
	nb[10] = '8';
	nb[11] = 0;
}

char		*ft_itoa(int n)
{
	char	*nb;

	nb = (char*)malloc(sizeof(char) * (ft_len_nb(n)) + 1);
	if (!nb)
		return (NULL);
	if (n == -2147483648)
	{
		ft_fillmin(nb);
		return (nb);
	}
	if (n == 0)
	{
		nb[0] = '0';
		nb[1] = 0;
		return (nb);
	}
	ft_fill(nb, n);
	return (nb);
}
