/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 17:59:16 by msrun             #+#    #+#             */
/*   Updated: 2017/01/24 17:12:33 by msrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdlib.h>
# include <unistd.h>
# include "libft.h"
# include "get_next_line.h"

typedef struct	s_cpile
{
	int	*tab;
	int	*statab;
	int len;
	int pos;
	int	a;
	int	b;
}				t_cpile;

char			*ft_sa(void *tab, int y);
char			*ft_sb(void *tab, int y, int len);
char			*ft_ss(void *tab, int y, int len);
char			*ft_ra(void *tab, int y);
char			*ft_rb(void *tab, int y, int len);
char			*ft_rr(void *tab, int y, int len);
char			*ft_rra(void *tab, int y);
char			*ft_rrb(void *tab, int y, int len);
char			*ft_rrr(void *tab, int y, int len);
char			*ft_pb(int *y);
char			*ft_pa(int *y, int len);
int				*ft_get_nbc(int ac, char **av, int *tab, int *nb);
int				ft_printf(const char *s, ...);
int				ft_nbrlen(long long nb);
void			ft_tab_oc(int *oc_tab, int nb);
int				ft_check_double(int *tab, int nb);
int				ft_check_ac3_1(char *s);
int				ft_check_ac3(char *s);
int				ft_check1_ac(int ac, char *av[]);
int				ft_check_doublenb(int ac, char **av);
int				ft_use_op2(int *tab, char *line, int len, int y);
int				ft_check_tab(int *tab, int len, int y);
void			ft_fill_statab(int *statab, int *tab, int len);
void			ft_cprint_pile2(int i, t_cpile tool, int pos);
void			ft_cprint_pile3(int i, t_cpile tool, int pos);
void			ft_print_cpile1(t_cpile tool, int pos);
void			ft_print_pile(int *tab, int pos, int len, int *statab);
void			ft_print_pile2(int *tab, int pos, int len, int i);
void			ft_op_v(int *tab, int y, int len);
void			ft_op_vc(int *tab, int y, int len, int *statab);
void			ft_use_op_p(int op);
int				ft_use_op(int *tab, int len, int y, int op);
int				ft_check_ac3_2(char *s, int c);

#endif
