NAME = fdf
FLAGS = -Wall -Wextra -Werror
DIRLIB = ./libft
LIB = ./libft/libft.a
MLX = ./minilibx_macos
SRCS = 
OBJS = $(SRCS:.c=.o)
INC = includes

vpath %.c srcs/

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(DIRLIB)
	make -C $(MLX)

