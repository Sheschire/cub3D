/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemesle <tlemesle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 15:42:10 by tlemesle          #+#    #+#             */
/*   Updated: 2021/02/23 15:43:13 by tlemesle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_get_player(t_config *c, int x, int y)
{
	c->p.pos_count++;
	c->p.x = x;
	c->p.y = y;
	c->p.orient = c->m.map[y][x];
	c->m.map[y][x] = '0';
}

void	add_walls(t_config *c, int y, int x, int len)
{
	int		diff;
	char	*to_join;

	diff = len - x;
	to_join = (char *)malloc(sizeof(char) * diff + 1);
	if (!to_join)
		return ;
	x = 0;
	while (x < diff)
		to_join[x++] = '1';
	to_join[x] = '\0';
	c->m.map[y] = ft_strjoin(c->m.map[y], to_join, 3);
}

void	fill_spaces(t_config *c)
{
	int	len;
	int	y;
	int	x;

	y = 0;
	len = greatest_line_len(c->m.map);
	while (c->m.map[y])
	{
		x = 0;
		while (c->m.map[y][x])
		{
			if (c->m.map[y][x] == ' ' || c->m.map[y][x] == '	')
				c->m.map[y][x] = '1';
			x++;
		}
		if (ft_strlen(c->m.map[y]) < (size_t)len)
			add_walls(c, y, x, len);
		y++;
	}
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
			f_error("line_after_map", c);
		get_map(line, c);
	}
	if (*line && !is_map_1st_line(line))
		f_error("wall", c);
	get_map(line, c);
}
