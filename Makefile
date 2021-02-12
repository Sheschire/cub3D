NAME	=	cub3D
LIBDIR	=	./libft/
LIBFT	=	libft.a

SRCS	=	check_map.c\
			free_tab.c\
			get_config.c\
			get_texture.c\
			init_struct.c\
			map_parser.c\
			get_next_line.c

OBJS	=	$(SRCS:.c=.o)
CC		=	clang
CFLAGS	=	-Wall -Wextra -Werror
AR		=	ar rc
RM		=	rm -f

%.o: %.c
	$(CC) -I. -o $@ -c $? $(FLAGS)

$(NAME)		:	$(OBJS)
		make all -C $(LIBDIR)
		cp $(LIBDIR)/$(LIBFT) $(NAME)
		
all		:	$(NAME)

fclean	:	clean
		$(RM) $(NAME)
		make fclean -C $(LIBDIR)

clean	:
		$(RM) $(OBJS)
		make clean -C $(LIBDIR)

re		:	fclean all

.PHONY	:	all re clean fclean