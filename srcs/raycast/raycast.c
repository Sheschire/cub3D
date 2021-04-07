/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemesle <tlemesle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 16:21:14 by tlemesle          #+#    #+#             */
/*   Updated: 2021/04/07 14:12:59 by tlemesle         ###   ########.fr       */
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
}

void	print_fov(t_config *c)
{
	int	column;

	c->r.n_rays = c->r1;
	column = 0;
	while (column < c->r.n_rays)
	{
		c->r.fov_angle = c->r.angle + atan((column - c->r1 / 2) \
		/ ((c->r1 / 2) / tan(c->r.fov / 2)));
		reset_ray(c);
		update_ray(c);
		cast_ray(c);
		draw_3d(c, column);
		column++;
	}
}
