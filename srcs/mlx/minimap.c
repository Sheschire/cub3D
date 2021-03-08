/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemesle <tlemesle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 10:19:28 by tlemesle          #+#    #+#             */
/*   Updated: 2021/03/08 11:32:55 by tlemesle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	pixel_put(t_data *data, int x, int y, int color)
{
	char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

void	print_cube(t_config *c, t_data *img, int color, int p)
{
	int		tmp_x;
	float	x;
	float	y;
	float	y_ord;
	float	x_abs;
	
	x = c->x * c->abs;    //position sur map
	y = c->y * c->ord;    //position sur map
	x_abs = x + c->abs;   //PROPORTION du carre
	if (p)
		x_abs = x + c->abs/2; //PROPORTION du joueur
	y_ord = y + c->ord;   //PROPORTION du carre
	if (p)
		y_ord = y + c->ord/3;  //PROPORTION du joueur
	while (y < y_ord && y < c->r2)
	{
		tmp_x = x;
		while (tmp_x < x_abs && tmp_x < c->r1)
			pixel_put(img, tmp_x++, y, color);
		y++;
	}
}

void	minimap_to_window(t_config *c, t_vars *v, t_data *img)
{	
	c->y = 0;
	while (c->y < c->y_max && c->y < c->r2)
	{
		c->x = 0;
		while (c->x < c->x_max && c->x < c->r1)
		{
			if (c->m.map[c->y][c->x] == '1')
				print_cube(c, img, 0x00D90F56, 0);
			if (c->m.map[c->y][c->x] == '0')
				print_cube(c, img, 0x00E0DABD, 0);
			if (c->m.map[c->y][c->x] == '2')
				print_cube(c, img, 0x002F29E0, 0);
			if (c->x == c->p.x && c->y == c->p.y)
				print_cube(c, img, 0x00F08F84, 1);
			c->x++;
		}
		c->y++;
	}
	mlx_put_image_to_window(v->mlx, v->win, img->img, 0, 0);
}

void    init_mlx(t_config *c)
{
	t_vars	v;
	t_data	img;

	v.mlx = mlx_init();
	v.win = mlx_new_window(v.mlx, c->r1, c->r2, "IceCub3D");
	img.img = mlx_new_image(v.mlx, c->r1, c->r2);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	minimap_to_window(c, &v, &img);
	keyhook(c, &v, &img);
	mlx_loop(v.mlx);
}