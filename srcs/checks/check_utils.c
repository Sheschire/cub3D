/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemesle <tlemesle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 15:27:10 by tlemesle          #+#    #+#             */
/*   Updated: 2021/04/08 10:01:30 by tlemesle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int		is_map_1st_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '1' && line[i] != '\t')
			return (0);
		i++;
	}
	if (ft_strchr(line, '1'))
		return (1);
	return (0);
}

int		is_in_set(char c, char *set)
{
	int		i;

	i = 0;
	while (set[i])
		if (c == set[i++])
			return (1);
	return (0);
}

void	count_sprites(t_config *c)
{
	int	x;
	int	y;

	y = -1;
	c->n_sprite = 0;
	while (++y < c->y_max)
	{
		x = -1;
		while (++x < c->x_max)
		{
			if (is_in_set(c->m.map[y][x], "23456789T"))
				c->n_sprite++;
		}
	}
}
