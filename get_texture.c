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

	if ((fd = (open(conf->S, O_RDONLY))) < 0)
		close(fd);
	if ((fd = (open(conf->NO, O_RDONLY))) < 0)
		close(fd);
	if ((fd = (open(conf->WE, O_RDONLY))) < 0)
		close(fd);
	if ((fd = (open(conf->EA, O_RDONLY))) < 0)
		close(fd);
	if ((fd = (open(conf->SO, O_RDONLY))) < 0)
		close(fd);
	if (fd < 0)
		return (0);
	return (1);
}

void	ft_get_path(s_config *conf, char **param)
{
	size_t	i;

	i = ft_strlen(param[1]);
	if (param[1][i - 1] == 'm' && param[1][i - 2] == 'p' && param[1][i - 3] == 'x' && param[1][i - 4] == '.')
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
}

int		check_param(s_config *conf, char **param)
{
	int		i;

	i = 0;
	while (param[i])
		i++;
	if (i - 1 != 1)
	{
		free_tab(param);
		return (0);
	}
	ft_get_path(conf, param);
//	if (!ft_check_xpm(conf))
//	{
//		ft_free_all(conf);
//		return (0);
//	}
	return (1);
}

int     ft_get_texture(char *line, s_config *conf)
{
    char    **param;
	int		i;

	i = 0;
    param = ft_split(line, ' ');
	if (!check_param(conf, param))
		return (0);
	else
		free_tab(param);
    return (1);
}