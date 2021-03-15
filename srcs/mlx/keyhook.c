/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemesle <tlemesle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 09:24:36 by tlemesle          #+#    #+#             */
/*   Updated: 2021/03/15 15:57:15 by tlemesle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	win_close(t_config *c)
{
	mlx_destroy_window(c->v.mlx, c->v.win);
	exit(0);
}

int		key_press(int keycode, t_config *c)
{
	if (keycode == UP_ARROW || keycode == W)
		c->p.walk = 1;
	if (keycode == DOWN_ARROW || keycode == S)
		c->p.walk = -1;
	if (keycode == A)
		c->p.left = 1;
	if (keycode == D)
		c->p.right = 1;
	if (keycode == ESC)
		win_close(c);
	if (keycode == SHIFT)
		c->p.speed *= 2;
	if (keycode == LEFT_ARROW)
		c->r.dir = -1;
	if (keycode == RIGHT_ARROW)
		c->r.dir = 1;
	return (1);
}

int	key_release(int keycode, t_config *c)
{
	if (keycode == UP_ARROW || keycode == W)
		c->p.walk = 0;
	if (keycode == DOWN_ARROW || keycode == S)
		c->p.walk = 0;
	if (keycode == A)
		c->p.left = 0;
	if (keycode == D)
		c->p.right = 0;
	if (keycode == SHIFT)
		c->p.speed /= 2;
	if (keycode == LEFT_ARROW)
		c->r.dir = 0;
	if (keycode == RIGHT_ARROW)
		c->r.dir = 0;
	return (1);
}

int	keyhook(t_config *c)
{
	mlx_hook(c->v.win, 2, 1L<<0, key_press, c);
	mlx_hook(c->v.win, 3, 1L<<1, key_release, c);
	return (1);
}