#include "../../includes/cub3d.h"

void	ronflex_event(t_config *c, int x, int y)
{
	if (c->m.map[y][x - 1] == '4' && c->obj.pokeflute == 1)
	{
		c->m.map[y][x - 1] = '0';
		c->n_sprite--;
	}
	if (c->m.map[y][x + 1] == '4' && c->obj.pokeflute == 1)
	{
		c->m.map[y][x + 1] = '0';
		c->n_sprite--;
	}
	if (c->m.map[y - 1][x] == '4' && c->obj.pokeflute == 1)
	{
		c->m.map[y - 1][x] = '0';
		c->n_sprite--;
	}
	if (c->m.map[y + 1][x] == '4' && c->obj.pokeflute == 1)
	{
		c->m.map[y][x] = '0';
		c->n_sprite--;
	}
}

void	event(t_config *c)
{
	int	y;
	int	x;

	y = (int)c->p.y;
	x = (int)c->p.x;
	if (c->m.map[y][x] == '3')
	{
		c->obj.pokeball = 1;
		c->m.map[y][x] = '0';
		c->n_sprite--;
	}
	if (c->m.map[y][x] == '5')
	{
		c->obj.pokeflute = 1;
		c->m.map[y][x] = '0';
		c->n_sprite--;
	}
	ronflex_event(c, x, y);
}