#include "cub3D.h"

int		check_config(s_config *conf)
{
	if (conf->R1 && conf->R2 && conf->NO && conf->SO &&\
	 conf->WE && conf->EA && conf->S && conf->F && conf->C)
	 	return (1);
	return (0);
}

int		ft_get_R(char *line, s_config *conf)
{
	while (*line)
	{
		if (*line != ' ' && !ft_isdigit(*line))
			return (0);
		while (ft_isdigit(*line))
		{
			conf->R1 = conf->R1 * 10 + (*line - '0');
			line++;
		}
		while (ft_isdigit(*line))
		{
			conf->R2 = conf->R2 * 10 + (*line - '0');
			line++;
		}
		if (conf->R1 && conf->R2 && (ft_isdigit(*line) || *line != ' '))
			return (0);
		line++;
	}
	return (1);
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

int		ft_get_config(char *line, s_config *conf)
{
	while (*line)
	{
		if (*line == 'R')
			return (ft_get_R(line + 1, conf));
		if (*line == 'S' || *line == 'N' || *line == 'W' || *line == 'E')
			return (ft_get_texture(line, conf));
//		if (*line == 'F' || *line == 'C')
//			return (ft_get_color(line, conf));
		line++;
	}
	return (1);
}