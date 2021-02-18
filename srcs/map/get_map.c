#include "cub3D.h"

void	ft_get_player(s_map *map, s_player *player, int x, int y)
{
		player->pos_count++;
		player->x = x;
		player->y = y;
		player->orient = map->map[y][x];
		map->map[y][x] = '0';
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

void 		ft_check_map(int fd, s_error *err)
{
	char    	*line;
	s_map    	map;
	s_player	player;
	s_config	conf;
	int			ret;

	ft_init_s_player(&player);
	ft_init_s_map(&map);
	ft_init_s_config(&conf);
	line = ft_config(fd, err, &conf);
	if (is_map_1st_line(line))
		get_map(line, &map);
	while ((ret = get_next_line(fd, &line)) > 0 && !is_map_1st_line(line))
		get_map(line, &map);
	get_map(line, &map);
	if (!check_empty_line(map.line))
		_ERROR("emptyline", err);
	map.map = ft_split(map.line, '*');
	fill_spaces(&map);
	if (!ft_check_walls(&map, &player))
		_ERROR("wall", err);
	if (player.pos_count != 1)
		_ERROR("player", err);
	if (!err->boo)
		ft_free_all(&map, &conf);
	tmp_print_check(&map, &player, &conf);
}