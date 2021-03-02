/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemesle <tlemesle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 15:20:14 by tlemesle          #+#    #+#             */
/*   Updated: 2021/03/02 17:03:17 by tlemesle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		check_UDRL(t_config *c, int y, int x)
{
	if (!is_in_set(c->m.map[y - 1][x], "120NSWE"))
		return (0);
	if (!is_in_set(c->m.map[y + 1][x], "120NSWE"))
		return (0);
	if (!is_in_set(c->m.map[y][x + 1], "120NSWE"))
		return (0);
	if (!is_in_set(c->m.map[y][x - 1], "120NSWE"))
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
			if (!is_in_set(c->m.map[y][x], " 120NSEW"))
				return (0);
			if (c->m.map[y][x] == 'N' || c->m.map[y][x] == 'S' || \
			c->m.map[y][x] == 'E' || c->m.map[y][x] == 'W')
				ft_get_player(c, x, y);
			if (c->m.map[y][x] == '0')
				if (!check_UDRL(c, y, x))
					return (0);
			x++;
		}
		y++;
	}
	return (1);
}

void	tmp_print_check(t_config *c)
{
	int	i;

	i = 0;
	printf("[MAP CHECK]\n\n");
	while (c->m.map[i])
		printf("%s\n", c->m.map[i++]);
	printf("\n");
	printf("[CONFIG CHECK]\n\n");
	printf("RESOLUTION = %d %d\n", c->r1, c->r2);
	printf("NO TEXTURE = %s\n", c->no);
	printf("SO TEXTURE = %s\n", c->so);
	printf("WE TEXTURE = %s\n", c->we);
	printf("EA TEXTURE = %s\n", c->ea);
	printf("S TEXTURE = %s\n\n", c->s);
	printf("F COLOR = %d\n\n", c->f_rgb);
	printf("C COLOR = %d\n\n", c->c_rgb);
	printf("PLAYER CHECK\n\n");
	printf("POSITION = %c\n", c->p.orient);
	printf("x = %d\n", c->p.x);
	printf("y = %d\n", c->p.y);
}

void	ft_check_map(int fd, t_config *c)
{
	char	*line;

	line = ft_config(fd, c);
	map_gnl(fd, line, c);
	c->m.map = ft_split(c->m.line, '*');
	if (!ft_check_walls(c))
		f_error("wall", c);
//	fill_spaces(c);
	if (c->p.pos_count != 1)
		f_error("player", c);
	tmp_print_check(c);
//	ft_exit(c);
}
