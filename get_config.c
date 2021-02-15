#include "cub3D.h"

int		check_config(s_config *conf)
{
	if (conf->R1 && conf->R2 && conf->NO && conf->SO &&\
	 conf->WE && conf->EA && conf->S)  //&& conf->F && conf->C)
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
/*
int		ft_get_color(char *line, s_config *conf)
{
	char	*tmp;
	char	**colors;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (*line == ' ')
	{
		if (*line != ',' || !ft_isdigit(*line))
			return (0);
		i++;
	}
	while (line[i] != ' ')
		i++;
	tmp = ft_substr(line, 0, i);
	line += i;
	while (*line)
	{
		if (*line != ' ')
		{
			free(tmp);
			return (0);
		}
		line++;
	}
	colors = ft_split(tmp, ',');
	free(tmp);
}*/

void	ft_get_config(char *line, s_config *conf, s_error *ERR)
{
	
	while (*line)
	{
		if (*line == 'R')
			ft_get_R(line, conf, ERR);
		if (*line == 'S' || *line == 'N' || *line == 'W' || *line == 'E')
			ft_get_texture(line, conf, ERR);
//		if (*line == 'F' || *line == 'C')
//			return (ft_get_color(line, conf));
		line++;
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
	return (line);
}