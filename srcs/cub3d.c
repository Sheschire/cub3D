/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemesle <tlemesle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 15:46:31 by tlemesle          #+#    #+#             */
/*   Updated: 2021/04/07 19:03:38 by tlemesle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int ac, char **av)
{
	int			fd;
	char		*map_path;
	t_config	*c;

	c = malloc(sizeof(t_config));
	ft_init_t_config(c);
	c->pkmn.pokecub = 0;
	map_path = av[1];
	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		f_error("fd", c);
	if (ft_strcmp(av[1], "./map/poke.cub") == 0)
		c->pkmn.pokecub = 1;
	if (ac == 3)
	{
		if (ft_strcmp(av[2], "--save") == 0)
			c->bmp_save = 1;
		else
			f_error("bmp", c);
	}
	c->v.mlx = mlx_init();
	ft_check_map(fd, c);
	player_orientation(c);
	init_mlx(c);
	return (0);
}
