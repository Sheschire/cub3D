#include "cub3D.h"

int 		ft_check_walls(s_config *c)
{
	int	x;
	int y;

	y = 0;
	while (c->m.map[y])
	{
		x = 0;
		while (c->m.map[y][x] != '1')
		{
			if (!is_in_set(c->m.map[y][x], " \t"))
				return (0);
			x++;
		}
		while (c->m.map[y][x])
		{
			if (!is_in_set(c->m.map[y][x], " 120NSEW"))
				return (0);
			if (c->m.map[y][x] == 'N' || c->m.map[y][x] == 'S' || c->m.map[y][x] == 'E' || c->m.map[y][x] == 'W')
				ft_get_player(c, x, y);
			x++;
		}
		if (c->m.map[y][x - 1] != '1')
			return (0);
		y++;
	}
	return (1);
}

int			check_empty_line(char *line)
{
	int	i;
	int	boo;

	i = 0;
	while (line[i])
	{
		boo = 0;
		if (line[i] == '*')
		{
			i++;
			if (line[i])
			{
				while (line[i] != '*')
				{
					if (is_in_set(line[i], "012NSWE"))
						boo = 1;
					i++;
				}
			}
			if (line[i] == '*' && boo == 0)
				return (0);
		}
		i++;
	}
	return (1);
}

int			greatest_line_len(char **map)
{
	int	y;
	int	x;
	int	len;

	y = 0;
	len = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
			x++;
		if (x > len)
			len = x;
		y++;
	}
	return (len);
}

void		tmp_print_check(s_config *c)
{
	printf("[MAP CHECK]\n\n");
	int	i = 0;
	while (c->m.map[i])
	{
		printf("%s\n", c->m.map[i]);
		i++;
	}
	printf("\n");
	printf("[CONFIG CHECK]\n\n");
	printf("RESOLUTION = %d %d\n", c->r1, c->r2);
	printf("NO TEXTURE = %s\n", c->no);
	printf("SO TEXTURE = %s\n", c->so);
	printf("WE TEXTURE = %s\n", c->we);
	printf("EA TEXTURE = %s\n", c->ea);
	printf("S TEXTURE = %s\n\n", c->s);
	printf("F COLOR = %d\n\n", c->f_rgb);
	printf("C COLOR = %d\n\n", c->c_rgb);
	printf("PLAYER CHECK\n\n");
	printf("POSITION = %c\n", c->p.orient);
	printf("x = %d\n", c->p.x);
	printf("y = %d\n", c->p.y);
}