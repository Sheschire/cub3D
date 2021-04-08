/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemesle <tlemesle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 13:33:54 by tlemesle          #+#    #+#             */
/*   Updated: 2021/04/08 13:47:50 by tlemesle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../includes/cub3d.h"

int		is_around_with_item(t_config *c, char *set, int item, char new_char)
{
	int	y;

	y = (int)c->p.y;
	if (is_in_set(c->m.map[y][(int)c->p.x + 1], set) && item >= 1)
	{
		c->m.map[y][(int)c->p.x + 1] = new_char;
		return (1);
	}
	if (is_in_set(c->m.map[y][(int)c->p.x - 1], set) && item >= 1)
	{
		c->m.map[y][(int)c->p.x - 1] = new_char;
		return (1);
	}
	if (is_in_set(c->m.map[y - 1][(int)c->p.x], set) && item >= 1)
	{
		c->m.map[y - 1][(int)c->p.x] = new_char;
		return (1);
	}
	if (is_in_set(c->m.map[y + 1][(int)c->p.x], set) && item >= 1)
	{
		c->m.map[y + 1][(int)c->p.x] = new_char;
		return (1);
	}
	return (0);
}

void	encounter_event(t_config *c, int x, int y)
{
	if (c->m.map[y][x] == '6' && y == 8 && x == 31)
	{
		c->p.x += 5;
		play_sound('x');
		play_sound('l');
		play_sound('t');
	}
	if (c->m.map[y][x] == '6' && y == 8 && x == 33)
	{
		c->p.x -= 5;
		play_sound('x');
		play_sound('r');
	}
	if (y == 15 && x == 16 && c->pkmn.ray_encounter == 0)
	{
		c->pkmn.ray_encounter = 1;
		play_sound('x');
		play_sound('z');
		play_sound('q');
	}
}

void	evolution_ronflex_capture(t_config *c)
{
	if (c->pkmn.current_item == 11 && \
	is_around_with_item(c, "8", c->pkmn.candy, 'T'))
	{
		play_sound('y');
		find_sprite(c);
		draw_sprites(c);
		c->pkmn.candy--;
		c->pkmn.progress++;
	}
	if (c->pkmn.current_item == 7 && \
	is_around_with_item(c, "4", c->pokeflute, '0'))
	{
		c->n_sprite--;
		c->pokeflute--;
		play_sound('s');
	}
	if (c->pkmn.current_item == 5 && \
	is_around_with_item(c, "27", c->pokeball, '0'))
	{
		c->pokeball--;
		c->n_sprite--;
		c->pkmn.progress++;
		play_sound('c');
	}
}

void	event(t_config *c)
{
	int	y;
	int	x;

	y = (int)c->p.y;
	x = (int)c->p.x;
	if (is_in_set(c->m.map[y][x], "359"))
	{
		play_sound('o');
		if (c->m.map[y][x] == '3')
			c->pokeball++;
		if (c->m.map[y][x] == '5')
			c->pokeflute++;
		if (c->m.map[y][x] == '9')
			c->pkmn.candy++;
		c->m.map[y][x] = '0';
		c->n_sprite--;
	}
	encounter_event(c, x, y);
	evolution_ronflex_capture(c);
	clean_item(c);
	draw_progression(c);
}