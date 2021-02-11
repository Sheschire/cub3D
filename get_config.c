#include "cub3D.h"

int		ft_get_R(char *line, s_map *map)
{
	while (*line)
	{
		if (*line != ' ' && !ft_isdigit(*line))
			return (0);
		while (ft_isdigit(*line))
			map->R1 = map->R1 * 10 + (*line - '0');
		while (ft_isdigit(*line))
			map->R2 = map->R2 * 10 + (*line - '0');
		if (map->R1 && map->R2 && (ft_isdigit(*line) || *line != ' '))
			return (0);
		line++;
	}
	return (1);
}

int		ft_get_config(char *line, s_map *map)
{
	while (*line)
	{
		if (*line == 'R')
			return (ft_get_R(line + 1, map));
		if (*line == 'S' || *line == 'N' || *line == 'W' || *line == 'E')
			return (ft_get_texture(line, map));
		if (*line == 'F' || *line == 'C')
			return (ft_get_color(line, map));
		line++;
	}
	return (1);
}