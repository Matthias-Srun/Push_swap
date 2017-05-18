/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 13:20:05 by msrun             #+#    #+#             */
/*   Updated: 2017/01/24 16:35:38 by msrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct	s_swap_tool
{
	int		tmpnb;
	int		attemp;
	int		besttry[2];
	int		split;
	int		b;
	int		tries;
	int		nb;
	int		i;
	int		y;
	int		y2;
	int		err;
	int		tmpminnb;
	int		ac;
	char	**av;
}				t_swap_tool;

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
int				*ft_get_nb(int ac, char **av, int *tab, int *nb);
int				ft_realloc(char **str, size_t size);
int				ft_printf(const char *s, ...);
int				ft_check_double(int *tab, int nb);
void			ft_tab_oc(int *oc_tab, int nb);
t_swap_tool		ft_print_best1bis(t_swap_tool tool, int *oc_tab, int *tab);
t_swap_tool		ft_print_best1(t_swap_tool tool, int *oc_tab, int *tab);
void			ft_print_best(t_swap_tool tool, int *oc_tab);
int				ft_check_order(int *tab, int pos, int len);
int				ft_len_next_nb(int *tab, int oc_tab, int i, int len);
int				ft_len_next_nb2(int *tab, int oc_tab, int i);
int				ft_next_nb3(int *tab, int min, int i);
t_swap_tool		ft_find_best4(t_swap_tool tool);
t_swap_tool		ft_find_best3(t_swap_tool tool, int *oc_tab, int *tab);
t_swap_tool		ft_find_best2(t_swap_tool tool, int *oc_tab, int *tab);
t_swap_tool		ft_find_best1bis(t_swap_tool tool, int *oc_tab, int *tab);
t_swap_tool		ft_find_best1(t_swap_tool tool, int *oc_tab, int *tab);
t_swap_tool		ft_find_best(t_swap_tool tool, int *oc_tab);
t_swap_tool		ft_print_best4(t_swap_tool tool);
t_swap_tool		ft_print_best31(t_swap_tool tool, int *oc_tab,
				int *tab);
t_swap_tool		ft_print_best32(t_swap_tool tool, int *oc_tab,
				int *tab);
t_swap_tool		ft_print_best3(t_swap_tool tool, int *oc_tab, int *tab);
t_swap_tool		ft_print_best2(t_swap_tool tool, int *oc_tab, int *tab);
int				ft_print_l(int ac, char **av);
t_swap_tool		ft_find_best32(t_swap_tool tool, int *oc_tab, int *tab);
t_swap_tool		ft_find_best31(t_swap_tool tool, int *oc_tab, int *tab);
t_swap_tool		ft_print_best33(t_swap_tool tool, int *oc_tab, int *tab);
t_swap_tool		ft_f_best(t_swap_tool tool, int *oc_tab, int *tab);
t_swap_tool		ft_atmp_best(t_swap_tool tool);

#endif
