/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemesle <tlemesle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 10:19:28 by tlemesle          #+#    #+#             */
/*   Updated: 2021/04/08 11:36:25 by tlemesle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	print_cube(t_config *c, int color)
{
	int		tmp_x;
	float	x;
	float	y;
	float	y_ord;
	float	x_abs;

	x = c->x * (TILE / SCALE);
	y = c->y * (TILE / SCALE);
	x_abs = x + (TILE / SCALE);
	y_ord = y + (TILE / SCALE);
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

	x = c->p.x * (TILE / SCALE);
	y = c->p.y * (TILE / SCALE);
	radius = 4;
	angle = 0;
	i = 0;
	while (i <= radius)
	{
		pixel_put(&c->img, x, y, 0x00000000);
		angle = 0;
		while (angle <= 6.28)
		{
			x = (c->p.x * (TILE / SCALE)) + cos(angle) * i;
			y = (c->p.y * (TILE / SCALE)) + sin(angle) * i;
			pixel_put(&c->img, x, y, 0x00000000);
			angle += 0.1;
		}
		i++;
	}
}

void	minimap_to_window(t_config *c)
{
	c->y = 0;
	while (c->y < c->y_max && c->y < c->r2)
	{
		c->x = 0;
		while (c->x < 33 && c->x < c->x_max)
		{
			if (c->m.map[c->y][c->x] == '1')
				print_cube(c, 0x00D90F56);
			if (is_in_set(c->m.map[c->y][c->x], "0359"))
				print_cube(c, 0x00E0DABD);
			if (is_in_set(c->m.map[c->y][c->x], "468T"))
				print_cube(c, 0x002F29E0);
			if (is_in_set(c->m.map[c->y][c->x], "27"))
				print_cube(c, 0x00F5C02B);
			c->x++;
		}
		c->y++;
	}
	if (c->p.x < 33 && c->pkmn.pokecub)
		print_player(c);
	if (c->p.x < 33 && !c->pkmn.pokecub)
		print_player(c);
}

void	paint_floor_ceiling(t_config *c)
{
	int x;
	int y;

	y = 0;
	while (y < c->r2)
	{
		x = 0;
		while (x < c->r1)
		{
			if (y < c->r2 / 2)
				pixel_put(&c->img, x, y, c->c_rgb);
			else
				pixel_put(&c->img, x, y, c->f_rgb);
			x++;
		}
		y++;
	}
}
