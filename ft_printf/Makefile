# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msrun <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 201./libft/1./libft/10 13:48:16 by msrun             #+#    #+#              #
#    Updated: 2016/12/29 17:18:09 by msrun            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJECTS = ./ft_checking.o ./ft_checking2.o ./ft_color.o ./ft_convert_base.o ./ft_op_char.o ./ft_op_convert.o ./ft_op_double.o ./ft_op_double2.o ./ft_op_int.o ./ft_printf.o ./ft_tool.o ./ft_tool2.o ./ft_op_convert2.o ./ft_utoa.o ./ft_convert_base2.o ./ft_checking3.o ./ft_tool3.o ./ft_tool4.o ./ft_op_char2.o ./ft_op_int2.o ./ft_op_k.o ./ft_op_lk.o ./ft_op_lk2.o ./ft_atoi.o ./ft_atoui.o ./ft_isdigit.o ./ft_itoa.o ./ft_memalloc.o ./ft_nbrlen.o ./ft_power.o ./ft_putchar.o ./ft_putnbr.o ./ft_putstr.o ./ft_strchr.o ./ft_strcmp.o ./ft_strlen.o ./ft_strncpy.o ./ft_strsplit.o

SRCS = ./ft_checking.c ./ft_checking2.c ./ft_color.c ./ft_convert_base.c ./ft_op_char.c ./ft_op_convert.c ./ft_op_double.c ./ft_op_double2.c ./ft_op_int.c ./ft_printf.c ./ft_tool.c ./ft_tool2.c ./ft_op_convert2.c ./ft_utoa.c ./ft_convert_base2.c ./ft_checking3.c ./ft_tool3.c ./ft_tool4.c ./ft_op_char2.c ./ft_op_int2.c ./ft_op_k.c ./ft_op_lk.c ./ft_op_lk2.c ./ft_atoi.c ./ft_atoui.c ./ft_isdigit.c ./ft_itoa.c ./ft_memalloc.c ./ft_nbrlen.c ./ft_power.c ./ft_putchar.c ./ft_putnbr.c ./ft_putstr.c ./ft_strchr.c ./ft_strcmp.c ./ft_strlen.c ./ft_strncpy.c ./ft_strsplit.c


NAME = libftprintf.a

all: $(NAME)

$(NAME):
	gcc -Werror -Wextra -Wall -c $(SRCS)
	ar rc $(NAME) $(OBJECTS) $(MOBJECTS)
	ranlib $(NAME)

clean:
	rm -f $(OBJECTS)

fclean:	clean
	rm -f $(NAME)

re: fclean all
