/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_3d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemesle <tlemesle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 14:22:25 by tlemesle          #+#    #+#             */
/*   Updated: 2021/03/30 11:53:32 by tlemesle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void    get_wall_values(t_config *c)
{
	float   dist_proj_plane;
	float   perp_dist;
	
	perp_dist = c->r.dist_p_hit * cos(c->r.fov_angle - c->r.angle);
	dist_proj_plane = (c->r1 / 2) / tan(c->r.fov / 2);
	c->w.w_height = (TILE / perp_dist) * dist_proj_plane;
	c->w.w_top = (c->r2 / 2) - (c->w.w_height / 2);
	if (c->w.w_top < 0)
		c->w.w_top = 0;
	c->w.w_bot = (c->r2 / 2) + (c->w.w_height / 2);
	if (c->w.w_bot > c->r2)
		c->w.w_bot = c->r2;
}

int		get_right_texture(t_config *c)
{
	if (c->r.verthit == 0 && c->r.face_up)
		return (0);
	if (c->r.verthit == 0 && c->r.face_down)
		return (1);
	if (c->r.verthit == 1 && c->r.face_left)
		return (2);
	if (c->r.verthit == 1 && c->r.face_right)
		return (3);
	return (-1);
}

void	apply_texture(t_config *c, int column)
{
	int	offset_x;
	int	offset_y;
	int color;
	int n_t;

	n_t = get_right_texture(c);
	if (c->r.verthit == 1)
		offset_x = (int)(c->r.hity * c->t[n_t].width / TILE) % c->t[n_t].width;
	else
		offset_x = (int)(c->r.hitx * c->t[n_t].width / TILE) % c->t[n_t].width;
	while (c->w.w_top < c->w.w_bot)
	{
		offset_y = c->w.w_top + (c->w.w_height / 2) - (c->r2 / 2);
		offset_y = offset_y * ((float)c->t[n_t].height / c->w.w_height);
		color = c->t[n_t].addr[(c->t[n_t].width * offset_y) + offset_x];
		if (color != 0x000000 && color != -16777216)
			c->img.addr[(c->w.w_top * c->r1) + column] = color;
		c->w.w_top++;
	}
}

void    draw_3d(t_config *c, int column)
{
	get_wall_values(c);
//	apply_texture(c, column);
/*	while (c->w.w_top < c->w.w_bot)
	{
		if (c->r.verthit == 0)
			pixel_put(&c->img, column, c->w.w_top, 0x00EEEEEE);
		else
			pixel_put(&c->img, column, c->w.w_top, 0x00FFFFFF);
		c->w.w_top++;
	}*/
}