/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horizontal_hit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemesle <tlemesle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 14:05:32 by tlemesle          #+#    #+#             */
/*   Updated: 2021/03/17 17:04:56 by tlemesle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	horizontal_hit_2(t_config *c)
{
	float	nextx;
	float	nexty;
	
	nextx = c->r.xi;
	nexty = c->r.yi;
	while (nextx >= 0 && nextx <= c->r1 && nexty >= 0 && nexty <= c->r2)
	{
		if (c->r.face_y == 1)
			nexty--;
		if (is_in_set(c->m.map[(int)(nexty / c->ord + 0.0001)][(int)(nextx / c->abs + 0.0001)], "12"))
		{
			c->r.h_hitx = nextx;
			c->r.h_hity = nexty;
	//		printf("Hhitx = %f\n", c->r.h_hitx / c->abs);
	//		printf("Hhity = %f\n", c->r.h_hity / c->ord);
			break;
		}
		else
		{
			nextx += c->r.delt_x;
			nexty = c->r.delt_y;
		}
	}
}

void	horizontal_hit(t_config *c)
{
	c->r.yi = floor(c->p.y) * c->ord;
//	printf("%f\n", c->r.yi);
//	printf("c->p.y = %f\n", c->p.y);
//	printf("c->ord = %f\n", c->ord);
//	printf("yi = %f\n", c->r.yi);
	if (c->r.face_y == -1)
		c->r.yi += c->ord;
	c->r.xi = c->p.x + (c->r.yi - c->p.y) / tan(c->r.fov_angle);
	c->r.delt_y = c->ord;
	if (c->r.face_y == 1)
		c->r.delt_y *= -1;
	c->r.delt_x = c->abs / tan(c->r.fov_angle);
	if (c->r.face_x == -1 && c->r.delt_x > 0)
		c->r.delt_x *= -1;
	if (c->r.face_x == 1 && c->r.delt_x < 0)
		c->r.delt_x *= -1;
	horizontal_hit_2(c);
}