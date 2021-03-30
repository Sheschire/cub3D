/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemesle <tlemesle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 16:21:14 by tlemesle          #+#    #+#             */
/*   Updated: 2021/03/30 09:18:40 by tlemesle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	update_ray(t_config *c)
{
	if (c->r.fov_angle > 2 * PI)
		c->r.fov_angle -= 2 * PI;
	if (c->r.fov_angle < 2 * -PI)
		c->r.fov_angle += 2 * PI;
	if (c->r.fov_angle < 0)
		c->r.fov_angle += 2 * PI;
	if (c->r.fov_angle > 0 && c->r.fov_angle < PI)
		c->r.face_down = 1;
	else
		c->r.face_up = 1;
	if (c->r.fov_angle < 0.5 * PI || c->r.fov_angle > 1.5 * PI)
		c->r.face_right = 1;
	else
		c->r.face_left = 1;
}

void	print_ray(t_config *c)
{
	float	x;
	float	y;
	float	tmp_x;
	float	tmp_y;
	float	i;

	i = 0;
	x = c->p.x * (TILE / SCALE);
	y = c->p.y * (TILE / SCALE);
	tmp_x = x;
	tmp_y = y;
	while (i < 10)
	{
		tmp_x = x + cos(c->r.fov_angle) * i;
		tmp_y = y + sin(c->r.fov_angle) * i;
			if (c->m.map[(int)floor(tmp_y / (TILE / SCALE))][(int)floor(tmp_x / (TILE / SCALE))] != '1' && tmp_x < c->r1 && tmp_y < c->r2)
				pixel_put(&c->img, tmp_x, tmp_y, 0x1AD08D);
		i++;
	}
}

void	reset_ray(t_config *c)
{
	c->r.face_up = 0;
	c->r.face_down = 0;
	c->r.face_left = 0;
	c->r.face_right = 0;
	c->r.hitx = 0;
	c->r.hity = 0;
	c->r.xi = 0;
	c->r.yi = 0;
	c->r.delt_x = 0;
	c->r.delt_y = 0;
	c->r.dist_p_hit = 2147483647;
	c->r.verthit = 0;
}


void	cast_ray(t_config *c)
{
	horizontal_hit(c);
	vertical_hit(c);
//	print_ray(c);
}

void	print_fov(t_config *c)
{
	int		column;
	
	c->r.n_rays = c->r1;
	c->r.angle += c->r.dir * c->r.speed;
	c->r.fov_angle = c->r.angle - (c->r.fov / 2);
	column = 0;
	while (column < c->r.n_rays)
	{
		reset_ray(c);
		update_ray(c);
		cast_ray(c);
		draw_3d(c, column);
		c->r.fov_angle += c->r.fov / c->r.n_rays;
		column++;
	}
}