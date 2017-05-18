# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msrun <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/19 13:47:44 by msrun             #+#    #+#              #
#    Updated: 2017/02/03 17:20:39 by msrun            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PUSH = push_swap

CHECKER = checker

SRCSCH = ./checker.c ./checker2.c ./checker3.c ./checker4.c ./get_next_line.c\
		 ./ft_get_nb.c ./ft_op_pile.c ./ft_op_pile2.c ./ft_op_pile3.c\
		 ./ft_realloc.c ./ft_check_double.c

SRCSPS = ./push_swap.c ./push_swap2.c ./push_swap3.c ./push_swap4.c\
		 ./push_swap5.c ./get_next_line.c ./ft_op_pile.c ./ft_op_pile2.c\
		 ./ft_op_pile3.c ./ft_get_nb.c ./ft_realloc.c ./ft_check_double.c\
		 ./push_swap6.c

all: $(PUSH) $(CHECKER)

$(PUSH) : $(SRCSPS)
	make -C libft
	gcc -Werror -Wextra -Wall $(SRCSPS) -I libft libft/libft.a -o $(PUSH)

$(CHECKER) : $(SRCSCH)
	make -C ft_printf
	make -C libft
	gcc -Werror -Wextra -Wall $(SRCSCH) -I libft libft/libft.a ft_printf/libftprintf.a -o $(CHECKER)

clean :
	make clean -C libft
	make clean -C ft_printf

fclean : clean
	make fclean -C libft
	make fclean -C ft_printf
	rm -f checker
	rm -f push_swap

re : fclean all
