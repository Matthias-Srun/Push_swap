/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 16:49:50 by msrun             #+#    #+#             */
/*   Updated: 2017/02/03 18:17:43 by msrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_use_op_p(int op)
{
	int		i;
	char	*pause;

	i = -1;
	if (op == 9 || op == 11 || op == 13 || op == 15)
	{
		get_next_line(1, &pause);
		free(pause);
	}
	else if (op == 1 || op == 3 || op == 5 || op == 7)
	{
		usleep(300000);
		while (++i < 70)
			write(1, "\n", 1);
	}
}

int		ft_freem(char *line, int *statab, int atp)
{
	free(line);
	free(statab);
	return (atp);
}

int		ft_use_op(int *tab, int len, int y, int op)
{
	char	*line;
	int		*statab;
	int		atp;

	if (!(statab = ft_memalloc(sizeof(int) * (len + 1))))
		return (-1);
	ft_fill_statab(statab, tab, len);
	atp = 0;
	(op == 1 || op == 3 || op == 5 || op == 7 || op == 9 || op == 11 || op == 13
	|| op == 15) ? ft_print_pile(tab, len, len, statab) : (void)op;
	while (get_next_line(0, &line) > 0)
	{
		ft_use_op_p(op);
		atp++;
		(op == 1 || op == 5 || op == 9 || op == 13 || op == 3 || op == 7 ||
		op == 11 || op == 15) ? ft_printf("%s\n", line) : op;
		if ((y = ft_use_op2(tab, line, len, y)) == -3)
			return (-1);
		(op == 1 || op == 5 || op == 9 || op == 13) ? ft_op_v(tab, y, len) : y;
		if (op == 3 || op == 7 || op == 11 || op == 15)
			ft_op_vc(tab, y, len, statab);
		free(line);
	}
	ft_check_tab(tab, len, y);
	return (ft_freem(line, statab, atp));
}

int		ft_check_ac3_2(char *s, int c)
{
	int	i;
	int	nb;

	nb = 0;
	i = -1;
	while (s[++i])
		if (s[i] == c)
		{
			nb++;
			if (nb > 1)
				return (-1);
		}
	return (0);
}
