/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemesle <tlemesle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 16:21:14 by tlemesle          #+#    #+#             */
/*   Updated: 2021/03/26 17:04:52 by tlemesle         ###   ########.fr       */
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
		c->r.face_y = -1;
	else
		c->r.face_y = 1;
	if (c->r.fov_angle < 0.5 * PI || c->r.fov_angle > 1.5 * PI)
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
	float	i;

	i = 0;
	x = c->p.x * 32;
	y = c->p.y * 32;
	tmp_x = x;
	tmp_y = y;
	while (i < c->r.dist_p_hit)
	{
		tmp_x = x + cos(c->r.fov_angle) * i;
		tmp_y = y + sin(c->r.fov_angle) * i;
		if (c->m.map[(int)floor(tmp_y / TILE)][(int)floor(tmp_x / TILE)] != '1')
			pixel_put(&c->img, tmp_x, tmp_y, 0x1AD08D);
		i++;
	}
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
	c->r.delt_x = 0;
	c->r.delt_y = 0;
	c->r.dist_p_hit = 0;
}


void	cast_ray(t_config *c)
{
	horizontal_hit(c);
	vertical_hit(c);
	find_dist_p_hit(c);
	print_ray(c);
//	printf("V x = %f\n", c->r.v_hitx / TILE);
//	printf("V y = %f\n", c->r.v_hity / c->ord);
//	printf("H x = %f\n", c->r.h_hitx / TILE);
//	printf("H y = %f\n", c->r.h_hity / c->ord);
//	printf("dist = %f\n", c->r.dist_p_hit / c->ord);
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
		c->r.fov_angle += c->r.fov / c->r.n_rays;
		column++;
	}
}