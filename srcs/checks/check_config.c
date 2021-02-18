#include "cub3D.h"

int		check_config(s_config *conf)
{
	if (conf->r1 && conf->r2 && conf->no && conf->so &&\
	 conf->we && conf->ea && conf->s && conf->f_rgb != -1 && conf->c_rgb != 1)
	 	return (1);
	return (0);
}

int		check_R(char **r)
{
	int	i;
	int	error;

	i = 0;
	error = 0;
	while (r[i])
		i++;
	if (i - 1 != 2)
		error = 1;
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

int	    ft_check_xpm(s_config *conf)
{
	int fd;

	if ((fd = (open(conf->s, O_RDONLY))) < 0)
		close(fd);
	if ((fd = (open(conf->no, O_RDONLY))) < 0)
		close(fd);
	if ((fd = (open(conf->we, O_RDONLY))) < 0)
		close(fd);
	if ((fd = (open(conf->ea, O_RDONLY))) < 0)
		close(fd);
	if ((fd = (open(conf->so, O_RDONLY))) < 0)
		close(fd);
	if (fd < 0)
		return (0);
	return (1);
}

int		check_param(s_config *conf, char **param, s_error *ERR, char *line)
{
	int		i;

	i = 0;
	while (param[i])
		i++;
	if (i - 1 != 1)
	{
		free_tab(param, line, ' ');
		_ERROR("param", ERR);
		return (0);
	}
	ft_get_path(conf, param);
//	if (!ft_check_xpm(conf))
//	{
//		ft_free_textures(conf);
//		_ERROR("xpm", ERR);
//	}
	return (1);
}

void	tmp_print_check2(s_config *conf)
{
	printf("[CONFIG CHECK]\n\n");
	printf("RESOLUTION = %d %d\n", conf->r1, conf->r2);
	printf("NO TEXTURE = %s\n", conf->no);
	printf("SO TEXTURE = %s\n", conf->so);
	printf("WE TEXTURE = %s\n", conf->we);
	printf("EA TEXTURE = %s\n", conf->ea);
	printf("S TEXTURE = %s\n\n", conf->s);
	printf("F COLOR = %d\n\n", conf->f_rgb);
	printf("C COLOR = %d\n\n", conf->c_rgb);
}