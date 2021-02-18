#include "cub3D.h"

void	ft_get_R(char *line, s_config *conf, s_error *err)
{
	char	**r;

	r = ft_split(line, ' ');
	if (!check_R(r))
	{
		free_tab(r, line, ' ');
		_ERROR("r", err);
	}
	else
	{
		conf->r1 = ft_atoi(r[1]);
		conf->r2 = ft_atoi(r[2]);
		free_tab(r, line, ' ');
	}
}

void	ft_get_colors(char **tmp, char **rgb, s_config *conf)
{
	int	r;
	int	g;
	int	b;

	r = ft_atoi(rgb[0]);
	g = ft_atoi(rgb[1]);
	b = ft_atoi(rgb[2]);
	if (ft_strcmp(tmp[0], "F") == 0)
//		conf->f_rgb = 65536 * r + 256 * g + b;
		conf->f_rgb = (r << 16) + (g << 8) + b;
	if (ft_strcmp(tmp[0], "C") == 0)
//		conf->c_rgb = 65536 * r + 256 * g + b;
		conf->c_rgb = (r << 16) + (g << 8) + b;
}

void	ft_split_colors(char *line, s_config *conf, s_error *err)
{
	char	**tmp;
	char	**rgb;
	int		i;

	i = 0;
	tmp = ft_split(line, ' ');
	while (tmp[i])
		i++;
	if (i - 1 != 1 || (ft_strcmp(tmp[0], "F") != 0 && ft_strcmp(tmp[0], "C") != 0))
		_ERROR("param", err);
	else
	{
		rgb = ft_split(tmp[1], ',');
		if (!check_colors(rgb))
			_ERROR("colors", err);
		else
			ft_get_colors(tmp, rgb, conf);
		free_tab(rgb, line, ',');
	}
	free_tab(tmp, line, ' ');
}

void	ft_get_config(char *line, s_config *conf, s_error *err)
{
	if (*line)
	{
		while (*line == ' ')
			line++;
		if (!is_in_set(*line, "RSNWEFC"))
			_ERROR("param", err);
		else
		{
			while (*line)
			{
				if (*line == 'R')
					ft_get_R(line, conf, err);
				if (*line == 'S' || *line == 'N' || *line == 'W' || *line == 'E')
					ft_get_texture(line, conf, err);
				if (*line == 'F' || *line == 'C')
					ft_split_colors(line, conf, err);
				line++;
			}
		}
	}

}

char	*ft_config(int fd, s_error *err)
{
	char		*line;
	int			ret;
	s_config	conf;

	ft_init_s_config(&conf);
	while ((ret = get_next_line(fd, &line)) > 0 && !is_map_1st_line(line))
	{
		ft_get_config(line, &conf, err);
		free(line);
	}
	if (!check_config(&conf) || ret == 0)
		_ERROR("config", err);
	tmp_print_check2(&conf);
	return (line);
}