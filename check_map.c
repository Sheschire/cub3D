#include "cub3D.h"

int 		ft_is_parameter(char c)
{
	if (c == ' ' || c == '1' || c == '2' || c == '0' || \
	c == 'N' || c == 'S' || c == 'E' || c =='W')
		return (1);
	return (0);
}

int			is_map_1st_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '1')
			return (0);
		i++;
	}
	if (ft_strchr(line, '1'))
		return (1);
	return (0);
}

int			ft_check_UDRL(char **map, int x, int y)
{
	if (map[y - 1][x] != '1' || map[y - 1][x] != '0' || map[y - 1][x] != '2')
		return (0);
	if (map[y + 1][x] != '1' || map[y + 1][x] != '0' || map[y + 1][x] != '2')
		return (0);
	if (map[y][x - 1] != '1' || map[y][x - 1] != '0' || map[y][x - 1] != '2')
		return (0);
	if (map[y][x + 1] != '1' || map[y][x + 1] != '0' || map[y][x + 1] != '2')
		return (0);
	return (1);
}

int 		ft_check_walls(char **map)
{
	int	x;
	int y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (!ft_is_parameter(map[y][x]))
				return (0);
			while (map[y][x] == ' ')
				x++;
			if (map[y][x] != '1' && map[y][x - 1] == ' ')
				return (0);
			if (map[y][x] == '0' || map[y][x] == '2')
				if (!ft_check_UDRL(map, x, y))
					return (0);
			x++;
		}
		y++;
	}
	return (1);
}

void	ft_check_player(char **map, s_player *player)
{
	int			x;
	int			y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'N' || map[y][x] == 'S' || map[y][x] == 'E' || map[y][x] == 'W')
			{
				player->pos_count++;
				player->x = x;
				player->y = y;
				player->pos = map[y][x];
				map[y][x] = '0';
			}
			x++;
		}
		y++;
	}
}

int 		ft_check_map(int fd)
{
	char    	*line;
	char    	**map;
	s_player	player;
	s_config	conf;
	int			ret;

	ft_init_s_player(&player);
	ft_init_s_config(&conf);
	while ((ret = get_next_line(fd, &line)) > 0 && !is_map_1st_line(line))
	{
		if (!ft_get_config(line, &conf))
			return (0);
		free(line);
	}
	if (!check_config(&conf))
	{
		free(line);
		return (0);
	}
	if (ret == 0)
		return (0);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		line = ft_strjoin(line, "*", 1);
		free(line);
	}
	map = ft_split(line, '*');
	if (!ft_check_walls(map))
		return (0);
	ft_check_player(map, &player);
	if (player.pos_count != 1)
		return (0);
//	if (!ft_check_empty_lines(map))
//		return (0);
	return (1);
}