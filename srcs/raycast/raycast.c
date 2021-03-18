/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemesle <tlemesle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 16:21:14 by tlemesle          #+#    #+#             */
/*   Updated: 2021/03/17 17:05:41 by tlemesle         ###   ########.fr       */
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
//	c->r.fov_angle = remainder(c->r.fov, 2 * PI);
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
	printf("tmp_x = %f\ntmp_y = %f\n", tmp_x, tmp_y);
	printf("dist = %f\n", c->r.dist_p_hit);
	while (i < c->r.dist_p_hit)
	{
		tmp_x = x + cos(c->r.angle) * i;
		tmp_y = y + sin(c->r.angle) * i;
		pixel_put(&c->img, tmp_x, tmp_y, 0x1AD08D);
		i++;
	}
}

void	cast_ray(t_config *c, int column)
{
	update_angle(c);
	horizontal_hit(c);
//	printf("h_hitx = %f\nh_hity = %f\n", c->r.h_hitx, c->r.h_hity);
	vertical_hit(c);
	find_dist_p_hit(c);
	printf("dist = %f\n", c->r.dist_p_hit);
//	print_ray(c);

	float	x;
	float	y;
	float	tmp_x;
	float	tmp_y;
	float	i;
	
	i = 0;
	x = c->p.x * c->abs;
	y = c->p.y * c->ord;
	tmp_x = x;
	tmp_y = y;
	while (!is_in_set(c->m.map[(int)floorf(tmp_y / c->ord)][(int)floorf(tmp_x / c->abs)], "12"))
	{
		tmp_x = x + cos(c->r.angle) * i;
		tmp_y = y + sin(c->r.angle) * i;
		pixel_put(&c->img, tmp_x, tmp_y, 0x1AD08D);
		i += 1;
	}
//	c->r.hitx = tmp_x / c->abs;
//	c->r.hity = tmp_x / c->ord;
//	c->r.dist_p_hit = (float)i;
//	printf("hitx = %f\nhity = %f\n", c->r.hitx, c->r.hity);
//	printf("dist = %f\n", c->r.dist_p_hit);*/
}

void	reset_ray(t_config *c)
{
	c->r.face_y = 0;
	c->r.face_x = 0;
	c->r.h_hitx = 0;
	c->r.h_hity = 0;
	c->r.v_hitx = 0;
	c->r.v_hity = 0;
	c->r.xi = 0;
	c->r.yi = 0;
	c->r.dist_p_hit = 0;
}

void	print_fov(t_config *c)
{
	int		column;

	c->r.n_rays = 1;
//	update_angle(c);
	column = 0;
	while (column < c->r.n_rays)
	{
//		reset_ray(c);
		cast_ray(c, column);
		c->r.fov_angle += c->r.fov / c->r.n_rays;
		column++;
	}
}