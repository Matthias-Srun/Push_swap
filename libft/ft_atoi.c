/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 14:05:22 by msrun             #+#    #+#             */
/*   Updated: 2017/01/18 17:36:04 by msrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long	ft_atoi(const char *str)
{
	int		i;
	long	nb;
	int		neg;
	long	max;

	max = 2147483648;
	i = 0;
	nb = 0;
	neg = 1;
	while (str[i] == 32 || str[i] == '\n' || str[i] == '\t' || str[i] == '\r'
			|| str[i] == '\f' || str[i] == '\v')
		++i;
	(str[i] == 45) ? neg = -1 : neg;
	(str[i] == 45 || str[i] == 43) ? ++i : i;
	if (str[i] > 47 && str[i] < 58)
		while (str[i] > 47 && str[i] < 58)
		{
			nb = nb * 10;
			nb = nb + (str[i] - 48);
			i++;
			if ((nb > 2147483647 && neg == 1) || (nb > max && neg == -1))
				return (nb + 1);
		}
	return (nb * neg);
}
