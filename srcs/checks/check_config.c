/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_config.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemesle <tlemesle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 15:18:22 by tlemesle          #+#    #+#             */
/*   Updated: 2021/03/30 10:26:06 by tlemesle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		check_config(t_config *c)
{
	if (c->r1 && c->r2 && c->no && c->so && \
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
	return (1);
}
