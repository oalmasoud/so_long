NAME = so_long

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

SRC_DR = src

MLX_DIR = ./minilibx-linux
MLX_LIB = -L$(MLX_DIR) -lmlx
MLX_INCLUDE = -I$(MLX_DIR)

CC = cc
CFLAGS = -Wall -Wextra -Werror $(MLX_INCLUDE) -I$(LIBFT_DIR)
LDFLAGS = $(MLX_LIB) -lXext -lX11 -lm

RM = rm -f

SRC =	src/main.c \
		src/utils/read_the_map.c \
		src/utils/error_handling.c \
		src/utils/error_handling_sec2.c \
		src/utils/free.c \
		src/utils/content_handling.c \
		src/game/game_utils.c \
		src/algorithm/game_algorithm.c \
		src/game/game_begin.c \
		src/game/game.c 





OBJ = $(SRC:.c=.o)  

all: libft $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(LDFLAGS)

libft:
	$(MAKE) -C $(LIBFT_DIR) -s

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean -s

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean -s

re: fclean all

.PHONY: all clean fclean re libft
