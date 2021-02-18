#include "cub3D.h"

void	ft_free_textures(s_config *conf)
{
	if (conf->so)
		free(conf->so);
	if (conf->no)
		free(conf->no);
	if (conf->we)
		free(conf->we);
	if (conf->ea)
		free(conf->ea);
	if (conf->s)
		free(conf->s);
}

void	ft_get_path(s_config *conf, char **param)
{
	size_t	i;

	i = ft_strlen(param[1]);
	if (param[1][i - 1] == 'm' && param[1][i - 2] == 'p' && param[1][i - 3] == 'x' && param[1][i - 4] == '.')
	{
		if (ft_strcmp(param[0], "NO") == 0)
			conf->no = ft_substr(param[1], 0, ft_strlen(param[1]));
		if (ft_strcmp(param[0], "SO") == 0)
			conf->so = ft_substr(param[1], 0, ft_strlen(param[1]));
		if (ft_strcmp(param[0], "WE") == 0)
			conf->we = ft_substr(param[1], 0, ft_strlen(param[1]));
		if (ft_strcmp(param[0], "EA") == 0)
			conf->ea = ft_substr(param[1], 0, ft_strlen(param[1]));
		if (ft_strcmp(param[0], "S") == 0)
			conf->s = ft_substr(param[1], 0, ft_strlen(param[1]));
    }
}

void	ft_get_texture(char *line, s_config *conf, s_error *err)
{
    char    **param;
	int		i;

	i = 0;
    param = ft_split(line, ' ');
	if (!check_param(conf, param, err, line))
		_ERROR("texture", err);
	else
		free_tab(param, line, ' ');
}