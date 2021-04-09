/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_item.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemesle <tlemesle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 13:39:38 by tlemesle          #+#    #+#             */
/*   Updated: 2021/04/07 19:10:49 by tlemesle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	draw_item(t_config *c, int n)
{
	int		co;
	float	i;
	float	j;

	j = 0;
	c->yb = (float)c->r2 * 0.6 - 1;
	while (++c->yb <= (c->r2 - 1))
	{
		c->xb = ((float)c->r1 * 0.4 - 1);
		i = 0;
		while (++c->xb < (float)(c->r1 * 0.65 - 1))
		{
			co = c->t[n].addr[(int)((int)j * (c->t[n].width * 4) + (int)i * 4)];
			if (co != 0x0000000)
				c->img.addr[(int)c->yb * (c->r1 * 4) + (int)c->xb * 4] = co;
			co = c->t[n].addr[((int)j * (c->t[n].width * 4) + (int)i * 4 + 1)];
			if (co != 0x0000000)
				c->img.addr[(int)c->yb * (c->r1 * 4) + (int)c->xb * 4 + 1] = co;
			co = c->t[n].addr[((int)j * (c->t[n].width * 4) + (int)i * 4 + 2)];
			if (co != 0x000000)
				c->img.addr[(int)c->yb * (c->r1 * 4) + (int)c->xb * 4 + 2] = co;
			i += (float)(c->t[n].width) / (float)((c->r1) * 0.25);
		}
		j += (float)(c->t[n].height - 1) / (float)(c->r2 * 0.5);
	}
}

void	switch_item(t_config *c)
{
	if (c->pkmn.current_item == 5)
	{
		if (c->pokeflute)
			c->pkmn.current_item = 7;
		if (!c->pokeflute && c->pkmn.candy)
			c->pkmn.current_item = 11;
	}
	else if (c->pkmn.current_item == 7)
	{
		if (c->pkmn.candy)
			c->pkmn.current_item = 11;
		if (!c->pkmn.candy && c->pokeball)
			c->pkmn.current_item = 5;
	}
	else if (c->pkmn.current_item == 11)
	{
		if (c->pokeball)
			c->pkmn.current_item = 5;
		if (!c->pokeball && c->pokeflute)
			c->pkmn.current_item = 7;
	}
}

void	is_item_picked(t_config *c)
{
	if (c->pkmn.current_item == 0)
	{
		if (c->pokeball)
			c->pkmn.current_item = 5;
		if (c->pokeflute)
			c->pkmn.current_item = 7;
		if (c->pkmn.candy)
			c->pkmn.current_item = 11;
	}
	if (c->pkmn.current_item != 0)
		draw_item(c, c->pkmn.current_item);
}

void	clean_item(t_config *c)
{
	if (c->pkmn.current_item == 5 && c->pokeball == 0)
	{
		if (c->pokeflute)
			c->pkmn.current_item = 7;
		if (!c->pokeflute && c->pkmn.candy)
			c->pkmn.current_item = 11;
	}
	else if (c->pkmn.current_item == 7 && c->pokeflute == 0)
	{
		if (c->pkmn.candy)
			c->pkmn.current_item = 11;
		if (!c->pkmn.candy && c->pokeball)
			c->pkmn.current_item = 5;
	}
	else if (c->pkmn.current_item == 11 && c->pkmn.candy == 0)
	{
		if (c->pokeball)
			c->pkmn.current_item = 5;
		if (!c->pokeball && c->pokeflute)
			c->pkmn.current_item = 7;
	}
	if (c->pkmn.candy || c->pokeball || c->pokeflute)
		draw_item(c, c->pkmn.current_item);
}
