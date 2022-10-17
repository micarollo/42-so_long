NAME = so_long

SRC = so_long.c src/ft_split.c src/ft_init.c src/check_map.c \
		src/move.c src/draw_map.c src/utils.c src/check_ber.c \
		src/error_control.c src/hook.c src/close_window.c \
		gnl/get_next_line.c gnl/get_next_line_utils.c \

OBJ = ${SRC:.c=.o}

MLX_PATH = mlx/

MLX_I = -Imlx

MLX = -Lmlx -lmlx -framework OpenGL -framework AppKit

HEADER = so_long.h

CC = GCC

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	@make -C mlx/
	$(CC) $(CFLAGS) $(OBJ) $(MLX) -o so_long

clean:
	$(RM) $(OBJ)
	make -C mlx clean

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
