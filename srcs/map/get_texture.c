/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemesle <tlemesle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 15:43:22 by tlemesle          #+#    #+#             */
/*   Updated: 2021/03/30 10:27:18 by tlemesle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_get_path(t_config *c, char **param)
{
	size_t	i;

	i = ft_strlen(param[1]);
	if (param[1][i - 1] == 'm' && param[1][i - 2] == 'p' && \
	param[1][i - 3] == 'x' && param[1][i - 4] == '.')
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

void	ft_get_texture(char *line, t_config *c)
{
	char	**param;
	int		i;

	i = 0;
	if ((*line == 'S' && c->s) || (*line == 'N' && c->no) ||\
	(*line == 'E' && c->ea) || (*line == 'W' && c->we))
	{
		f_error("twice", c);
		return ;
	}
	param = ft_split(line, ' ');
	if (!check_param(c, param, line))
		f_error("texture", c);
	else
		free_tab(param, line, ' ');
}
