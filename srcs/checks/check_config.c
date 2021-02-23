#include "cub3d.h"

int		check_config(t_config *c)
{
	if (c->r1 && c->r2 && c->no && c->so &&\
	 c->we && c->ea && c->s && c->f_rgb != -1 && c->c_rgb != 1)
	 	return (1);
	return (0);
}

int		check_r(char **r)
{
	int	i;
	int	error;

	i = 0;
	error = 0;
	while (r[i])
		i++;
	if (i != 3)
		return (0);
	if (r[0][0] != 'R' || r[0][1])
		error = 1;
	i = 0;
	while (r[1][i])
		if (!ft_isdigit(r[1][i++]))
			error = 1;
	i = 0;
	while (r[2][i])
		if (!ft_isdigit(r[2][i++]))
			error = 1;
	if (error == 1)
		return (0);
	return (1);
}

int		check_colors(char **rgb)
{
	int	i;
	int	j;

	i = 0;
	while (rgb[i])
	{
		j = 0;
		if (ft_atoi(rgb[i]) > 255)
			return (0);
		while (rgb[i][j])
			if (!ft_isdigit(rgb[i][j++]))
				return (0);
		i++;
	}
	if (i - 1 != 2)
		return (0);
	return (1);
}

int	    ft_check_xpm(t_config *c)
{
	int fd;

	if ((fd = (open(c->s, O_RDONLY))) < 0)
		close(fd);
	if ((fd = (open(c->no, O_RDONLY))) < 0)
		close(fd);
	if ((fd = (open(c->we, O_RDONLY))) < 0)
		close(fd);
	if ((fd = (open(c->ea, O_RDONLY))) < 0)
		close(fd);
	if ((fd = (open(c->so, O_RDONLY))) < 0)
		close(fd);
	if (fd < 0)
		return (0);
	return (1);
}

int		check_param(t_config *c, char **param, char *line)
{
	int		i;

	i = 0;
	while (param[i])
		i++;
	if (i - 1 != 1)
	{
		free_tab(param, line, ' ');
		f_error("param", c);
		return (0);
	}
	ft_get_path(c, param);
//	if (!ft_check_xpm(conf))
//	{
//		ft_free_textures(conf);
//		f_error("xpm", ERR);
//	}
	return (1);
}