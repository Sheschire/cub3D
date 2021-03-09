/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemesle <tlemesle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 09:24:36 by tlemesle          #+#    #+#             */
/*   Updated: 2021/03/09 12:00:37 by tlemesle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	win_close(int keycode, t_config *c)
{
	if (keycode == 53)
	{
		mlx_destroy_window(c->v.mlx, c->v.win);
		exit(0);
	}
	return (1);
}

int	key_decoder(int keycode, t_config *c)
{
	win_close(keycode, c);
	player_movement(keycode, c);
	return (1);
}

int	keyhook(t_config *c)
{
	mlx_key_hook(c->v.win, key_decoder, c);
	return (1);
}