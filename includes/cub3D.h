/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemesle <tlemesle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 15:04:08 by tlemesle          #+#    #+#             */
/*   Updated: 2021/03/02 16:42:00 by tlemesle         ###   ########.fr       */
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


typedef	struct	s_player
{
	int			x;
	int			y;
	char		orient;
	int			pos_count;
}				t_player;

typedef	struct	s_map
{
	char		*line;
	char		**map;
}				t_map;

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
	int			error;
	t_player	p;
	t_map		m;

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
void			add_walls(t_config *c, int y, int x, int len);
void			fill_spaces(t_config *c);
void			get_map(char *line, t_config *c);
int				greatest_line_len(char **map);

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
#endif
