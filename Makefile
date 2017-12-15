NAME = fdf
FLAGS = -Wall -Wextra -Werror
DIRLIB = ./libft
LIB = ./libft/libft.a
MLX = ./minilibx_macos
SRCS = main.c \
	   error.c \
	   parser.c \
	   utils.c \
	   draw.c \
	   coord.c \

OBJS = $(SRCS:.c=.o)
INC = includes

vpath %.c srcs/

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(DIRLIB)
	@make -C $(MLX)
	@gcc $(FLAGS) -o $(NAME) $(OBJS) -lmlx -framework OpenGL -framework AppKit -lm $(LIB) -I $(INC) -g

%.o: %.c
	@gcc $(FLAGS) -c -o $@ $< -I $(INC)

clean:
	@$(MAKE) -C $(DIRLIB) fclean
	@$(MAKE) -C $(MLX) clean
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re: 
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY: all clean fclean re
