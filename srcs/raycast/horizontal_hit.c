/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horizontal_hit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemesle <tlemesle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 14:05:32 by tlemesle          #+#    #+#             */
/*   Updated: 2021/04/07 14:05:53 by tlemesle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		is_wall(float y, float x, t_config *c)
{
	int	mapx;
	int	mapy;

	mapx = floor(x / TILE);
	mapy = floor(y / TILE);
	if (x < 0 || x > c->x_max * TILE ||
		y < 0 || y > c->y_max * TILE ||
		mapx > c->x_max - 1 || mapy > c->y_max - 1)
		return (1);
	if (is_in_set(c->m.map[mapy][mapx], "1"))
		return (1);
	return (0);
}

void	horizontal_hit_2(t_config *c)
{
	while (c->r.xi >= 0 && c->r.xi < (c->x_max * TILE) && \
	c->r.yi >= 0 && c->r.yi < (c->y_max * TILE))
	{
		if (is_wall(c->r.yi - c->r.face_up, c->r.xi, c))
		{
			if (c->r.dist_p_hit > hypot(c->r.xi - (c->p.x * TILE), \
			c->r.yi - (c->p.y * TILE)))
			{
				c->r.hitx = c->r.xi;
				c->r.hity = c->r.yi;
				c->r.verthit = 0;
				c->r.dist_p_hit = hypot(c->r.xi - (c->p.x * TILE), \
				c->r.yi - (c->p.y * TILE));
			}
			break ;
		}
		else
		{
			c->r.xi += c->r.delt_x;
			c->r.yi += c->r.delt_y;
		}
	}
}

void	horizontal_hit(t_config *c)
{
	c->r.yi = floor(c->p.y) * TILE;
	if (c->r.face_down == 1)
		c->r.yi += TILE;
	c->r.xi = (c->p.x * TILE) + (c->r.yi - (c->p.y * TILE)) \
	/ tan(c->r.fov_angle);
	c->r.delt_y = TILE;
	if (c->r.face_up == 1)
		c->r.delt_y *= -1;
	c->r.delt_x = TILE / tan(c->r.fov_angle);
	if ((c->r.face_left == 1 && c->r.delt_x > 0) || \
	(c->r.face_right == 1 && c->r.delt_x < 0))
		c->r.delt_x *= -1;
	horizontal_hit_2(c);
}
