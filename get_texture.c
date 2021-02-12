#include "cub3D.h"

void	ft_free_all(s_config *conf)
{
	if (conf->SO)
		free(conf->SO);
	if (conf->NO)
		free(conf->NO);
	if (conf->WE)
		free(conf->WE);
	if (conf->EA)
		free(conf->EA);
	if (conf->S)
		free(conf->S);
}

int	ft_check_xpm(s_config *conf)
{
	int fd;

	if (!(open(conf->S, O_RDONLY)))
		return (0);
	if (!(open(conf->SO, O_RDONLY)))
		return (0);
	if (!(open(conf->NO, O_RDONLY)))
		return (0);
	if (!(open(conf->EA, O_RDONLY)))
		return (0);
	if (!(open(conf->WE, O_RDONLY)))
	{
		return (0);
	}
	return (1);
}

void	ft_get_path(char *line, s_config *conf, char **param)
{
	size_t	i;

	i = 0;
	while (param[1][i])
	{
		if (line[i - 1] == 'm' && line[i - 2] == 'p' && line[i - 3] == 'x' && line[i - 4] == '.')
		{
			if (ft_strcmp(param[0], "NO") == 0)
				conf->NO = ft_substr(param[1], 0, ft_strlen(param[1]));
			if (ft_strcmp(param[0], "SO") == 0)
				conf->SO = ft_substr(param[1], 0, ft_strlen(param[1]));
			if (ft_strcmp(param[0], "WE") == 0)
				conf->WE = ft_substr(param[1], 0, ft_strlen(param[1]));
			if (ft_strcmp(param[0], "EA") == 0)
				conf->EA = ft_substr(param[1], 0, ft_strlen(param[1]));
			if (ft_strcmp(param[0], "S") == 0)
				conf->S = ft_substr(param[1], 0, ft_strlen(param[1]));
        }
		i++;
	}
}

int     ft_get_texture(char *line, s_config *conf)
{
    char    **param;

    param = ft_split(line, ' ');
	ft_get_path(line, conf, param);
	free_tab(param);
	if (!ft_check_xpm(conf))
	{
		ft_free_all(conf);
		return (0);
	}
    return (1);
}