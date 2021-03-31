/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horizontal_hit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemesle <tlemesle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 14:05:32 by tlemesle          #+#    #+#             */
/*   Updated: 2021/03/31 16:38:23 by tlemesle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int        is_wall(float y, float x, t_config *c)
{
    int    mapx;
    int    mapy;

    mapx = floor(x / TILE);
    mapy = floor(y / TILE);
    if (x < 0 || x > c->x_max * TILE ||
        y < 0 || y > c->y_max * TILE ||
        mapx > c->x_max - 1 || mapy > c->y_max - 1)
        return (1);
    if (c->m.map[mapy][mapx] == '1')
        return (1);
    return (0);
}

void	horizontal_hit_2(t_config *c)
{
	float	nextx;
	float	nexty;
	
	nextx = c->r.xi;
	nexty = c->r.yi;
	while (nextx >= 0 && nextx < (c->x_max * TILE) && nexty >= 0 && nexty < (c->y_max * TILE))
	{
		if (is_wall(nexty - c->r.face_up, nextx, c))
		{
			if (c->r.dist_p_hit > hypot(nextx - (c->p.x * TILE), nexty - (c->p.y * TILE)))
			{
				c->r.hitx = nextx;
				c->r.hity = nexty;
				c->r.verthit = 0;
				c->r.dist_p_hit = hypot(nextx - (c->p.x * TILE), nexty - (c->p.y * TILE));
			}
			break;
		}
		else
		{
			nextx += c->r.delt_x;
			nexty += c->r.delt_y;
		}
	}
}

void	horizontal_hit(t_config *c)
{
	c->r.yi = floor(c->p.y) * TILE;
	if (c->r.face_down == 1)
		c->r.yi += TILE;
	c->r.xi = (c->p.x * TILE) + (c->r.yi - (c->p.y * TILE)) / tan(c->r.fov_angle);
	c->r.delt_y = TILE;
	if (c->r.face_up == 1)
		c->r.delt_y *= -1;
	c->r.delt_x = TILE / tan(c->r.fov_angle);
	if ((c->r.face_left == 1 && c->r.delt_x > 0) || (c->r.face_right == 1 && c->r.delt_x < 0))
		c->r.delt_x *= -1;
	horizontal_hit_2(c);
}