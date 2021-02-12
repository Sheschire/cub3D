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

int		ft_get_R(char *line, s_config *conf)
{
	char	**R;

	R = ft_split(line, ' ');
	if (!check_R(R))
	{
		free_tab(R);
		return (0);
	}
	else
	{
		conf->R1 = ft_atoi(R[1]);
		conf->R2 = ft_atoi(R[2]);
		free_tab(R);
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
			return (ft_get_R(line, conf));
		if (*line == 'S' || *line == 'N' || *line == 'W' || *line == 'E')
			return (ft_get_texture(line, conf));
//		if (*line == 'F' || *line == 'C')
//			return (ft_get_color(line, conf));
		line++;
	}
	return (1);
}