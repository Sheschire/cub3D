/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertical_hit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemesle <tlemesle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 14:05:20 by tlemesle          #+#    #+#             */
/*   Updated: 2021/03/18 16:16:29 by tlemesle         ###   ########.fr       */
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
	if (dist_x < dist_y)
		c->r.dist_p_hit = dist_x;
	else
		c->r.dist_p_hit = dist_y;
//	printf("dist = %f\n", c->r.dist_p_hit / c->ord);
}

void	vertical_hit_2(t_config *c)
{
	float	nextx;
	float	nexty;
	
	nextx = c->r.xi;
	nexty = c->r.yi;
	while (nextx >= 0 && nextx <= c->r1 && nexty >= 0 && nexty <= c->r2)
	{
		if (c->r.face_x == -1)
			nextx--;
		if (is_in_set(c->m.map[(int)(nexty / c->ord)][(int)(nextx / c->abs)], "12") && nexty < c->r2 && nextx < c->r1)
		{
			c->r.v_hitx = nextx;
			c->r.v_hity = nexty;
//			printf("V x = %f\n", c->r.h_hitx / c->abs);
//			printf("V y = %f\n", c->r.h_hity / c->ord);
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
	if (c->r.face_y == 1 && c->r.delt_y > 0)
		c->r.delt_y *= -1;
	if (c->r.face_y == -1 && c->r.delt_y < 0)
		c->r.delt_y *= -1;
	vertical_hit_2(c);
}