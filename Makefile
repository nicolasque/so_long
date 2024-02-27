# Variables
CC = gcc
CFLAGS = -Wall -Wextra -Werror -O3
NAME = so_long
SRC =	src/main.c \
		src/floodfill_map.c \
		src/get_map.c \
		src/input_management.c \
		src/key_hook.c \
		src/map_paint.c \
		src/on_close.c \
		src/utils.c \
		src/verify_map.c \

OBJ = $(SRC:.c=.o)
LIBFT = libft/libft.a
MLX = .mlx/libmlx.a

all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME)  -Llibft -lft -L.mlx -lmlx -framework OpenGL -framework AppKit $(OBJ)

$(LIBFT):
	make -C libft

$(MLX):
	make -C .mlx

%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

clean:
	rm -f $(OBJ)
	make -C libft clean
	make -C .mlx clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean
	make -C .mlx clean

re: fclean all

.PHONY: all clean fclean re