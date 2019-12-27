# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmaarela <tmaarela@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/17 11:11:52 by taho              #+#    #+#              #
#    Updated: 2019/12/20 17:57:23 by tmaarela         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf
FLAG = -Wall -Wextra -Werror
SRCS =	srcs/ft_printf.c			\
		srcs/func_char.c			\
		srcs/func_d.c				\
		srcs/func_o.c				\
		srcs/func_x.c				\
		srcs/func_capitalx.c		\
		srcs/func_f.c				\
		srcs/func_u.c				\
		srcs/store_data.c			\
		srcs/store_flags.c			\
		srcs/write_output.c			\
		srcs/store_length_spec.c	\
		testmain.c
OBJE = $(subst .c,.o,$(SRCS))

GREEN = \033[0;32m
RED = \033[0;31m
END = \033[0m

all: $(NAME)

$(NAME):
	make -C libft re
	gcc -o $(NAME) $(SRCS) -L libft -l ft -g
	@echo "$(NAME): $(GREEN)ft_printf was created$(END)"

clean:
	rm -f $(OBJE)
	@echo "$(NAME): $(RED)All object files were deleted.$(END)"

fclean:	clean
	rm -f $(NAME)
	@echo "$(NAME): $(RED)$(NAME) was deleted$(END)"

re:	fclean all

.PHONY: all clean fclean re
.PRECIOUS: author
