/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemesle <tlemesle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 11:38:23 by tlemesle          #+#    #+#             */
/*   Updated: 2021/03/12 14:53:27 by tlemesle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	update_angle(t_config *c)
{
	c->r.angle += c->r.dir * c->r.speed;
	c->r.fov_angle = c->r.angle - (c->r.fov / 2);
}

void	is_collision(t_config *c)
{
	int		y;
	int		x;
	int		y_ord;
	int		x_abs;
	
	x = (int)floorf(c->p.x);
	y = (int)floorf(c->p.y);
	if (is_in_set(c->m.map[y][x], "12") && c->p.walk == 1)
		c->p.y += DIST * c->p.speed;
	if (is_in_set(c->m.map[y][x], "12") && c->p.walk == -1)
		c->p.y -= DIST * c->p.speed;
	if (is_in_set(c->m.map[y][x], "12") && c->p.left == 1)
		c->p.x += DIST * c->p.speed;
	if (is_in_set(c->m.map[y][x], "12") && c->p.right == 1)
		c->p.x -= DIST * c->p.speed;
}

void	player_movement(t_config *c)
{
	if (c->p.walk == 1)
		c->p.y -= DIST * c->p.speed;
	if (c->p.walk == -1)
		c->p.y += DIST * c->p.speed;
	if (c->p.left == 1)
		c->p.x -= DIST * c->p.speed;
	if (c->p.right == 1)
		c->p.x += DIST * c->p.speed;
	is_collision(c);
}
