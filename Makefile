NAME	=	cub3D
LIBDIR	=	./libft/
LIBFT	=	libft.a

SRCS	=	./srcs/checks/check_config.c\
			./srcs/checks/check_map.c\
			./srcs/checks/check_utils.c\
			./srcs/map/get_config.c\
			./srcs/map/get_map.c\
			./srcs/map/get_texture.c\
			./srcs/utils/error_manager.c\
			./srcs/utils/free_tab.c\
			./srcs/utils/get_next_line.c\
			./srcs/utils/init_struct.c\
			./srcs/cub3d.c\
			./srcs/mlx/minimap.c\
			./srcs/mlx/keyhook.c\
			./srcs/mlx/player_movement.c

OBJS	=	$(SRCS:.c=.o)
CC		=	clang
CFLAGS	=	-Wall -Wextra -Werror
AR		=	ar rc
RM		=	rm -f

%.o: %.c
	$(CC) -I./includes -Imlx -c $< -o $@ $(FLAGS)

$(NAME)		:	$(OBJS)
		make all -C $(LIBDIR)
		$(CC) $(CFLAGS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(OBJS) $(LIBDIR)/$(LIBFT)
		
all		:	$(NAME)

fclean	:	clean
		$(RM) $(NAME)
		make fclean -C $(LIBDIR)

clean	:
		$(RM) $(OBJS)
		make clean -C $(LIBDIR)

re		:	fclean all

.PHONY	:	all re clean fclean mlx libft