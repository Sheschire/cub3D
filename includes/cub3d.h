/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemesle <tlemesle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 15:04:08 by tlemesle          #+#    #+#             */
/*   Updated: 2021/04/09 13:36:33 by tlemesle         ###   ########.fr       */
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
# include "os.h"
# include <math.h>

# define DIST 0.01
# define PI 3.1415926
# define TILE 27
# define SCALE 5

typedef struct	s_vars
{
	void		*mlx;
	void		*win;
}				t_vars;

typedef struct	s_data
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_data;

typedef struct	s_wall
{
	int			w_top;
	int			w_bot;
	int			w_height;
}				t_wall;

typedef	struct	s_map
{
	char		*line;
	char		**map;
}				t_map;

typedef struct	s_texture
{
	void		*img;
	char		*addr;
	int			height;
	int			width;
}				t_texture;

typedef struct	s_player
{
	float		x;
	float		y;
	float		mx;
	float		my;
	char		orient;
	int			pos_count;
	int			walk;
	int			left;
	int			right;
	float		speed;
	float		xdir;
	float		ydir;
	float		plany;
	float		planx;
}				t_player;

typedef struct	s_ray
{
	int			dir;
	float		speed;
	float		angle;
	float		fov;
	float		fov_angle;
	int			n_rays;
	int			wall_thick;
	float		xi;
	float		yi;
	float		delt_x;
	float		delt_y;
	float		dist_p_hit;
	int			face_up;
	int			face_down;
	int			face_left;
	int			face_right;
	float		hitx;
	float		hity;
	int			verthit;
}				t_ray;

typedef struct	s_sprite
{
	int			topx;
	int			topy;
	int			botx;
	int			boty;
	int			screenx;
	int			num;
	int			width;
	int			height;
	float		size;
	float		newy;
	float		x;
	float		y;
	float		dist;
}				t_sprite;

typedef struct	s_pkmn
{
	int			pokecub;
	int			ray_encounter;
	int			candy;
	int			current_item;
	int			progress;
}				t_pkmn;

typedef struct	s_config
{
	int			game_started;
	int			line_bool;
	char		*line;
	float		*buff;
	int			r1;
	int			r2;
	int			pokeflute;
	int			pokeball;
	int			f_rgb;
	int			c_rgb;
	int			x;
	int			y;
	int			x_max;
	int			y_max;
	float		abs;
	float		ord;
	int			error;
	int			tile;
	int			n_sprite;
	float		xb;
	float		yb;
	float		i_tmp;
	int			bmp_save;
	t_player	p;
	t_map		m;
	t_vars		v;
	t_data		img;
	t_ray		r;
	t_wall		w;
	t_texture	t[20];
	t_sprite	*sp;
	t_pkmn		pkmn;
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
void			ft_config(int fd, t_config *c);
int				check_config(t_config *c);
int				check_r(char **r, t_config *c);
int				check_colors(char **rgb);
int				ft_check_xpm(t_config *c);
int				check_param(t_config *c, char **param, char *line);
void			player_orientation(t_config *c);
void			check_screen_size(t_config *c);
void			ft_split_colors(char *line, t_config *c);
void			ft_get_colors(char **tmp, char **rgb, t_config *c);

/*
**	Texture
*/
void			ft_get_texture(char *line, t_config *c);
void			ft_get_path(t_config *c, char **param);
void			get_path_bonus(t_config *c);

/*
**	init structs
*/
void			ft_init_t_config(t_config *c);
void			init_sprites(t_config *c);
void			init_ray(t_config *c);

/*
**	Free
*/
void			free_tab(char **tab, char const *s, char sep);
void			ft_free_all(t_config *c);
void			free_window(t_config *c);
void			free_image(t_config *c);

/*
**	Error
*/
void			f_error(char *s, t_config *c);
int				ft_exit(t_config *c);

/*
**	Utils
*/
int				is_in_set(char	c, char *set);
int				is_map_1st_line(char *line);
int				get_next_line(int fd, char **line);
void			play_sound(char c);

/*
**	MLX
*/
void			init_mlx(t_config *c);
void			pixel_put(t_data *data, int x, int y, int color);
int				keyhook(t_config *c);
int				key_press(int keycode, t_config *c);
int				key_release(int keycode, t_config *c);
void			minimap_to_window(t_config *c);
void			print_cube(t_config *c, int color);
void			win_close(t_config *c);

/*
**	RAYCAST
*/
void			update_angle(t_config *c);
void			print_ray(t_config *c);
void			print_fov(t_config *c);
void			player_movement(t_config *c);
void			horizontal_hit(t_config *c);
void			vertical_hit(t_config *c);
void			reset_ray(t_config *c);
int				is_wall(float y, float x, t_config *c);
void			normalize_r_angle(t_config *c);
void			update_var_angle(t_config *c);

/*
**	WORLD
*/
void			init_world(t_config *c);
void			draw_background(t_config *c);
void			draw_3d(t_config *c, int column);
int				launch_game(t_config *c);
void			ft_bmp_saver(t_config *c);
void			paint_floor_ceiling(t_config *c);

/*
**	SPRITES
*/
char			*get_texture_addr(t_config *c, int n, char **param);
char			*get_texture_addr_bonus(t_config *c, int n, char *filename);
void			draw_sprites(t_config *c);
void			find_sprite(t_config *c);
void			get_coord_draw(t_sprite *sp, t_config*c);
void			get_sprite_size(t_config *c, int i);
void			get_newy(t_config *c, int i);
void			count_sprites(t_config *c);

/*
**	POKEMON
*/
void			draw_item(t_config *c, int n);
void			is_item_picked(t_config *c);
void			switch_item(t_config *c);
void			clean_item(t_config *c);
void			event(t_config *c);
void			draw_progression(t_config *c);
#endif
