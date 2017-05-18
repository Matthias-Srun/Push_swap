/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msrun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 13:26:24 by msrun             #+#    #+#             */
/*   Updated: 2017/01/18 18:43:26 by msrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <wchar.h>
# include <string.h>

char				*ft_utoa(unsigned long long n);
char				*ft_convert_base2(char *nbr, char
					*base_from, char *base_to);
int					ft_printf(const char *str, ...);
char				*ft_convert_base(char *nbr, char *base_from, char *base_to);
long long			convert(char *nbr, char *base_from, long long i);
void				cnvrtssr(char *base_to, long long len,
					long long nb, char *nbr_from_to);
long long			get_it(char *nbr, char *base_from);
void				ft_op_prct(const char *s, int *lenp);
void				ft_bin_switch(int i, char *nbstr);
int					ft_do_print(const char *s, va_list arg, int *i);
int					ft_countbis(const char *s);
int					ft_count(const char *s);
int					ft_color(const char *s);
int					ft_txt_color(const char *s);
int					ft_b_color(const char *s);
void				ft_check(const char *s, va_list arg, int *i);
void				ft_check1(const char *s, va_list arg, int *i);
void				ft_check2(const char *s, va_list arg, int *i, int p);
void				ft_check_o(const char *s, va_list arg, int *i);
void				ft_check_obis(const char *s, va_list arg, int *i);
void				ft_check_sx(const char *s, va_list arg, int *i);
void				ft_check_sxbis(const char *s, va_list arg, int *i);
void				ft_check_bx(const char *s, va_list arg, int *i);
void				ft_check_bxbis(const char *s, va_list arg, int *i);
void				ft_check4(const char *s, va_list arg, int *i);
void				ft_check5(const char *s, va_list arg, int *i);
void				ft_check6(const char *s, va_list arg, int *i);
void				ft_op_n(int *nb, int *lenp);
void				ft_op_g(const char *s, double nb, int *lenp);
void				ft_ge0(double nb, int *lenp, int e);
void				ft_ge6(const char *s, double nb, int *lenp, int e);
void				ft_op_e(const char *s, double nb, int *lenp);
void				ft_op_e2(const char *s, double nb, int *lenp);
void				ft_op_f(double nb, int *lenp);
void				ft_putnbr_spec2(long nb, int *lenp);
int					ft_putnbr_wo_0(long long nb);
void				ft_putnbr_spec(long nb, int *lenp);
void				ft_nb_to_b(char *nbstr, int *lenp);
void				ft_nb_to_binary(long long nb, int *lenp);
void				ft_use_lchar(wint_t c, int *lenp);
void				ft_use_lstr(const char *s, wchar_t *str, int *lenp);
void				ft_use_char(const char *s, int str, int *lenp);
void				ft_use_str(const char *s, char *str, int *lenp);
void				ft_use_u_nbr(const char *s, unsigned long long i,
					int *lenp);
void				ft_use_nbradd(const char *s, unsigned long long
					i, int *lenp);
void				ft_use_signed_nbr(const char *s, long long i, int *lenp);
void				ft_get_white_uspace(int a, const char *s,
					char *nb, int *lenp);
void				ft_get_white_space(int a, const char *s, long long nb,
					int *lenp);
void				ft_op_o(const char *s, unsigned long long i, int *lenp);
void				ft_op_sx(const char *s, unsigned long long i, int *lenp);
void				ft_op_bx(const char *s, unsigned long long i, int *lenp);
int					ft_print_whilea(int a, int *lenp);
int					ft_thereisplus(const char *s, long long i, int a,
					int *lenp);
int					ft_a_equal_to(int a, long long i);
int					ft_a_str_equal(int a, char *strnb, const char *s);
int					ft_a_strchar_equal(int a, int strnb);
char				*ft_str_0(const char *s);
const char			*ft_strnbr(const char *s);
int					ft_putunbr(unsigned long long n);
int					ft_unbrlen(unsigned long long nb);
void				ft_print_conv_0(int *lenp);
int					ft_a_is(const char *s, int *b, int *a);
void				ft_print_wsp(int a, int nbsp, int *lenp);
int					ft_ia_is(const char *s, long long nb, int *b);
int					ft_putnchar(char *str, int i);
void				ft_get_white_strspace(int a, const char *s, int str,
					int *lenp);
void				ft_get_ui_white_space(int a, const char *s,
					unsigned long long nb, int *lenp);
void				ft_if_i_neg(long long *i, int *lenp, int *b);
int					ft_return_no_sp(const char *s);
void				ft_print_if_ui(const char *s, unsigned long long i,
					int a, int *lenp);
void				ft_print_if_i(const char *s, long long i, int a, int *lenp);
void				ft_print_wchar(long long nb, int *lenp, int *b);
void				ft_random_char(const char *s, int *i);
void				ft_if_diese(const char *s, unsigned long long i,
		int *lenp, int *b);
int					ft_return_no_sp(const char *s);
void				ft_op_k(char *str, int *lenp);
void				ft_op_lk(char *str, int *lenp);
void				ft_pmonth(int month, int *lenp);
void				ft_op_lka(int *date, int *lenp);
long long			ft_atoi(const char *str);
unsigned long long	ft_atoui(const char *str);
int					ft_isdigit(int c);
char				*ft_itoa(long long n);
void				*ft_memalloc(size_t size);
int					ft_nbrlen(long long nb);
int					ft_power(int nb, int power);
int					ft_putchar(char c);
int					ft_putnbr(long long n);
int					ft_putstr(char const *s);
char				*ft_strchr(const char *s, int c);
int					ft_strcmp(const char *s1, const char *s2);
char				**ft_strsplit(char const *s, char c);
size_t				ft_strlen(const char *s);
char				*ft_strncpy(char *dst, const char *src, size_t len);
int					ft_wstrlen(wchar_t *str);

#endif
