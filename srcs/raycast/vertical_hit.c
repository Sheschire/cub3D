/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertical_hit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemesle <tlemesle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 14:05:20 by tlemesle          #+#    #+#             */
/*   Updated: 2021/03/19 13:58:57 by tlemesle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void    find_dist_p_hit(t_config *c)
{
    float	dist_x;
	float	dist_y;
	float	px;
	float	py;

	px = c->p.x * c->abs;
	py = c->p.y * c->ord;
	dist_x = sqrt((c->r.h_hitx - px) * (c->r.h_hitx - px) + (c->r.h_hity - py) * (c->r.h_hity - py));
	dist_y = sqrt((c->r.v_hitx - px) * (c->r.v_hitx - px) + (c->r.v_hity - py) * (c->r.v_hity - py));
	if (c->r.h_hitx == 0.000 || c->r.h_hity == 0.000)
		dist_x = 2147483647;
	if (c->r.v_hitx == 0.000 || c->r.v_hity == 0.000)
		dist_y = 2147483647;
//	printf("distx = %f\ndisty = %f\n", dist_x, dist_y);
	if (dist_x < dist_y)
		c->r.dist_p_hit = dist_x;
	if (dist_x > dist_y)
		c->r.dist_p_hit = dist_y;
}

void	vertical_hit_2(t_config *c)
{
	float	nextx;
	float	nexty;
	
	nextx = c->r.xi;
	nexty = c->r.yi;
	while (nextx >= 0 && nextx < (c->x_max * c->abs) && nexty >= 0 && nexty < (c->y_max * c->ord))
	{
		if (c->r.face_x == -1)
			nextx--;
		if (is_in_set(c->m.map[(int)(nexty / c->ord)][(int)(nextx / c->abs)], "12"))
		{
			c->r.v_hitx = nextx;
			c->r.v_hity = nexty;
			
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
	c->r.xi = floor((c->p.x * c->abs) / c->abs) * c->abs;
	if (c->r.face_x == 1)
		c->r.xi += c->abs;
	c->r.yi = (c->p.y * c->ord) + (c->r.xi - (c->p.x * c->abs)) * tan(c->r.fov_angle);
	c->r.delt_x = c->abs;
	if (c->r.face_x == -1)
		c->r.delt_x *= -1;
	c->r.delt_y = c->ord * tan(c->r.fov_angle);
	if ((c->r.face_y == 1 && c->r.delt_y > 0) || (c->r.face_y == -1 && c->r.delt_y < 0))
		c->r.delt_y *= -1;
	vertical_hit_2(c);
}