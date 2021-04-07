/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_3d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemesle <tlemesle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 14:22:25 by tlemesle          #+#    #+#             */
/*   Updated: 2021/04/07 13:39:08 by tlemesle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	get_wall_values(t_config *c, int column)
{
	float	dist_proj_plane;
	float	perp_dist;

	perp_dist = c->r.dist_p_hit * cos(c->r.fov_angle - c->r.angle);
	c->buff[column] = perp_dist;
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
	int	off_x;
	int	off_y;
	int color;
	int n_t;

	n_t = get_right_texture(c);
	if (c->r.verthit == 1)
		off_x = (int)(c->r.hity * c->t[n_t].width / TILE) % c->t[n_t].width;
	else
		off_x = (int)(c->r.hitx * c->t[n_t].width / TILE) % c->t[n_t].width;
	while (c->w.w_top < c->w.w_bot)
	{
		off_y = c->w.w_top + (c->w.w_height / 2) - (c->r2 / 2);
		off_y = offset_y * ((float)c->t[n_t].height / c->w.w_height);
		color = c->t[n_t].addr[(c->t[n_t].width * off_y * 4) + off_x * 4];
		c->img.addr[(c->w.w_top * c->r1 * 4) + column * 4] = color;
		color = c->t[n_t].addr[(c->t[n_t].width * off_y * 4) + off_x * 4 + 1];
		c->img.addr[(c->w.w_top * c->r1 * 4) + column * 4 + 1] = color;
		color = c->t[n_t].addr[(c->t[n_t].width * off_y * 4) + off_x * 4 + 2];
		c->img.addr[(c->w.w_top * c->r1 * 4) + column * 4 + 2] = color;
		color = c->t[n_t].addr[(c->t[n_t].width * off_y * 4) + off_x * 4 + 3];
		c->img.addr[(c->w.w_top * c->r1 * 4) + column * 4 + 3] = color;
		c->w.w_top++;
	}
}

void	draw_3d(t_config *c, int column)
{
	get_wall_values(c, column);
	apply_texture(c, column);
}
