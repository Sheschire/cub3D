#include "cub3D.h"

int 		ft_check_walls(s_map *map, s_player *player)
{
	int	x;
	int y;

	y = 0;
	while (map->map[y])
	{
		x = 0;
		while (map->map[y][x])
		{
			if (!is_in_set(map->map[y][x], " 	120NSEW"))
				return (0);
			while (map->map[y][x] == ' ')
				x++;
			if (map->map[y][x])
				if (map->map[y][x] != '1' && (map->map[y][x - 1] == ' ' || map->map[y][x - 1] == '	'))
					return (0);
			if (map->map[y][x] == 'N' || map->map[y][x] == 'S' || map->map[y][x] == 'E' || map->map[y][x] == 'W')
				ft_get_player(map, player, x, y);
/*			if (is_in_set(map[y][x]) && map[y][x] != '1')
				if (!ft_check_UDRL(map, x, y))
					return (0);*/
			x++;
		}
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
			while (line[i] != '*')
			{
				if (is_in_set(line[i], "012NSWE"))
					boo = 1;
				i++;
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

void		tmp_print_check(s_map *map, s_player *player)
{
	printf("[MAP CHECK]\n\n");
	int	i = 0;
	while (map->map[i])
	{
		printf("%s\n", map->map[i]);
		i++;
	}
	printf("\n");
	printf("PLAYER CHECK\n\n");
	printf("POSITION = %c\n", player->orient);
	printf("x = %d\n", player->x);
	printf("y = %d\n", player->y);
}