# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmaarela <tmaarela@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/13 17:33:45 by tmaarela          #+#    #+#              #
#    Updated: 2020/01/13 18:36:02 by tmaarela         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C = gcc

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror

LIBFT = libft

DIR_S = srcs

DIR_O = objs

HEADER = include

SOURCES =	ft_printf.c				\
			func_char.c				\
			func_d.c				\
			func_o.c				\
			func_x.c				\
			func_capitalx.c			\
			func_f.c				\
			func_u.c				\
			store_data.c			\
			store_flags.c			\
			write_output.c			\
			store_length_spec.c		\
			fix_negative_sign.c		\
			ft_numlenbase.c			\
			flags_conflict_fix.c	\
			store_hash.c			\
			empty_checks.c			\
			store_space.c			\
			ret_stuff.c

SRCS = $(addprefix $(DIR_S)/,$(SOURCES))

OBJS = $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

GREEN = \033[0;32m
RED = \033[0;31m
END = \033[0m

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFT)
	@cp libft/libft.a ./$(NAME)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "$(NAME): $(GREEN)ft_printf was created$(END)"

$(DIR_O)/%.o: $(DIR_S)/%.c
	@mkdir -p objs
	@$(CC) $(FLAGS) -I $(HEADER) -o $@ -c $<

norme:
	norminette ./libft/
	@echo
	norminette ./$(HEADER)/
	@echo
	norminette ./$(DIR_S)/

clean:
	@rm -f $(OBJS)
	@rm -rf $(DIR_O)
	@make clean -C $(LIBFT)
	@echo "$(NAME): $(RED)All object files were deleted.$(END)"

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT)
	@echo "$(NAME): $(RED)$(NAME) was deleted$(END)"

re: fclean all