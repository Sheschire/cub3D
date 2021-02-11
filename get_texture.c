#include "cub3D.h"

void	ft_check_xpm(s_map *map)
{
	if (!(open(map->S, O_RDONLY)))
		free(map->S);
	if (!(open(map->SO, O_RDONLY)))
		free(map->SO);
	if (!(open(map->NO, O_RDONLY)))
		free(map->NO);
	if (!(open(map->EA, O_RDONLY)))
		free(map->EA);
	if (!(open(map->WE, O_RDONLY)))
		free(map->WE);
}

int		ft_get_path(char *line, s_map *map, char **param)
{
	size_t	i;

	i = 0;
	while (param[1][i])
	{
		if (line[i - 1] == 'm' && line[i - 2] == 'p' && line[i - 3] == 'x' && line[i - 4] == '.')
		{
			if (param[0] == "NO")
				map->NO = ft_substr(line, 0, i);
			if (param[0] == "SO")
				map->SO = ft_substr(line, 0, i);
			if (param[0] == "WE")
				map->WE = ft_substr(line, 0, i);
			if (param[0] == "EA")
				map->EA = ft_substr(line, 0, i);
			if (param[0] == "S")
				map->S = ft_substr(line, 0, i);
			ft_check_xpm(map);
        }
		if (map->SO == NULL || map->S == NULL || map->NO == NULL || map->WE == NULL || map->EA == NULL)
		    return (0);
		i++;
	}
	return (1);
}

int     ft_get_texture(char *line, s_map *map)
{
    char    **param;

    param = ft_split(line, ' ');
	if (!ft_get_path(line, map, param) || param[2])
	{
		free(param[0]);
		free(param[1]);
		return (0);
	}
    free(param[0]);
    free(param[1]);
    return (1);
}