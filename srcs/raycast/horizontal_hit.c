/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horizontal_hit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemesle <tlemesle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 14:05:32 by tlemesle          #+#    #+#             */
/*   Updated: 2021/03/26 10:18:36 by tlemesle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	horizontal_hit_2(t_config *c)
{
	float	nextx;
	float	nexty;
	
	nextx = c->r.xi;
	nexty = c->r.yi;
	while (nextx >= 0 && nextx < (c->x_max * c->abs) && nexty >= 0 && nexty < (c->y_max * c->abs))
	{
		if (c->r.face_y == 1)
			nexty--;
		if (is_in_set(c->m.map[(int)(nexty / c->abs)][(int)(nextx / c->abs)], "12"))
		{
			c->r.h_hitx = nextx;
			c->r.h_hity = nexty;
			
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
	c->r.yi = floor((c->p.y * c->abs) / c->abs) * c->abs;
	if (c->r.face_y == -1)
		c->r.yi += c->abs;
	c->r.xi = (c->p.x * c->abs) + (c->r.yi - (c->p.y * c->abs)) / tan(c->r.fov_angle);
	c->r.delt_y = c->abs;
	if (c->r.face_y == 1)
		c->r.delt_y *= -1;
	c->r.delt_x = c->abs / tan(c->r.fov_angle);
	if ((c->r.face_x == -1 && c->r.delt_x > 0) || (c->r.face_x == 1 && c->r.delt_x < 0))
		c->r.delt_x *= -1;
	horizontal_hit_2(c);
}