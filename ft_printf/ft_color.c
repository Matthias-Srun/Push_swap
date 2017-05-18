/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 16:04:08 by msrun             #+#    #+#             */
/*   Updated: 2016/12/21 18:28:10 by msrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**  Change la couleur du background
*/

int		ft_b_color(const char *s)
{
	if (!(ft_strcmp(s, "{bcyan")))
		return (write(1, "\033[46m", 6));
	if (!(ft_strcmp(s, "{bred")))
		return (write(1, "\033[41m", 6));
	if (!(ft_strcmp(s, "{bgreen")))
		return (write(1, "\033[42m", 6));
	if (!(ft_strcmp(s, "{byellow")))
		return (write(1, "\033[43m", 6));
	if (!(ft_strcmp(s, "{bblue")))
		return (write(1, "\033[44m", 6));
	if (!(ft_strcmp(s, "{bpink")))
		return (write(1, "\033[45m", 6));
	if (!(ft_strcmp(s, "{bgrey")))
		return (write(1, "\033[47m", 6));
	if (!(ft_strcmp(s, "{bblack")))
		return (write(1, "\033[40m", 6));
	return (0);
}

/*
**  Change la couleur du texte
*/

int		ft_txt_color(const char *s)
{
	if (!(ft_strcmp(s, "{cyan")))
		return (write(1, "\033[36m", 6));
	if (!(ft_strcmp(s, "{red")))
		return (write(1, "\033[31m", 6));
	if (!(ft_strcmp(s, "{green")))
		return (write(1, "\033[32m", 6));
	if (!(ft_strcmp(s, "{yellow")))
		return (write(1, "\033[33m", 6));
	if (!(ft_strcmp(s, "{blue")))
		return (write(1, "\033[34m", 6));
	if (!(ft_strcmp(s, "{pink")))
		return (write(1, "\033[35m", 6));
	if (!(ft_strcmp(s, "{grey")))
		return (write(1, "\033[37m", 6));
	if (!(ft_strcmp(s, "{black")))
		return (write(1, "\033[30m", 6));
	return (0);
}

int		ft_color(const char *s)
{
	if (!(ft_strcmp(s, "eoc")))
		return (write(1, "\033[0m", 5));
	if (s[1] == 'b' && s[2] != 'l')
		return (ft_b_color(s));
	else
		return (ft_txt_color(s));
	return (0);
}
