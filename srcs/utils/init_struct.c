/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemesle <tlemesle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 15:32:01 by tlemesle          #+#    #+#             */
/*   Updated: 2021/04/08 14:46:24 by tlemesle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_player(t_config *c)
{
	c->p.x = 0;
	c->p.y = 0;
	c->p.orient = 0;
	c->p.pos_count = 0;
	c->p.walk = 0;
	c->p.left = 0;
	c->p.right = 0;
	c->p.speed = 0.05;
}

void	init_ray(t_config *c)
{
	c->r.speed = 2 * (PI / 180);
	c->r.angle = 0;
	c->r.dir = 0;
	c->r.fov = 66 * (PI / 180);
	c->r.fov_angle = 0;
	c->r.n_rays = 0;
	c->r.verthit = 0;
}

void	init_pkmn(t_config *c)
{
	c->pkmn.pokecub = 0;
	c->pkmn.ray_encounter = 0;
	c->pkmn.candy = 0;
	c->pkmn.current_item = 0;
	c->pkmn.progress = 0;
	c->pokeflute = 0;
	c->pokeball = 0;
}

void	init_sprites(t_config *c)
{
	if (c->pkmn.pokecub == 1)
	{
		get_path_bonus(c);
		play_sound('r');
	}
	c->n_sprite = 0;
	count_sprites(c);
	c->sp = malloc(sizeof(t_sprite) * c->n_sprite);
	find_sprite(c);
}

void	ft_init_t_config(t_config *c)
{
	c->buff = 0;
	c->bmp_save = 0;
	c->game_started = 0;
	c->r1 = 0;
	c->r2 = 0;
	c->f_rgb = -1;
	c->c_rgb = -1;
	c->x = 0;
	c->y = 0;
	c->m.line = NULL;
	c->m.map = NULL;
	init_player(c);
	init_ray(c);
	init_pkmn(c);
}
