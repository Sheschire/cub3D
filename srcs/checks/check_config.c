#include "cub3D.h"

int		check_config(s_config *conf)
{
	if (conf->R1 && conf->R2 && conf->NO && conf->SO &&\
	 conf->WE && conf->EA && conf->S && conf->F_rgb != -1 && conf->C_rgb != 1)
	 	return (1);
	return (0);
}

int		check_R(char **R)
{
	int	i;
	int	error;

	i = 0;
	error = 0;
	while (R[i])
		i++;
	if (i - 1 != 2)
		error = 1;
	if (R[0][0] != 'R' || R[0][1])
		error = 1;
	i = 0;
	while (R[1][i])
		if (!ft_isdigit(R[1][i++]))
			error = 1;
	i = 0;
	while (R[2][i])
		if (!ft_isdigit(R[2][i++]))
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
	printf("RESOLUTION = %d %d\n", conf->R1, conf->R2);
	printf("NO TEXTURE = %s\n", conf->NO);
	printf("SO TEXTURE = %s\n", conf->SO);
	printf("WE TEXTURE = %s\n", conf->WE);
	printf("EA TEXTURE = %s\n", conf->EA);
	printf("S TEXTURE = %s\n\n", conf->S);
	printf("F COLOR = %d\n\n", conf->F_rgb);
	printf("C COLOR = %d\n\n", conf->C_rgb);
}