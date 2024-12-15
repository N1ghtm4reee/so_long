CC = cc
MLX =  -Lminilibx-linux -lmlx_Linux -lX11 -lXext
FLAGS = #-Wall -Wextra -Werror
M_SRC = $(addprefix ./mandatory/, free_all.c get_images.c gnl_utils.c gnl.c key_hooks.c list_utils.c \
		map_check_errors.c map_config.c mlx_display.c mlx_utils.c parse.c so_long.c)
M_OBJ = $(M_SRC:.c=.o)
B_SRC = $(addprefix ./bonus/, free_all_bonus.c get_images_bonus.c gnl_utils_bonus.c gnl_bonus.c key_hooks_bonus.c list_utils_bonus.c \
		map_check_errors_bonus.c map_config_bonus.c mlx_display_bonus.c mlx_utils_bonus.c move_ghosts_bonus.c parse_bonus.c so_long_bonus.c)
B_OBJ = $(B_SRC:.c=.o)
NAME = so_long

.c.o :
	$(CC) $(FLAGS) -c -o $@ $<

all : $(NAME)

$(NAME) : $(M_OBJ)
	$(CC) $(FLAGS) $(M_OBJ) -o $(NAME) $(MLX)

bonus : $(B_OBJ)
	$(CC) $(FLAGS) $(B_OBJ) -o $(NAME) $(MLX)

clean :
	@rm -f $(M_OBJ) $(B_OBJ)

fclean : clean
	@rm -f $(NAME)

re : fclean all
