#include "cub3D.h"

void	ft_free_all(s_map *map)
{
	if (map->SO)
		free(map->SO);
	if (map->NO)
		free(map->NO);
	if (map->WE)
		free(map->WE);
	if (map->EA)
		free(map->EA);
	if (map->S)
		free(map->S);
}

int	ft_check_xpm(s_map *map)
{
	int fd;

	if (!(open(map->S, O_RDONLY)))
		return (0);
	if (!(open(map->SO, O_RDONLY)))
		return (0);
	if (!(open(map->NO, O_RDONLY)))
		return (0);
	if (!(open(map->EA, O_RDONLY)))
		return (0);
	if (!(open(map->WE, O_RDONLY)))
	{
		return (0);
	}
	return (1);
}

void	ft_get_path(char *line, s_map *map, char **param)
{
	size_t	i;

	i = 0;
	while (param[1][i])
	{
		if (line[i - 1] == 'm' && line[i - 2] == 'p' && line[i - 3] == 'x' && line[i - 4] == '.')
		{
			if (ft_strncmp(param[0], "NO") == 0)
				map->NO = ft_substr(param[1], 0, ft_strlen(param[1]));
			if (ft_strncmp(param[0], "SO") == 0)
				map->SO = ft_substr(param[1], 0, ft_strlen(param[1]));
			if (ft_strncmp(param[0], "WE") == 0)
				map->WE = ft_substr(param[1], 0, ft_strlen(param[1]));
			if (ft_strncmp(param[0], "EA") == 0)
				map->EA = ft_substr(param[1], 0, ft_strlen(param[1]));
			if (ft_strncmp(param[0], "S") == 0)
				map->S = ft_substr(param[1], 0, ft_strlen(param[1]));
        }
		i++;
	}
}

int     ft_get_texture(char *line, s_map *map)
{
    char    **param;

    param = ft_split(line, ' ');
	ft_get_path(line, map, param);
	free(param[0]);
    free(param[1]);
	free(param);
	if (!ft_check_xpm(map))
	{
		ft_free_all(map);
		return (0);
	}
    return (1);
}