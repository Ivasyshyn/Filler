#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sivasysh <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/26 16:14:29 by sivasysh          #+#    #+#              #
#    Updated: 2017/11/12 22:47:42 by sivasysh         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

SWITCH =		\033[
STYLE_NORMAL =	$(SWITCH)0m
STYLE_BOLD =	$(SWITCH)1m
COLOR_YELLOW =	$(SWITCH)93m
COLOR_GREEN = 	$(SWITCH)32m
COLOR_RED =		$(SWITCH)31m
COLOR_BLUE = 	$(SWITCH)36m
COLOR_BLACK =	$(SWITCH)90m

NAME =			sivasysh.filler
FLAGS =			-Wall -Wextra -Werror

SRC_FILES =		manage_variable.c \
				manage_input.c \
				manage_piece.c \
				main.c

OBJ_FILES =		$(SRC_FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJ_FILES)
	@echo "$(STYLE_BOLD)$(COLOR_BLUE)The library is being created...$(STYLE_NORMAL)"
	@make -C libft
	@gcc -o $(NAME) $(OBJ_FILES) -L libft -lft
	@echo "$(STYLE_BOLD)$(COLOR_GREEN)$(NAME) has been created!\n$(STYLE_NORMAL)$(STYLE_BOLD)$(COLOR_BLUE)Enjoy! ;)$(STYLE_NORMAL)"
	
%.o : %.c
	@gcc $(FLAGS) -c $< -o $@

clean:
	@echo "$(STYLE_BOLD)$(COLOR_RED)All $(STYLE_NORMAL)$(STYLE_BOLD)$(COLOR_BLACK)filler $(STYLE_NORMAL)$(STYLE_BOLD)$(COLOR_RED)object files have been deleted.$(STYLE_NORMAL)"
	@make clean -C libft
	@rm -f $(OBJ_FILES)

fclean:
	@make fclean -C libft
	@echo "$(STYLE_BOLD)$(COLOR_RED)All $(STYLE_NORMAL)$(STYLE_BOLD)$(COLOR_BLACK)filler $(STYLE_NORMAL)$(STYLE_BOLD)$(COLOR_RED)object files have been deleted.$(STYLE_NORMAL)"
	@echo "$(STYLE_BOLD)$(COLOR_RED)$(NAME) has been deleted.$(STYLE_NORMAL)"
	@rm -f $(OBJ_FILES)
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re