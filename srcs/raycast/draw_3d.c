/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_3d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemesle <tlemesle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 14:22:25 by tlemesle          #+#    #+#             */
/*   Updated: 2021/03/30 10:15:42 by tlemesle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void    get_wall_values(t_config *c)
{
	float   dist_proj_plane;
	float   wall_height;
	float   perp_dist;
	int     wall_strip;
	
	perp_dist = c->r.dist_p_hit * cos(c->r.fov_angle - c->r.angle);
	dist_proj_plane = (c->r1 / 2) / tan(c->r.fov / 2);
	wall_height = (TILE / perp_dist) * dist_proj_plane;
	wall_strip = (int)wall_height;
	c->w.w_top = (c->r2 / 2) - (wall_strip / 2);
	if (c->w.w_top < 0)
		c->w.w_top = 0;
	c->w.w_bot = (c->r2 / 2) + (wall_strip / 2);
	if (c->w.w_bot > c->r2)
		c->w.w_bot = c->r2;
}

void	get_right_texture(t_config *c)
{
	if (c->r.verthit == 0 && c->r.face_up)
		return (0);
	if (c->r.verthit == 0 && c->r.face_down)
		return (1);
	if (c->r.verthit == 1 && c->r.face_left)
		return (2);
	if (c->r.verthit == 1 && c->r.face_right)
		return (3);
}

void	apply_texture(t_config *c)
{
	int	offset_x;
	int	offset_y;
	int color;
	int n_t;

	n_t = get_right_texture(c);
//	if (c->r.verthit == 1)
//		offset_x = (int)(c->r.hity *)
}

void    draw_3d(t_config *c, int column)
{
	get_wall_values(c);
	apply_texture(c);
	while (c->w.w_top < c->w.w_bot)
	{
		if (c->r.verthit == 0)
			pixel_put(&c->img, column, c->w.w_top, 0x00EEEEEE);
		else
			pixel_put(&c->img, column, c->w.w_top, 0x00FFFFFF);
		c->w.w_top++;
	}
}