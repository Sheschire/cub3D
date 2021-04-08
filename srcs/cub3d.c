/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemesle <tlemesle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 15:46:31 by tlemesle          #+#    #+#             */
/*   Updated: 2021/04/08 15:51:27 by tlemesle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	check_fd_save_pokecub(int ac, char **av, t_config *c)
{
	int fd;
	
	if (av[1])
		fd = open(av[1], O_RDONLY);
	else
	{
		fd = 0;
		f_error("fd", c);
	}
	if (fd < 0)
		f_error("fd", c);
	if (ft_strcmp(av[1], "map/poke.cub") == 0)
		c->pkmn.pokecub = 1;
	if (ac == 3)
	{
		if (ft_strcmp(av[2], "--save") == 0)
			c->bmp_save = 1;
		else
			f_error("bmp", c);
	}
	return (fd);
}

int	main(int ac, char **av)
{
	int			fd;
	t_config	*c;

	c = malloc(sizeof(t_config));
	ft_init_t_config(c);
	fd = check_fd_save_pokecub(ac, av, c);
	ft_check_map(fd, c);
	init_mlx(c);
	return (0);
}
