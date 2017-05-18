/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/19 00:07:10 by msrun             #+#    #+#             */
/*   Updated: 2016/12/22 18:22:27 by msrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		cnvrtssr(char *base_to, long long len,
		long long nb, char *nbr_from_to)
{
	long long i;
	long long nb_rec;
	long long nblen;

	nblen = 0;
	nb_rec = nb;
	while ((nb_rec = nb_rec / len) != 0)
		nblen++;
	if (nbr_from_to[0] == 45)
		nblen++;
	i = 0;
	while (nb != 0)
	{
		nbr_from_to[nblen - i] = base_to[nb % len];
		nb = nb / len;
		i++;
	}
	nbr_from_to[nblen + 1] = '\0';
}

long long	convert(char *nbr, char *base_from, long long len)
{
	long long i;
	long long y;
	long long nb;

	nb = 0;
	i = 0;
	while (nbr[i] != 0)
	{
		y = 0;
		while (base_from[y] != 0)
		{
			if (nbr[i] == base_from[y])
			{
				nb = nb + y;
				if (nbr[i + 1] != 0)
					nb *= len;
				break ;
			}
			++y;
		}
		i++;
	}
	return (nb);
}

long long	get_it(char *nbr, char *base_from)
{
	long long i;
	long long nb;

	i = 0;
	while (base_from[i] != '\0')
		i++;
	nb = convert(nbr, base_from, i);
	return (nb);
}

char		*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long long		nb;
	long long		i;
	long long		len;
	long long		neg;
	char			*nbr_from_to;

	neg = 0;
	if (nbr[0] == 45)
		neg = 1;
	i = 0;
	nb = get_it(nbr, base_from);
	len = 0;
	while (base_to[len] != '\0')
		len++;
	i = 0;
	while ((nb = nb / len) != 0)
		i++;
	nbr_from_to = (char*)malloc(sizeof(*nbr_from_to) * (i + 2));
	if (neg == 1)
		nbr_from_to[0] = 45;
	nb = get_it(nbr, base_from);
	cnvrtssr(base_to, len, nb, nbr_from_to);
	return (nbr_from_to);
}
