/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 18:00:18 by msrun             #+#    #+#             */
/*   Updated: 2016/12/29 12:08:39 by msrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

int	ft_putstr(char const *s)
{
	int	len;

	len = 0;
	if (s)
	{
		write(1, s, ft_strlen(s));
		len = (int)ft_strlen(s);
	}
	return (len);
}
