SHELL		= /bin/sh

CURRENTOS	:= $(shell uname -s)

ifeq ($(CURRENTOS), Linux)
MLX_DIR = ./minilibx-linux
MLX = -L $(MLX_DIR) -lmlx -lm -lbsd -lX11 -lXext
LISTPKG := "$(shell dpkg -l | grep -c "mpg123")"
endif
ifeq ($(CURRENTOS), Darwin)
MLX_DIR = ./mlxopengl
MLX = -L $(MLX_DIR) -lmlx -lm -framework OpenGL -framework AppKit
endif

NAME = cub3D

CC = clang -g3 -Wall -Wextra -Werror 

INC= -I./includes

SRC	=	checks/check_config\
			checks/check_map\
			checks/check_utils\
			map/get_config\
			map/get_map\
			map/get_texture\
			utils/error_manager\
			utils/free_tab\
			utils/get_next_line\
			utils/init_struct\
			cub3d\
			raycast/minimap\
			raycast/keyhook\
			raycast/player_movement\
			raycast/raycast\
			raycast/horizontal_hit\
			raycast/vertical_hit\
			raycast/draw_3d\
			raycast/draw_sprites\
			raycast/sprites_utils\
			raycast/event\
			raycast/draw_item\
			raycast/draw_progression\
			utils/raycast_utils\
			utils/bmp_saver\
			launch_game\
			utils/free_mlx

FIL = $(addsuffix .c, $(addprefix srcs/, $(SRC)))

OBJ = $(FIL:.c=.o)

BIN = $(addsuffix .o, $(SRC))

.c.o:
	@echo "\033[0;32m [OK] \033[0m       \033[0;33m Compiling:\033[0m" $<
	-@${CC} ${INC} -c $< -o ${<:.c=.o}

all: $(NAME)

$(NAME): $(OBJ)
	@echo "\n\033[0;33m Compiling libft..."
	@make -s -C ./libft
	@echo "\033[0;32m-->[OK] \033[0m"
	@echo "\n\033[0;33m Compiling MLX..."
	@make -s -C $(MLX_DIR) 2>/dev/null
	@echo "\033[0;32m-->[OK] \033[0m"
ifeq ($(CURRENTOS), Linux)
	@echo "\n\033[0;33m Checking for dependencies...\033[0m"
ifneq ($(LISTPKG),"2")
	@echo "\033[0;32m-->Installing MGP123 \033[0m"
	sudo apt-get install mpg123
	@echo "\033[0;32m-->MGP123 Installed\033[0m"
else
	@echo "\033[0;32m-->[OK] \033[0m"
endif
endif
	@echo "\n\033[0;34m Compiling $@..."
	-@$(CC) $(INC) $(OBJ) -Llibft -lft $(MLX) -o $(NAME) 
#-fsanitize=address
	@echo "\033[0;32m-->[OK] \033[0m"
	@echo "\033[0;36m\033[0;40mStart program with : ./cub3D [path_map] [--save]\033[0m"

clean:
	@echo "\033[0;31m__Clean__"
	@echo "\033[0;35mLibft"
	@make -s clean -C ./libft
	@echo "\033[0;35mMLX"
	@make -s clean -C $(MLX_DIR)
	@echo "\033[0;35mOBJ"
	@rm -rf $(OBJ)
	@echo "\033[0;35mImg saved"
	@rm -f img_saved.bmp
	@echo "\033[0;32mCleaned \033[0m"

fclean: clean
	@make -s fclean -C ./libft
	@echo
	@echo "\033[0;31m__Delete program__"
	@rm -f $(NAME)
	@echo "\033[0;32m$(NAME) removed\033[0m"

re: fclean all

.SILENT: clean

.PHONY: all clean fclean re packages