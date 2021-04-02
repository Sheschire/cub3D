#include "../../includes/cub3d.h"

int		is_around_with_item(t_config *c, char *set, int item)
{
	int	y;

	y = (int)c->p.y;
	if (is_in_set(c->m.map[y][(int)c->p.x + 1], set) && item >= 1)
	{
		c->m.map[y][(int)c->p.x + 1] = '0';
		return (1);
	}
	if (is_in_set(c->m.map[y][(int)c->p.x - 1], set) && item >= 1)
	{
		c->m.map[y][(int)c->p.x - 1] = '0';
		return (1);
	}
	if (is_in_set(c->m.map[y - 1][(int)c->p.x], set) && item >= 1)
	{
		c->m.map[y - 1][(int)c->p.x] = '0';
		return (1);
	}
	if (is_in_set(c->m.map[y + 1][(int)c->p.x], set) && item >= 1)
	{
		c->m.map[y + 1][(int)c->p.x] = '0';
		return (1);
	}
	return (0);
}

void	ronflex_event(t_config *c)
{
	if (is_around_with_item(c, "4", c->pokeflute))
	{
		c->n_sprite--;
		system("afplay ./sounds/ronflex.mp3 &");
	}
}

void	teleport_event(t_config *c, int x, int y)
{
	if (c->m.map[y][x] == '6' && y == 8 && x == 31)
		c->p.x += 5;
	if (c->m.map[y][x] == '6' && y == 8 && x == 33)
		c->p.x -= 5;
}

void	capture_event(t_config *c)
{
	if (is_around_with_item(c, "27", c->pokeball) && c->pokeball >= 1)
	{
		c->pokeball--;
		c->n_sprite--;
		system("afplay ./sounds/capture.mp3 &");	
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
		c->pokeball++;
		c->m.map[y][x] = '0';
		c->n_sprite--;
	}
	if (c->m.map[y][x] == '5')
	{
		c->pokeflute = 1;
		c->m.map[y][x] = '0';
		c->n_sprite--;
	}
	ronflex_event(c);
	teleport_event(c, x, y);
	capture_event(c);
}