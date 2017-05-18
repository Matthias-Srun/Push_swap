/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checking3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 18:06:14 by msrun             #+#    #+#             */
/*   Updated: 2016/12/29 12:41:07 by msrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check_bxbis(const char *s, va_list arg, int *i)
{
	int	p;

	p = ft_strlen(s) - 1;
	if (s[p - 1] == 'j' && s[p] == 'X')
	{
		ft_op_bx(s, (unsigned long long)(va_arg(arg, uintmax_t)), i);
		return ((void)p);
	}
	if (s[p - 1] == 'z' && s[p] == 'X')
	{
		ft_op_bx(s, (va_arg(arg, size_t)), i);
		return ((void)p);
	}
	if (s[p] == 'X')
	{
		ft_op_bx(s, (unsigned long long)va_arg(arg, unsigned int), i);
		return ((void)p);
	}
}

void	ft_check_bx(const char *s, va_list arg, int *i)
{
	int	p;

	p = ft_strlen(s) - 1;
	if (s[p - 2] == 'l' && s[p - 1] == 'l' && s[p] == 'X')
		return (ft_op_bx(s, (va_arg(arg, unsigned long long)), i));
	if (s[p - 1] == 'l' && s[p] == 'X')
	{
		ft_op_bx(s, (unsigned long long)va_arg(arg, unsigned long), i);
		return ((void)i);
	}
	if (s[p - 2] == 'h' && s[p - 1] == 'h' && s[p] == 'X')
	{
		ft_op_bx(s, (unsigned long long)(unsigned char)(va_arg(arg,
						unsigned int)), i);
		return ((void)i);
	}
	if (s[p - 1] == 'h' && s[p] == 'X')
	{
		ft_op_bx(s, (unsigned long long)(unsigned short)(va_arg(arg,
						unsigned int)), i);
		return ((void)i);
	}
	ft_check_bxbis(s, arg, i);
}

void	ft_check_sxbis(const char *s, va_list arg, int *i)
{
	int	p;

	p = ft_strlen(s) - 1;
	if (s[p - 1] == 'j' && s[p] == 'x')
	{
		ft_op_sx(s, (unsigned long long)(va_arg(arg, uintmax_t)), i);
		return ((void)p);
	}
	if (s[p - 1] == 'z' && s[p] == 'x')
	{
		ft_op_sx(s, (va_arg(arg, size_t)), i);
		return ((void)p);
	}
	if (s[p] == 'x')
	{
		ft_op_sx(s, (unsigned long long)va_arg(arg, unsigned int), i);
		return ((void)p);
	}
}

void	ft_check_sx(const char *s, va_list arg, int *i)
{
	int	p;

	p = ft_strlen(s) - 1;
	if (s[p - 2] == 'l' && s[p - 1] == 'l' && s[p] == 'x')
		return (ft_op_sx(s, (va_arg(arg, unsigned long long)), i));
	if (s[p - 1] == 'l' && s[p] == 'x')
	{
		ft_op_sx(s, (unsigned long long)va_arg(arg, unsigned long), i);
		return ((void)i);
	}
	if (s[p - 2] == 'h' && s[p - 1] == 'h' && s[p] == 'x')
	{
		ft_op_sx(s, (unsigned long long)(unsigned char)(va_arg(arg,
						unsigned int)), i);
		return ((void)i);
	}
	if (s[p - 1] == 'h' && s[p] == 'x')
	{
		ft_op_sx(s, (unsigned long long)(unsigned short)(va_arg(arg,
						unsigned int)), i);
		return ((void)i);
	}
	ft_check_sxbis(s, arg, i);
}
