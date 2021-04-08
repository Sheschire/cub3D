/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemesle <tlemesle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 15:42:10 by tlemesle          #+#    #+#             */
/*   Updated: 2021/04/08 19:15:06 by tlemesle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	greatest_x_y_max(t_config *c)
{
	int	y;
	int	x;
	int	len;

	y = 0;
	len = 0;
	while (c->m.map[y])
	{
		x = 0;
		while (c->m.map[y][x])
		{
			if (c->m.map[y][x] == ' ')
				c->m.map[y][x] = '1';
			x++;
		}
		if (x > len)
			len = x;
		y++;
	}
	c->x_max = len;
	c->abs = (float)c->r1 / (float)c->x_max;
	c->y_max = y;
	c->ord = (float)c->r2 / (float)c->y_max;
}

void	ft_get_player(t_config *c, int x, int y)
{
	c->p.pos_count++;
	c->p.x = x;
	c->p.y = y;
	c->p.orient = c->m.map[y][x];
	c->m.map[y][x] = '0';
	player_orientation(c);
}

void	get_map(char *line, t_config *c)
{
	char	*tmp;

	tmp = ft_strjoin(line, "*", 1);
	if (c->m.line == NULL)
		c->m.line = ft_strdup(tmp);
	else
		c->m.line = ft_strjoin(c->m.line, tmp, 1);
	free(tmp);
}

void	map_gnl(int fd, char *line, t_config *c)
{
	int	ret;
	int	end_map;

	end_map = 0;
	if (is_map_1st_line(line))
		get_map(line, c);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if (!*line)
			end_map = 1;
		if (*line && end_map == 1)
		{
			c->line_bool = 0;
			free(line);
			f_error("line_after_map", c);
		}
		get_map(line, c);
	}
	if (*line && !is_map_1st_line(line))
	{
		c->line_bool = 0;
		f_error("wall", c);
	}
	get_map(line, c);
}
