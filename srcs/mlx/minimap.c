/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemesle <tlemesle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 10:19:28 by tlemesle          #+#    #+#             */
/*   Updated: 2021/03/12 16:17:45 by tlemesle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	pixel_put(t_data *data, int x, int y, int color)
{
	char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

void	print_cube(t_config *c, int color)
{
	int		tmp_x;
	float	x;
	float	y;
	float	y_ord;
	float	x_abs;
	
	x = c->x * c->abs;
	y = c->y * c->ord;
	x_abs = x + c->abs;
	y_ord = y + c->ord;
	while (y < y_ord && y < c->r2)
	{
		tmp_x = x;
		while (tmp_x < x_abs && tmp_x < c->r1)
			pixel_put(&c->img, tmp_x++, y, color);
		y++;
	}
}

void	print_player(t_config *c)
{
	int		radius;
	float	x;
	float	y;
	float	angle;
	int		i;
	
	x = c->p.x * c->abs;
	y = c->p.y * c->ord;
	radius = 4;
	angle = 0;
	i = 0;
	while (i <= radius)
	{
		pixel_put(&c->img, x, y, 0x00000000);
		angle = 0;
		while (angle <= 6.28)
		{
			x = (c->p.x * c->abs) + cos(angle) * i;
			y = (c->p.y * c->ord) + sin(angle) * i;
			pixel_put(&c->img, x, y, 0x00000000);
			angle += 0.1;
		}
		i++;
	}
}

void	print_ray(t_config *c)
{
	float	x;
	float	y;
	float	tmp_x;
	float	tmp_y;
	int		i;
	
	i = 0;
	x = c->p.x * c->abs;
	y = c->p.y * c->ord;
	tmp_x = x;
	tmp_y = y;
	while (!is_in_set(c->m.map[(int)floorf(tmp_y / c->ord)][(int)floorf(tmp_x / c->abs)], "12"))
	{
		tmp_x = x + cos(c->r.fov_angle) * i;
		tmp_y = y + sin(c->r.fov_angle) * i;
		pixel_put(&c->img, tmp_x, tmp_y, 0x1AD08D);
		i++;
	}
}

void	print_fov(t_config *c)
{
	float	fov_angle;
	int		i;
	
	c->r.wall_thick = 50;
	c->r.n_rays = c->r1 / c->r.wall_thick;
	update_angle(c);
	i = 0;
	while (i < c->r.n_rays)
	{
		print_ray(c);
		c->r.fov_angle += c->r.fov / c->r.n_rays;
		i++;
	}
}

void	minimap_to_window(t_config *c)
{
	c->y = 0;
	while (c->y < c->y_max && c->y < c->r2)
	{
		c->x = 0;
		while (c->x < c->x_max && c->x < c->r1)
		{
			if (c->m.map[c->y][c->x] == '1')
				print_cube(c, 0x00D90F56);
			if (c->m.map[c->y][c->x] == '0')
				print_cube(c, 0x00E0DABD);
			if (c->m.map[c->y][c->x] == '2')
				print_cube(c, 0x002F29E0);
			c->x++;
		}
		c->y++;
	}
	print_fov(c);
	print_player(c);
	mlx_put_image_to_window(c->v.mlx, c->v.win, c->img.img, 0, 0);
	mlx_destroy_image(c->v.mlx, c->img.img);
}

int		launch_game(t_config *c)
{
	c->img.img = mlx_new_image(c->v.mlx, c->r1, c->r2);
	c->img.addr = mlx_get_data_addr(c->img.img, &c->img.bits_per_pixel, &c->img.line_length, &c->img.endian);
	minimap_to_window(c);
	keyhook(c);
	player_movement(c);
	return (1);
}

void    init_mlx(t_config *c)
{
	c->v.mlx = mlx_init();
	c->v.win = mlx_new_window(c->v.mlx, c->r1, c->r2, "IceCub3D");
	mlx_loop_hook(c->v.mlx, launch_game, c);
	mlx_loop(c->v.mlx);
}