#include "cub3D.h"

void	ft_free_textures(s_config *conf)
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

void	ft_get_texture(char *line, s_config *conf, s_error *ERR)
{
    char    **param;
	int		i;

	i = 0;
    param = ft_split(line, ' ');
	if (!check_param(conf, param, ERR, line))
		_ERROR("texture", ERR);
	else
		free_tab(param, line, ' ');
}