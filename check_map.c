#include "cub3D.h"

int 		ft_is_parameter(char c)
{
	if (c == ' ' || c == '	'|| c == '1' || c == '2' || c == '0' || \
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
		if (line[i] != ' ' && line[i] != '1' && line[i] != '	')
			return (0);
		i++;
	}
	if (ft_strchr(line, '1'))
		return (1);
	return (0);
}

int			is_in_set(char	c)
{
	char	*set;
	int		i;

	set = "012NSWE";
	i = 0;
	while (set[i])
		if (c == set[i++])
			return (1);
	return (0);
}
/*
int			ft_check_UDRL(char **map, int x, int y)
{
	if (!is_in_set(map[y - 1][x]))
		return (0);
	if (!is_in_set(map[y + 1][x]))
		return (0);
	if (!is_in_set(map[y][x + 1]))
		return (0);
	if (!is_in_set(map[y][x - 1]))
		return (0);
	return (1);
}*/

void	ft_check_player(s_map *map, s_player *player, int x, int y)
{
		player->pos_count++;
		player->x = x;
		player->y = y;
		player->pos = map->map[y][x];
		map->map[y][x] = '0';
}

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
			if (!ft_is_parameter(map->map[y][x]))
				return (0);
			while (map->map[y][x] == ' ')
				x++;
			if (map->map[y][x])
				if (map->map[y][x] != '1' && (map->map[y][x - 1] == ' ' || map->map[y][x - 1] == '	'))
					return (0);
			if (map->map[y][x] == 'N' || map->map[y][x] == 'S' || map->map[y][x] == 'E' || map->map[y][x] == 'W')
				ft_check_player(map, player, x, y);
/*			if (is_in_set(map[y][x]) && map[y][x] != '1')
				if (!ft_check_UDRL(map, x, y))
					return (0);*/
			x++;
		}
		y++;
	}
	return (1);
}

void		get_map(char *line, s_map *map)
{
	char	*tmp;

	tmp = ft_strjoin(line, "*", 1);
	if (map->line == NULL)
		map->line = ft_strdup(tmp);
	else
		map->line = ft_strjoin(map->line, tmp, 1);
	free(tmp);
}

void		add_walls(s_map *map, int y, int x, int len)
{
	int		diff;
	char	*to_join;

	diff = len - x;
	to_join = (char *)malloc(sizeof(char) * diff + 1);
	if (!to_join)
		return ;
	x = 0;
	while (x < diff)
		to_join[x++] = '1';
	to_join[x] = '\0';
	map->map[y] = ft_strjoin(map->map[y], to_join, 3);
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

void		fill_spaces(s_map *map)
{
	int	len;
	int	y;
	int	x;

	y = 0;
	len = greatest_line_len(map->map);
	while (map->map[y])
	{
		x = 0;
		while (map->map[y][x])
		{
			if (map->map[y][x] == ' ' || map->map[y][x] == '	')
				map->map[y][x] = '1';
			x++;
		}
		if (ft_strlen(map->map[y]) < (size_t)len)
			add_walls(map, y, x, len);
		y++;
	}
}

int			check_empty(char *line)
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
				if (is_in_set(line[i]))
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

int 		ft_check_map(int fd, s_error *ERR)
{
	char    	*line;
	s_map    	map;
	s_player	player;
	int			ret;

	ft_init_s_player(&player);
	ft_init_s_map(&map);
	line = ft_config(fd, ERR);
	if (is_map_1st_line(line))
		get_map(line, &map);
	while ((ret = get_next_line(fd, &line)) > 0 && !is_map_1st_line(line))
		get_map(line, &map);
	get_map(line, &map);
	if (!check_empty(map.line))
		_ERROR("emptyline", ERR);
	map.map = ft_split(map.line, '*');
	fill_spaces(&map);
	if (!ft_check_walls(&map, &player))
		_ERROR("wall", ERR);
	int	i = 0;
	while (map.map[i])
	{
		printf("%s\n", map.map[i]);
		i++;
	}
	if (player.pos_count != 1)
		_ERROR("player", ERR);
	return (ERR->boo);
}