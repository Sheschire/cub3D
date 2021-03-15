/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemesle <tlemesle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 16:21:14 by tlemesle          #+#    #+#             */
/*   Updated: 2021/03/15 16:26:49 by tlemesle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	update_angle(t_config *c)
{
	c->r.angle += c->r.dir * c->r.speed;
	c->r.fov_angle = c->r.angle - (c->r.fov / 2);
	if (c->r.angle > 2 * PI)
		c->r.angle -= 2 * PI;
	if (c->r.angle < 2 * -PI)
		c->r.angle += 2 * PI;
	if (c->r.angle < 0)
		c->r.angle += 2 * PI;
	if (c->r.angle > 0 && c->r.angle < PI)
		c->r.face_y = -1;
	else
		c->r.face_y = 1;
	if (c->r.angle < 0.5 * PI || c->r.angle > 1.5 * PI)
		c->r.face_x = 1;
	else
		c->r.face_x = -1;
//	printf("face_x = %d\nface_y = %d\nangle = %f\n", c->r.face_x, c->r.face_y, c->r.angle);
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