/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemesle <tlemesle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 11:38:23 by tlemesle          #+#    #+#             */
/*   Updated: 2021/03/10 15:31:31 by tlemesle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	is_collision(t_config *c)
{
	int		y;
	int		x;
	int		y_ord;
	int		x_abs;
	
	x = (int)floorf(c->p.x);
	y = (int)floorf(c->p.y);
	y_ord = (int)floorf(c->p.y + c->p.y / c->ord);
	x_abs = (int)floorf(c->p.x + c->p.x / c->abs);
	printf("y_ord = %d\nx_abs = %d\n", y_ord, x_abs);
	if ((is_in_set(c->m.map[y][x], "12") || is_in_set(c->m.map[y_ord][x], "12")) && c->p.walk == 1)
		c->p.y += DIST;
	if ((is_in_set(c->m.map[y][x], "12") || is_in_set(c->m.map[y_ord][x], "12")) && c->p.walk == -1)
		c->p.y -= DIST;
	if ((is_in_set(c->m.map[y][x], "12") || is_in_set(c->m.map[y][x_abs], "12")) && c->p.left == 1)
		c->p.x += DIST;
	if ((is_in_set(c->m.map[y][x], "12") || is_in_set(c->m.map[y][x_abs], "12")) && c->p.right == 1)
		c->p.x -= DIST;
}

void	player_movement(t_config *c)
{
	if (c->p.walk == 1)
		c->p.y -= DIST;
	if (c->p.walk == -1)
		c->p.y += DIST;
	if (c->p.left == 1)
		c->p.x -= DIST;
	if (c->p.right == 1)
		c->p.x += DIST;
	is_collision(c);
}
