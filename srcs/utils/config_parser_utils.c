/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_parser_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemesle <tlemesle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 10:56:30 by tlemesle          #+#    #+#             */
/*   Updated: 2021/04/09 13:38:08 by tlemesle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	check_screen_size(t_config *c)
{
	int	sizex;
	int	sizey;

	if (c->r1 < 100)
		c->r1 = 100;
	if (c->r2 < 100)
		c->r2 = 100;
	if (PLATFORM == 2)
	{
		mlx_get_screen_size(c->v.mlx, &sizex, &sizey);
		if (c->r1 > sizex)
			c->r1 = sizex;
		if (c->r2 > sizey)
			c->r2 = sizey;
	}
	else
	{
		if (c->r1 > 1920)
			c->r1 = 1920;
		if (c->r1 > 1080)
			c->r2 = 1080;
	}
}

void	ft_split_colors_2(char *line, t_config *c, char **tmp)
{
	char	**rgb;

	rgb = ft_split(tmp[1], ',');
	if (!check_colors(rgb))
	{
		free_tab(rgb, line, ',');
		if (tmp)
			free_tab(tmp, line, ' ');
		f_error("colors", c);
	}
	else
		ft_get_colors(tmp, rgb, c);
	free_tab(rgb, line, ',');
}

void	ft_split_colors(char *line, t_config *c)
{
	char	**tmp;
	int		i;

	i = 0;
	if ((*line == 'C' && c->c_rgb != -1) || (*line == 'F' && c->f_rgb != -1))
		f_error("twice", c);
	tmp = ft_split(line, ' ');
	while (tmp[i])
		i++;
	if (i != 2 || (ft_strcmp(tmp[0], "F") != 0 && ft_strcmp(tmp[0], "C") != 0))
	{
		free_tab(tmp, line, ' ');
		f_error("param", c);
	}
	else
		ft_split_colors_2(line, c, tmp);
	free_tab(tmp, line, ' ');
}
