#include "../../includes/cub3d.h"

void	draw_item(t_config *c, int n)
{
	int		color;
	float	i;
	float	j;

	j = 0;
	c->y_tmp = (float)c->r2 * 0.6 - 1;
	while (++c->y_tmp <= (c->r2 - 1))
	{
		c->x_tmp = ((float)c->r1 * 0.4 - 1);
		i = 0;
		while (++c->x_tmp < (float)(c->r1 * 0.65 - 1))
		{
			color = c->t[n].addr[(int)((int)j * (c->t[n].width * 4) + (int)i * 4)];
			if (color != 0x0000000)
				c->img.addr[(int)c->y_tmp * (c->r1 * 4) + (int)c->x_tmp * 4] = color;
			color = c->t[n].addr[(int)((int)j * (c->t[n].width * 4) + (int)i * 4 + 1)];
			if (color != 0x0000000)
				c->img.addr[(int)c->y_tmp * (c->r1 * 4) + (int)c->x_tmp * 4 + 1] = color;
			color = c->t[n].addr[(int)((int)j * (c->t[n].width * 4) + (int)i * 4 + 2)];
			if (color != 0x000000)
				c->img.addr[(int)c->y_tmp * (c->r1 * 4) + (int)c->x_tmp * 4 + 2] = color;
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
	draw_item(c, c->pkmn.current_item);
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