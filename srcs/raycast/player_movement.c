/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemesle <tlemesle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 11:38:23 by tlemesle          #+#    #+#             */
/*   Updated: 2021/04/07 14:08:27 by tlemesle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	player_orientation_2(t_config *c)
{
	if (c->p.orient == 'N')
	{
		c->r.angle = 1.5 * PI;
		c->p.xdir = 0;
		c->p.ydir = -1;
		c->p.planx = -0.66;
		c->p.plany = 0;
	}
	else if (c->p.orient == 'S')
	{
		c->r.angle = 0.5 * PI;
		c->p.xdir = 0;
		c->p.ydir = 1;
		c->p.planx = 0.66;
		c->p.plany = 0;
	}
}

void	player_orientation(t_config *c)
{
	if (c->p.orient == 'W')
	{
		c->r.angle = PI;
		c->p.xdir = -1;
		c->p.ydir = 0;
		c->p.planx = 0;
		c->p.plany = 0.66;
	}
	else if (c->p.orient == 'E')
	{
		c->r.angle = 0;
		c->p.xdir = 1;
		c->p.ydir = 0;
		c->p.planx = 0;
		c->p.plany = -0.66;
	}
	player_orientation_2(c);
}

void	update_var_angle(t_config *c)
{
	float	tmpx;
	float	tmpplanx;
	float	tmpangle;

	tmpx = c->p.xdir;
	tmpplanx = c->p.planx;
	tmpangle = c->r.dir * c->r.speed;
	c->p.xdir = c->p.xdir * cos(tmpangle) - c->p.ydir * sin(tmpangle);
	c->p.ydir = tmpx * sin(tmpangle) + c->p.ydir * cos(tmpangle);
	c->p.planx = c->p.planx * cos(tmpangle) - c->p.plany * sin(tmpangle);
	c->p.plany = tmpplanx * sin(tmpangle) + c->p.plany * cos(tmpangle);
}

void	update_player(t_config *c, float step, char var)
{
	int		tmpx;
	int		tmpy;

	tmpx = (int)floor(c->p.x);
	tmpy = (int)floor(c->p.y);
	if (tmpx > c->x_max - 1 || tmpy > c->y_max - 1 || tmpx < 0 || tmpy < 0 ||
	is_in_set(c->m.map[tmpy][tmpx], "12478T"))
	{
		if (var == 'x')
			c->p.x = c->p.x - cos(c->r.angle) * step;
		else if (var == 'y')
			c->p.y = c->p.y - sin(c->r.angle) * step;
		else if (var == 'l')
		{
			c->p.x = c->p.x + c->p.ydir * c->p.speed;
			c->p.y = c->p.y - c->p.xdir * c->p.speed;
		}
		else if (var == 'r')
		{
			c->p.x = c->p.x - c->p.ydir * c->p.speed;
			c->p.y = c->p.y + c->p.xdir * c->p.speed;
		}
	}
}

void	player_movement(t_config *c)
{
	float step;

	step = c->p.walk * c->p.speed;
	c->r.angle += c->r.dir * c->r.speed;
	c->p.x = c->p.x + cos(c->r.angle) * step;
	update_player(c, step, 'x');
	c->p.y = c->p.y + sin(c->r.angle) * step;
	update_player(c, step, 'y');
	if (c->p.right == 1 && c->p.left == 0)
	{
		c->p.x = c->p.x - c->p.ydir * c->p.speed;
		c->p.y = c->p.y + c->p.xdir * c->p.speed;
		update_player(c, step, 'l');
	}
	else if (c->p.right == 0 && c->p.left == 1)
	{
		c->p.x = c->p.x + c->p.ydir * c->p.speed;
		c->p.y = c->p.y - c->p.xdir * c->p.speed;
		update_player(c, step, 'r');
	}
	update_var_angle(c);
}
