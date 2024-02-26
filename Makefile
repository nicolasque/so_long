# Variables
CC = gcc
CFLAGS = -Wall -Wextra -Werror -O3
NAME = a.out
SRC = main.c
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