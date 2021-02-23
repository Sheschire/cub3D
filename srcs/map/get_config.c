#include "cub3D.h"

void	ft_get_R(char *line, s_config *c)
{
	char	**r;

	if (c->r1 || c->r2)
	{
		_ERROR("twice", c);
		return ;
	}
	r = ft_split(line, ' ');
	if (!check_R(r))
	{
		free_tab(r, line, ' ');
		_ERROR("R", c);
	}
	else
	{
		c->r1 = ft_atoi(r[1]);
		c->r2 = ft_atoi(r[2]);
		free_tab(r, line, ' ');
	}
}

void	ft_get_colors(char **tmp, char **rgb, s_config *c)
{
	int	r;
	int	g;
	int	b;

	r = ft_atoi(rgb[0]);
	g = ft_atoi(rgb[1]);
	b = ft_atoi(rgb[2]);
	if (ft_strcmp(tmp[0], "F") == 0)
//		conf->f_rgb = 65536 * r + 256 * g + b;
		c->f_rgb = (r << 16) + (g << 8) + b;
	if (ft_strcmp(tmp[0], "C") == 0)
//		conf->c_rgb = 65536 * r + 256 * g + b;
		c->c_rgb = (r << 16) + (g << 8) + b;
}

void	ft_split_colors(char *line, s_config *c)
{
	char	**tmp;
	char	**rgb;
	int		i;

	i = 0;
	if ((*line == 'C' && c->c_rgb != -1) || (*line == 'F' && c->f_rgb != -1))
	{
		_ERROR("twice", c);
		return ;
	}
	tmp = ft_split(line, ' ');
	while (tmp[i])
		i++;
	if (i - 1 != 1 || (ft_strcmp(tmp[0], "F") != 0 && ft_strcmp(tmp[0], "C") != 0))
		_ERROR("param", c);
	else
	{
		rgb = ft_split(tmp[1], ',');
		if (!check_colors(rgb))
			_ERROR("colors", c);
		else
			ft_get_colors(tmp, rgb, c);
		free_tab(rgb, line, ',');
	}
	free_tab(tmp, line, ' ');
}

void	ft_get_config(char *line, s_config *c)
{
	if (*line)
	{
		while (*line == ' ')
			line++;
		if (!is_in_set(*line, "RSNWEFC"))
			_ERROR("param", c);
		else
		{
			while (*line)
			{
				if (*line == 'R')
					ft_get_R(line, c);
				if (*line == 'S'|| *line == 'N' || *line == 'E'|| *line == 'W')
					ft_get_texture(line, c);
				if (*line == 'F'|| *line == 'C')
					ft_split_colors(line, c);
				line++;
			}
		}
	}

}

char	*ft_config(int fd, s_config *c)
{
	char		*line;
	int			ret;

	while ((ret = get_next_line(fd, &line)) > 0 && !is_map_1st_line(line))
	{
		ft_get_config(line, c);
		free(line);
	}
	if (!check_config(c) || ret == 0)
		_ERROR("config", c);
	return (line);
}