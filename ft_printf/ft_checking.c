/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checking.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 16:05:40 by msrun             #+#    #+#             */
/*   Updated: 2016/12/28 18:47:11 by msrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check4(const char *s, va_list arg, int *i)
{
	int p;

	p = ft_strlen(s) - 1;
	if (s[p - 2] == 'l' && s[p - 1] == 'l' && s[p] == 'b')
		return (ft_nb_to_binary((va_arg(arg, long long)), i));
	if (s[p - 1] == 'l' && s[p] == 'b')
		return (ft_nb_to_binary((long long)va_arg(arg, long), i));
	if (s[p - 2] == 'h' && s[p - 1] == 'h' && s[p] == 'b')
		return (ft_nb_to_binary((long long)(va_arg(arg, int)), i));
	if (s[p - 1] == 'h' && s[p] == 'b')
		return (ft_nb_to_binary((long long)(va_arg(arg, int)), i));
	if (s[p - 1] == 'j' && s[p] == 'b')
		return (ft_nb_to_binary((long long)(va_arg(arg, intmax_t)), i));
	if (s[p - 1] == 'z' && s[p] == 'b')
		return (ft_nb_to_binary((va_arg(arg, long long)), i));
	if (s[p] == 'b')
		return (ft_nb_to_binary((long long)va_arg(arg, int), i));
}

void	ft_check_obis(const char *s, va_list arg, int *i)
{
	int p;

	p = ft_strlen(s) - 1;
	if (s[p - 1] == 'j' && s[p] == 'o')
	{
		ft_op_o(s, (unsigned long long)(va_arg(arg, uintmax_t)), i);
		return ((void)p);
	}
	if (s[p - 1] == 'z' && s[p] == 'o')
	{
		ft_op_o(s, (va_arg(arg, size_t)), i);
		return ((void)p);
	}
	if (s[p] == 'o')
	{
		ft_op_o(s, (unsigned long long)va_arg(arg, unsigned int), i);
		return ((void)p);
	}
	if (s[p] == 'O')
		return (ft_op_o(s,
					(unsigned long long)va_arg(arg, unsigned long), i));
}

void	ft_check_o(const char *s, va_list arg, int *i)
{
	int p;

	p = ft_strlen(s) - 1;
	if (s[p - 2] == 'l' && s[p - 1] == 'l' && s[p] == 'o')
		return (ft_op_o(s, (va_arg(arg, unsigned long long)), i));
	if (s[p - 1] == 'l' && s[p] == 'o')
	{
		ft_op_o(s, (unsigned long long)va_arg(arg, unsigned long), i);
		return ((void)i);
	}
	if (s[p - 2] == 'h' && s[p - 1] == 'h' && s[p] == 'o')
	{
		ft_op_o(s, (unsigned long long)(unsigned char)(va_arg(arg,
						unsigned int)), i);
		return ((void)i);
	}
	if (s[p - 1] == 'h' && s[p] == 'o')
	{
		ft_op_o(s, (unsigned long long)(unsigned short)(va_arg(arg,
						unsigned int)), i);
		return ((void)i);
	}
	ft_check_obis(s, arg, i);
}

void	ft_check2(const char *s, va_list arg, int *i, int p)
{
	if (s[p - 2] == 'l' && s[p - 1] == 'l' && s[p] == 'u')
		return (ft_use_u_nbr(s, (va_arg(arg, unsigned long long)), i));
	if ((s[p - 1] == 'l' && s[p] == 'u') || s[p] == 'U')
		ft_use_u_nbr(s, ((unsigned long long)va_arg(arg, unsigned long)), i);
	if ((s[p - 1] == 'l' && s[p] == 'u') || s[p] == 'U')
		return ((void)i);
	if (s[p - 2] == 'h' && s[p - 1] == 'h' && s[p] == 'u')
		ft_use_u_nbr(s, (unsigned long long)(unsigned char)(va_arg(arg,
						unsigned int)), i);
	if (s[p - 2] == 'h' && s[p - 1] == 'h' && s[p] == 'u')
		return ((void)i);
	if (s[p - 1] == 'h' && s[p] == 'u')
		ft_use_u_nbr(s, (unsigned long long)(unsigned short)(va_arg(arg,
						unsigned int)), i);
	if (s[p - 1] == 'h' && s[p] == 'u')
		return ((void)i);
	if (s[p - 1] == 'j' && s[p] == 'u')
		ft_use_u_nbr(s, (unsigned long long)(va_arg(arg, uintmax_t)), i);
	if (s[p - 1] == 'j' && s[p] == 'u')
		return ((void)i);
	if (s[p - 1] == 'z' && s[p] == 'u')
		return (ft_use_u_nbr(s, (va_arg(arg, size_t)), i));
	if (s[p] == 'u')
		return (ft_use_u_nbr(s,
					((unsigned long long)va_arg(arg, unsigned int)), i));
}

void	ft_check1(const char *s, va_list arg, int *i)
{
	int p;

	p = ft_strlen(s) - 1;
	if (s[p - 2] == 'l' && s[p - 1] == 'l' && (s[p] == 'd' || s[p] == 'i'))
		return (ft_use_signed_nbr(s, (va_arg(arg, long long)), i));
	if ((s[p - 1] == 'l' && (s[p] == 'd' || s[p] == 'i')) || s[p] == 'D')
		return (ft_use_signed_nbr(s, ((long long)va_arg(arg, long)), i));
	if (s[p - 2] == 'h' && s[p - 1] == 'h' && (s[p] == 'd' || s[p] == 'i'))
		return (ft_use_signed_nbr(s, (long long)(char)(va_arg(arg, int)), i));
	if (s[p - 1] == 'h' && (s[p] == 'd' || s[p] == 'i'))
		return (ft_use_signed_nbr(s, (long long)(short)(va_arg(arg, int)), i));
	if (s[p - 1] == 'j' && (s[p] == 'd' || s[p] == 'i'))
		return (ft_use_signed_nbr(s, (long long)(va_arg(arg, intmax_t)), i));
	if (s[p - 1] == 'z' && (s[p] == 'd' || s[p] == 'i'))
		return (ft_use_signed_nbr(s, (va_arg(arg, long long)), i));
	if (s[p] == 'd' || s[p] == 'i')
		return (ft_use_signed_nbr(s, ((long long)va_arg(arg, int)), i));
}
