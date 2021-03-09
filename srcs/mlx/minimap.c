/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemesle <tlemesle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 10:19:28 by tlemesle          #+#    #+#             */
/*   Updated: 2021/03/09 14:44:13 by tlemesle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	pixel_put(t_data *data, int x, int y, int color)
{
	char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

void	print_cube(t_config *c, int color, int p)
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
	if (p)
	{
		x = c->p.x * c->abs;
		x_abs = x + c->abs/2;
		y = c->p.y * c->ord;
		y_ord = y + c->ord/3;
	}
	while (y < y_ord && y < c->r2)
	{
		tmp_x = x;
		while (tmp_x < x_abs && tmp_x < c->r1)
			pixel_put(&c->img, tmp_x++, y, color);
		y++;
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
				print_cube(c, 0x00D90F56, 0);
			if (c->m.map[c->y][c->x] == '0')
				print_cube(c, 0x00E0DABD, 0);
			if (c->m.map[c->y][c->x] == '2')
				print_cube(c, 0x002F29E0, 0);
			print_cube(c, 0x00F08F84, 1);
			c->x++;
		}
		c->y++;
	}
	mlx_put_image_to_window(c->v.mlx, c->v.win, c->img.img, 0, 0);
	mlx_destroy_image(c->v.mlx, c->img.img);
}

int		launch_game(t_config *c)
{
	c->img.img = mlx_new_image(c->v.mlx, c->r1, c->r2);
	c->img.addr = mlx_get_data_addr(c->img.img, &c->img.bits_per_pixel, &c->img.line_length, &c->img.endian);
	minimap_to_window(c);
	keyhook(c);
	return (1);
}

void    init_mlx(t_config *c)
{
	c->v.mlx = mlx_init();
	c->v.win = mlx_new_window(c->v.mlx, c->r1, c->r2, "IceCub3D");
	mlx_loop_hook(c->v.mlx, launch_game, c);
	mlx_loop(c->v.mlx);
}