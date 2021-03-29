/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertical_hit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemesle <tlemesle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 14:05:20 by tlemesle          #+#    #+#             */
/*   Updated: 2021/03/29 16:51:58 by tlemesle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	vertical_hit_2(t_config *c)
{
	float	nextx;
	float	nexty;
	
	nextx = c->r.xi;
	nexty = c->r.yi;
	while (nextx >= 0 && nextx < (c->x_max * TILE) && nexty >= 0 && nexty < (c->y_max * TILE))
	{
		if (is_wall(nexty, nextx - c->r.face_left, c))
		{
			if (c->r.dist_p_hit > hypot(nextx - (c->p.x * TILE), nexty - (c->p.y * TILE)))
			{
				c->r.hitx = nextx;
				c->r.hity = nexty;
				c->r.verthit = 1;
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

void	vertical_hit(t_config *c)
{
	c->r.xi = floor(c->p.x) * TILE;
	if (c->r.face_right == 1)
		c->r.xi += TILE;
	c->r.yi = (c->p.y * TILE) + (c->r.xi - (c->p.x * TILE)) * tan(c->r.fov_angle);
	c->r.delt_x = TILE;
	if (c->r.face_left == 1)
		c->r.delt_x *= -1;
	c->r.delt_y = TILE * tan(c->r.fov_angle);
	if ((c->r.face_up == 1 && c->r.delt_y > 0) || (c->r.face_down == 1 && c->r.delt_y < 0))
		c->r.delt_y *= -1;
	vertical_hit_2(c);
}