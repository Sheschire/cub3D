/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemesle <tlemesle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 09:24:36 by tlemesle          #+#    #+#             */
/*   Updated: 2021/03/08 11:58:41 by tlemesle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	win_close(int keycode, t_vars *v)
{
	if (keycode == 53)
	{
		mlx_destroy_window(v->mlx, v->win);
		exit(0);
	}
	return (1);
}

int	key_decoder(int keycode, t_vars *v, t_config *c)
{
	win_close(keycode, v);
	player_movement(keycode, c);
	return (1);
}

int	keyhook(t_config *c, t_vars *v, t_data *img)
{
	mlx_key_hook(v->win, key_decoder, v);
	return (1);
}