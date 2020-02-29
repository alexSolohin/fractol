NAME = fractol
MINILIB_PATH = ./minilibx_macos
SRCS_DIR = ./srcs
I_DIR = ./includes
OBJS_DIR = objs
CC = gcc
CFLAGC = -Wall -Wextra -Werror
_SRCS = fractol.c \
		mandelbrot.c
		# draw.c \
		# fractol_init_img.c \
		# keyboard_hook.c \
		# init_hook.c \
		



SRSC = $(addprefix $(SRCS_DIR)/. $(_SRCS))
_OBJS = $(_SRCS:%.c=%.o)
OBJS = $(addprefix $(OBJS_DIR)/, $(_OBJS))

BLACK = \033[0;30m
GREEN = \033[0;32m
RED = \033[0;31m
BLINK = \033[5m
RESET = \033[0m

all: $(NAME)
	# @say -v Fred hello, my name is Stephen Hawking, `date "+DATE: %Y-%m-%d"`
	@say -v Fred $(NAME) was created
	@echo "\n$(NAME): $(GREEN)$(NAME) was created"

$(NAME): $(OBJS)
	@$(CC) $(OBJS) -o $(NAME) $(CFLAGC) -L$(MINILIB_PATH) -lmlx -framework OpenGL -framework AppKit
	

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p objs
	@echo "$(GREEN).$(RESET)\c"
	@$(CC) -c -o $@ $< $(CFLAGC) -I$(I_DIR) -I$(MINILIB_PATH)

clean:
	@say -v Fred Go then, there are other worlds than these.
	@rm -f $(OBJS)
	@echo "$(NAME): $(RED).$(RESET)"
	@echo "$(NAME): $(RED)objects files was deleted"

fclean: clean
	@rm -f $(NAME)

re: fclean all
	
.PHONY: all clean fclean re