SWITCH =		\033[
STYLE_NORMAL =	$(SWITCH)0m
STYLE_BOLD =	$(SWITCH)1m
COLOR_YELLOW =	$(SWITCH)93m
COLOR_GREEN = 	$(SWITCH)32m
COLOR_RED =		$(SWITCH)31m
COLOR_BLUE = 	$(SWITCH)36m
COLOR_BLACK =	$(SWITCH)90m

NAME = sivasysh

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

SRC = sivasysh.c get_functions.c other_functions.c drawing_functions.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	@echo "$(STYLE_BOLD)$(COLOR_BLUE)The library is being created...$(STYLE_NORMAL)"
	@make -C ../libft
	@$(CC) $(CFLAGS) -c $(SRC)
	@$(CC) $(CFLAGS) $(OBJ) ../libft/libft.a -L/usr/local/lib/ -I/usr/local/include -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	@echo "$(STYLE_BOLD)$(COLOR_GREEN)Visualizer has been created!\n$(STYLE_NORMAL)$(STYLE_BOLD)$(COLOR_BLUE)Enjoy! ;)$(STYLE_NORMAL)"
	
clean:
	@echo "$(STYLE_BOLD)$(COLOR_RED)All $(STYLE_NORMAL)$(STYLE_BOLD)$(COLOR_BLACK)visualizer $(STYLE_NORMAL)$(STYLE_BOLD)$(COLOR_RED)object files have been deleted.$(STYLE_NORMAL)"
	@$(RM) $(OBJ)
	@make -C ../libft/ clean

fclean:
	@echo "$(STYLE_BOLD)$(COLOR_RED)All $(STYLE_NORMAL)$(STYLE_BOLD)$(COLOR_BLACK)visualizer $(STYLE_NORMAL)$(STYLE_BOLD)$(COLOR_RED)object files have been deleted.$(STYLE_NORMAL)"
	@echo "$(STYLE_BOLD)$(COLOR_RED)$(NAME) has been deleted.$(STYLE_NORMAL)"
	@$(RM) $(NAME)
	@$(RM) $(OBJ)
	@make -C ../libft/ fclean

re: fclean all

.PHONY : all clean fclean re
