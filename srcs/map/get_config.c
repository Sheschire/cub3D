#include "cub3D.h"

void	ft_get_R(char *line, s_config *conf, s_error *ERR)
{
	char	**R;

	R = ft_split(line, ' ');
	if (!check_R(R))
	{
		free_tab(R, line, ' ');
		_ERROR("R", ERR);
	}
	else
	{
		conf->R1 = ft_atoi(R[1]);
		conf->R2 = ft_atoi(R[2]);
		free_tab(R, line, ' ');
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
//		conf->F_rgb = 65536 * r + 256 * g + b;
		conf->F_rgb = (r << 16) + (g << 8) + b;
	if (ft_strcmp(tmp[0], "C") == 0)
//		conf->C_rgb = 65536 * r + 256 * g + b;
		conf->C_rgb = (r << 16) + (g << 8) + b;
}

void	ft_split_colors(char *line, s_config *conf, s_error *ERR)
{
	char	**tmp;
	char	**rgb;
	int		i;

	i = 0;
	tmp = ft_split(line, ' ');
	while (tmp[i])
		i++;
	if (i - 1 != 1 || (ft_strcmp(tmp[0], "F") != 0 && ft_strcmp(tmp[0], "C") != 0))
		_ERROR("param", ERR);
	else
	{
		rgb = ft_split(tmp[1], ',');
		if (!check_colors(rgb))
			_ERROR("colors", ERR);
		else
			ft_get_colors(tmp, rgb, conf);
		free_tab(rgb, line, ',');
	}
	free_tab(tmp, line, ' ');
}

void	ft_get_config(char *line, s_config *conf, s_error *ERR)
{
	if (*line)
	{
		while (*line == ' ')
			line++;
		if (!is_in_set(*line, "RSNWEFC"))
			_ERROR("param", ERR);
		else
		{
			while (*line)
			{
				if (*line == 'R')
					ft_get_R(line, conf, ERR);
				if (*line == 'S' || *line == 'N' || *line == 'W' || *line == 'E')
					ft_get_texture(line, conf, ERR);
				if (*line == 'F' || *line == 'C')
					ft_split_colors(line, conf, ERR);
				line++;
			}
		}
	}

}

char	*ft_config(int fd, s_error *ERR)
{
	char		*line;
	int			ret;
	s_config	conf;

	ft_init_s_config(&conf);
	while ((ret = get_next_line(fd, &line)) > 0 && !is_map_1st_line(line))
	{
		ft_get_config(line, &conf, ERR);
		free(line);
	}
	if (!check_config(&conf) || ret == 0)
		_ERROR("config", ERR);
	tmp_print_check2(&conf);
	return (line);
}