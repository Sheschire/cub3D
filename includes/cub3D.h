/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemesle <tlemesle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 15:04:08 by tlemesle          #+#    #+#             */
/*   Updated: 2021/03/12 17:13:27 by tlemesle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include <../mlx/mlx.h>
# include <math.h>

# define W 13
# define A 0
# define D 2
# define S 1
# define TAB 48
# define SHIFT 257
# define SPACE 49
# define UP_ARROW 126
# define DOWN_ARROW 125
# define LEFT_ARROW 123
# define RIGHT_ARROW 124
# define ESC 53
# define DIST 0.01

typedef struct  s_vars {
    void        *mlx;
    void        *win;
}               t_vars;

typedef struct  s_data {
	void        *img;
	char        *addr;
	int         bits_per_pixel;
	int         line_length;
	int         endian;
}               t_data;

typedef	struct	s_player
{
	float			x;
	float			y;
	char		orient;
	int			pos_count;
	int			walk;
	int			left;
	int			right;
	int			speed;
	float		dir_x;
	float		dir_y;
	float		plan_x;
	float		plan_y;
}				t_player;

typedef	struct	s_map
{
	char		*line;
	char		**map;
}				t_map;

typedef struct	s_ray
{
	int			dir;
	float		speed;
	float		angle;
	float		fov;
	float		fov_angle;
	int			n_rays;
	int			wall_thick;
	int			hit_x;
	int			hit_y;
}				t_ray;

typedef struct	s_config
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
	int			x_max;
	int			y_max;
	float		abs;
	float		ord;
	int			error;
	t_player	p;
	t_map		m;
	t_vars		v;
	t_data		img;
	t_ray		r;
}				t_config;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 20
# endif

/*
**	Map
*/
void			ft_check_map(int fd, t_config *c);
void			ft_get_player(t_config *c, int x, int y);
void			map_gnl(int fd, char *line, t_config *c);
void			get_map(char *line, t_config *c);
void			greatest_x_y_max(t_config *c);

/*
**	Config
*/
char			*ft_config(int fd, t_config *c);
int				check_config(t_config *c);
int				check_r(char **r);
int				check_colors(char **rgb);
int				ft_check_xpm(t_config *c);
int				check_param(t_config *c, char **param, char *line);

/*
**	Texture
*/
void			ft_get_texture(char *line, t_config *c);
void			ft_get_path(t_config *c, char **param);
void			ft_free_textures(t_config *c);

/*
**	init structs
*/
void			ft_init_t_config(t_config *c);

/*
**	Free
*/
void			free_tab(char **tab, char const *s, char sep);
void			ft_free_all(t_config *c);

/*
**	Error
*/
void			f_error(char *s, t_config *c);
void			ft_exit(t_config *c);

/*
**	Utils
*/
int				is_in_set(char	c, char *set);
int				is_map_1st_line(char *line);
int				get_next_line(int fd, char **line);

/*
**	MLX
*/
void    		init_mlx(t_config *c);
int				keyhook(t_config *c);
int				key_press(int keycode, t_config *c);
int				key_release(int keycode, t_config *c);
void			print_cube(t_config *c, int color);
void			minimap_to_window(t_config *c);
void			player_movement(t_config *c);
void			win_close(t_config *c);
void			update_angle(t_config *c);
#endif
