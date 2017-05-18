/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tool3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 18:29:07 by msrun             #+#    #+#             */
/*   Updated: 2016/12/29 16:50:50 by msrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_a_is(const char *s, int *b, int *a)
{
	*b = 0;
	*a = 0;
	(ft_str_0(s) != 0) ? *a = ft_atoui(ft_str_0(s) + 1) : (void)a;
	(ft_str_0(s) != 0 && ft_strchr(s, 'p')) ?
		*a = ft_atoui(ft_str_0(s) + 1) - 2 : (void)a;
	(ft_strchr(s, '-') != 0) ? *b = -ft_atoui(ft_strnbr(s)) : (void)a;
	if (ft_strchr(s, '.') != 0)
	{
		*a = ft_atoui(ft_strchr(s, '.') + 1);
	}
	return (*a);
}

int		ft_ia_is(const char *s, long long nb, int *b)
{
	int a;

	a = 0;
	if (ft_str_0(s) != 0)
		a = ft_atoi(ft_str_0(s) + 1);
	if (ft_strchr(s, '-') != 0)
		*b = -ft_atoi(ft_strnbr(s));
	if (ft_strchr(s, '.') != 0)
		a = ft_atoi(ft_strchr(s, '.') + 1);
	(nb < 0 && a > 0 && *b >= 0 && !ft_strchr(s, '.')) ? --a : (void)a;
	if (a < 0)
		a = 0;
	return (a);
}

void	ft_print_wsp(int a, int nbsp, int *lenp)
{
	if (nbsp > a)
	{
		nbsp -= a;
		while (nbsp > 0)
		{
			write(1, " ", 1);
			*lenp += 1;
			nbsp--;
		}
	}
}

int		ft_putnchar(char *str, int i)
{
	if (!str)
		return (0);
	if (ft_strlen(str) < (unsigned long long)i)
		i = ft_strlen(str);
	write(1, str, i);
	return (i);
}

void	ft_get_white_strspace(int a, const char *s, int b, int *lenp)
{
	int	i;
	int	nbsp;

	i = 0;
	while (s[i])
	{
		if (s[i] == '.' || s[i] == '-')
			break ;
		if (s[i] >= '0' && s[i] <= '9')
		{
			nbsp = ft_atoi(s + i) - b;
			ft_print_wsp(a, nbsp, lenp);
			break ;
		}
		i++;
	}
}
