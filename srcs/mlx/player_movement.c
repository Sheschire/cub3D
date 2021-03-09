/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemesle <tlemesle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 11:38:23 by tlemesle          #+#    #+#             */
/*   Updated: 2021/03/09 11:59:40 by tlemesle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void    player_movement(int keycode, t_config *c)
{
	if (keycode == UP_ARROW || keycode == W)
		c->p.y -= 0.5;
	if (keycode == DOWN_ARROW || keycode == S)
		c->p.y += 0.5;
	if (keycode == A)
		c->p.x -= 0.5;
	if (keycode == D)
		c->p.x += 0.5;
/*	if (keycode == UP_ARROW || keycode == W)
		c->p.forward = 1;
	if (keycode == DOWN_ARROW || keycode == S)
		c->p.backward = 1;
	if (keycode == A)
		c->p.left = 1;
	if (keycode == D)
		c->p.right = 1;*/
	minimap_to_window(c);
}