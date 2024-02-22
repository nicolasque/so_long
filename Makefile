# Variables
CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = a.out
SRC = main.c get_next_line_utils.c
OBJ = $(SRC:.c=.o)
LIBFT = libft/libft.a
MLX = .mlx/libmlx.a

all: $(NAME)

$(NAME): $(LIBFT) $(MLX) $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -Llibft -lft -L.mlx -lmlx

$(LIBFT):
	make -C libft

$(MLX):
	make -C .mlx

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	make -C libft clean
	make -C .mlx clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean
	make -C .mlx fclean

re: fclean all

.PHONY: all clean fclean re