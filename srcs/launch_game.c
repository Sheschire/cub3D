/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemesle <tlemesle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 14:20:55 by tlemesle          #+#    #+#             */
/*   Updated: 2021/04/08 14:46:06 by tlemesle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	game_screen(t_config *c)
{
	int x;
	int y;
	int	color;

	y = 0;
	while (y < c->r2)
	{
		x = 0;
		while (x < c->r1)
		{
			color = c->t[13].addr[(c->t[13].width * y * 4) + x * 4];
			c->img.addr[(y * c->r1 * 4) + x * 4] = color;
			color = c->t[13].addr[(c->t[13].width * y * 4) + x * 4 + 1];
			c->img.addr[(y * c->r1 * 4) + x * 4 + 1] = color;
			color = c->t[13].addr[(c->t[13].width * y * 4) + x * 4 + 2];
			c->img.addr[(y * c->r1 * 4) + x * 4 + 2] = color;
			color = c->t[13].addr[(c->t[13].width * y * 4) + x * 4 + 3];
			c->img.addr[(y * c->r1 * 4) + x * 4 + 3] = color;
			x++;
		}
		y++;
	}
}

void	run_game(t_config *c)
{
	player_movement(c);
	paint_floor_ceiling(c);
	print_fov(c);
	draw_sprites(c);
	minimap_to_window(c);
	if (c->pkmn.pokecub)
	{
		is_item_picked(c);
		event(c);
	}
	normalize_r_angle(c);
}

int		launch_game(t_config *c)
{
	c->img.img = mlx_new_image(c->v.mlx, c->r1, c->r2);
	c->img.addr = mlx_get_data_addr(c->img.img, \
	&c->img.bits_per_pixel, &c->img.line_length, &c->img.endian);
	if (!c->game_started && c->pkmn.pokecub)
		game_screen(c);
	if (c->game_started || !c->pkmn.pokecub)
		run_game(c);
	if (c->bmp_save)
	{
		ft_bmp_saver(c);
		c->bmp_save = 0;
	}
	mlx_put_image_to_window(c->v.mlx, c->v.win, c->img.img, 0, 0);
	free_image(c);
	return (1);
}

void	init_mlx(t_config *c)
{
	keyhook(c);
	mlx_loop_hook(c->v.mlx, launch_game, c);
	mlx_loop(c->v.mlx);
}
