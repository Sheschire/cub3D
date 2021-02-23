#include "cub3D.h"

void	ft_free_textures(s_config *c)
{
	if (c->so)
		free(c->so);
	if (c->no)
		free(c->no);
	if (c->we)
		free(c->we);
	if (c->ea)
		free(c->ea);
	if (c->s)
		free(c->s);
}

void	ft_get_path(s_config *c, char **param)
{
	size_t	i;

	i = ft_strlen(param[1]);
	if (param[1][i - 1] == 'm' && param[1][i - 2] == 'p' && param[1][i - 3] == 'x' && param[1][i - 4] == '.')
	{
		if (ft_strcmp(param[0], "NO") == 0)
			c->no = ft_substr(param[1], 0, ft_strlen(param[1]));
		if (ft_strcmp(param[0], "SO") == 0)
			c->so = ft_substr(param[1], 0, ft_strlen(param[1]));
		if (ft_strcmp(param[0], "WE") == 0)
			c->we = ft_substr(param[1], 0, ft_strlen(param[1]));
		if (ft_strcmp(param[0], "EA") == 0)
			c->ea = ft_substr(param[1], 0, ft_strlen(param[1]));
		if (ft_strcmp(param[0], "S") == 0)
			c->s = ft_substr(param[1], 0, ft_strlen(param[1]));
    }
}

void	ft_get_texture(char *line, s_config *c)
{
    char    **param;
	int		i;

	i = 0;
	if ((*line == 'S' && c->s) || (*line == 'N' && c->no) ||\
	(*line == 'E' && c->ea) || (*line == 'W' && c->we))
	{
		_ERROR("twice", c);
		return ;
	}
    param = ft_split(line, ' ');
	if (!check_param(c, param, line))
		_ERROR("texture", c);
	else
		free_tab(param, line, ' ');
}