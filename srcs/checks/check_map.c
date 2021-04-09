/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemesle <tlemesle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 15:20:14 by tlemesle          #+#    #+#             */
/*   Updated: 2021/04/09 13:40:46 by tlemesle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int		check_udrl(t_config *c, int y, int x)
{
	if (is_in_set(c->m.map[y][0], "23456789T0NSWE"))
		return (0);
	if (x > (int)ft_strlen(c->m.map[y + 1]))
		return (0);
	if (!is_in_set(c->m.map[y - 1][x], "123456789T0NSWE"))
		return (0);
	if (!is_in_set(c->m.map[y + 1][x], "123456789T0NSWE"))
		return (0);
	if (!is_in_set(c->m.map[y][x + 1], "123456789T0NSWE"))
		return (0);
	if (!is_in_set(c->m.map[y][x - 1], "123456789T0NSWE"))
		return (0);
	return (1);
}

int		ft_check_walls(t_config *c)
{
	int	x;
	int y;

	y = 0;
	while (c->m.map[y])
	{
		x = 0;
		while (c->m.map[y][x])
		{
			if (!is_in_set(c->m.map[y][x], " 123456789T0NSEW"))
				return (0);
			if (c->m.map[y][x] == 'N' || c->m.map[y][x] == 'S' || \
			c->m.map[y][x] == 'E' || c->m.map[y][x] == 'W')
				ft_get_player(c, x, y);
			if (is_in_set(c->m.map[y][x], "023456789TNSWE"))
				if (!ft_strchr(c->m.map[y + 1], '1') || !check_udrl(c, y, x))
					return (0);
			x++;
		}
		y++;
	}
	return (1);
}

char	*space_to_join(t_config *c, int len)
{
	int		i;
	int		size;
	char	*space;

	i = 0;
	size = c->x_max - len;
	space = (char *)malloc(sizeof(char) * size + 1);
	if (!space)
		ft_exit(c);
	while (i < size)
		space[i++] = '1';
	space[i] = '\0';
	return (space);
}

void	adapt_to_greatest(t_config *c)
{
	int		y;
	int		len;
	char	*space;

	y = 0;
	while (c->m.map[y])
	{
		len = (int)ft_strlen(c->m.map[y]);
		if (len < c->x_max)
		{
			space = space_to_join(c, len);
			c->m.map[y] = ft_strjoin(c->m.map[y], space, 3);
		}
		y++;
	}
}

void	ft_check_map(int fd, t_config *c)
{
	c->line_bool = 1;
	ft_config(fd, c);
	map_gnl(fd, c->line, c);
	c->m.map = ft_split(c->m.line, '*');
	if (!ft_check_walls(c))
	{
		c->line_bool = 0;
		f_error("wall", c);
	}
	if (c->p.pos_count != 1)
	{
		c->line_bool = 0;
		f_error("player", c);
	}
	greatest_x_y_max(c);
	adapt_to_greatest(c);
	init_sprites(c);
	c->line_bool = 0;
	c->v.win = mlx_new_window(c->v.mlx, c->r1, c->r2, "Pokecube 3D");
}
