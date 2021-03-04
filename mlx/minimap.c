/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemesle <tlemesle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 10:19:28 by tlemesle          #+#    #+#             */
/*   Updated: 2021/03/04 15:09:44 by tlemesle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	pixel_put(t_data *data, int x, int y, int color)
{
	char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

void	print_cube(t_config *c, t_data *img, float x, float y, int color)
{
	int	tmp_x;

	while (y < (y + c->ord) && y < c->r2)
	{
		tmp_x = x;
		while (tmp_x < (x + c->abs) && tmp_x < c->r1)
			pixel_put(img, tmp_x++, y, color);
		y++;
	}
}

void	minimap_to_window(t_config *c, t_vars *v, t_data *img)
{
	int		y;
	int		x;
	int		abs;
	int		ord;
	
	y = 0;
	while (y < c->y_max && y < c->r2)
	{
		x = 0;
		while (x < c->x_max && x < c->r1)
		{
			if (c->m.map[y][x] == '1')
				print_cube(c, img, x * c->abs, y * c->ord, 0x00FB1514);
			if (c->m.map[y][x] == '0')
				print_cube(c, img, x * c->abs, y * c->ord, 0x00E0DABD);
			if (c->m.map[y][x] == '2')
				print_cube(c, img, x * c->abs, y * c->ord,  0x002F29E0);
			x++;
		}
		y++;
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
	mlx_loop(v.mlx);
}