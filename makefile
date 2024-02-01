NAME = so_long
NAME_BONUS = so_long_bonus

LIBFT = ./libs/Libft/libft.a
MINILIBX = ./libs/minilibx-linux/libmlx_Linux.a

all: $(NAME)

CC = cc
CCFLAGS = -Wall -Werror -Wextra -g
MLXFLAGS = -L ./libs/minilibx-linux -lm -lmlx -Ilmlx -lXext -lX11

SRC = src/main.c \
	utils/map_check.c \
	utils/map_check_2.c \
	utils/map_utils.c \
	utils/map_path.c\
	utils/utils.c \
	src/open_window.c \
	src/init.c \
	src/render_game.c \
	movements/moves.c \
	movements/key_handler.c

	SRC_BONUS =	src_bonus/main_bonus.c \
		src_bonus/map_check_bonus.c \
		src_bonus/map_check_2_bonus.c \
		src_bonus/map_utils_bonus.c \
		src_bonus/map_path_bonus.c\
		src_bonus/utils_bonus.c \
		src_bonus/open_window_bonus.c \
		src_bonus/init_bonus.c \
		src_bonus/render_game_bonus.c \
		src_bonus/moves_bonus.c \
		src_bonus/cloaker_utils_bonus.c \
		src_bonus/cloaker_move_bonus.c \
		src_bonus/key_handler_bonus.c




OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)

$(NAME): $(OBJ) $(LIBFT) $(MINILIBX)
	$(CC) $(CCFLAGS) $(OBJ) $(LIBFT) $(MLXFLAGS) -o $(NAME)

$(LIBFT):
	$(MAKE) -C ./libs/Libft/

$(MINILIBX):
	$(MAKE) -C ./libs/minilibx-linux

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJ_BONUS) $(LIBFT) $(MINILIBX)
	$(CC) $(CCFLAGS) $(OBJ_BONUS) $(LIBFT) $(MLXFLAGS) -o $(NAME_BONUS)

%.o: %.c
	$(CC) $(CCFLAGS) -o $@ -c $<

clean:
	$(RM) $(RMFLAGS) $(OBJ) $(OBJ_BONUS)

fclean: clean
	$(RM) $(RMFLAGS) $(NAME) $(NAME_BONUS)
	$(MAKE) fclean -C ./libs/Libft/
	$(MAKE) clean -C ./libs/minilibx-linux/

download:
	@wget https://cdn.intra.42.fr/document/document/21300/minilibx-linux.tgz
	@tar -xzf minilibx-linux.tgz -C libs
	@rm minilibx-linux.tgz

re: fclean all bonus
