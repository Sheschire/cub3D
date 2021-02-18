# ifndef CUB3D_H
# define CUB3D_H

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "../libft/libft.h"

typedef struct  t_player
{
	int         x;
	int         y;
	char        orient;
	int         pos_count;
}               s_player;

typedef struct	t_config
{
	int			r1;
	int			r2;
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	char		*s;
	int			f_rgb;
	int			c_rgb;
	int			x;
	int			y;
}				s_config;

typedef struct	t_map
{
	char		*line;
	char		**map;
}				s_map;

typedef struct	t_error 
{
	int			boo;
}				s_error;

//	Map
void 	ft_check_map(int fd, s_error *err);
int 	ft_check_walls(s_map *map, s_player *player);
int		check_empty_line(char *line);
int		greatest_line_len(char **map);
void	ft_get_player(s_map *map, s_player *player, int x, int y);
void	tmp_print_check(s_map *map, s_player *player, s_config *conf);

//	Config
char	*ft_config(int fd, s_error *err, s_config *conf);
int		check_config(s_config *conf);
int		check_R(char **r);
int		check_colors(char **rgb);
int		ft_check_xpm(s_config *conf);
int		check_param(s_config *conf, char **param, s_error *err, char *line);

//	Texture
void	ft_get_texture(char *line, s_config *conf, s_error *err);
void	ft_get_path(s_config *conf, char **param);
void	ft_free_textures(s_config *conf);

//	init structs
void    ft_init_s_player(s_player *player);
void    ft_init_s_config(s_config *conf);
void    ft_init_s_map(s_map *map);
void    ft_init_s_error(s_error *err);

//	Free
void	free_tab(char **tab, char const *s, char sep);
void	ft_free_all(s_map *map, s_config *conf);

//	Error
void 	_ERROR(char  *s, s_error *err);

// Utils
int		is_in_set(char	c, char *set);
int		is_map_1st_line(char *line);
int		get_next_line(int fd, char **line);
# endif