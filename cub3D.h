# ifndef CUB3D_H
# define CUB3D_H

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <libc.h>
#include <stdlib.h>
#include "./libft/libft.h"

typedef struct  t_player
{
	int         x;
	int         y;
	char        pos;
	int         pos_count;
}               s_player;

typedef struct	t_config
{
	int			R1;
	int			R2;
	char		*NO;
	char		*SO;
	char		*WE;
	char		*EA;
	char		*S;
	char		*F;
	char		*C;
	int			x;
	int			y;
}				s_config;

int 		ft_error_manager(int n);
int 		ft_check_map(int fd);
void    	free_tab(char **tab);
int			check_config(s_config *conf);
int			ft_get_config(char *line, s_config *conf);
int			get_next_line(int fd, char **line);
int     	ft_get_texture(char *line, s_config *conf);
void    	ft_init_s_player(s_player *player);
void    	ft_init_s_config(s_config *conf);

# endif