/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemesle <tlemesle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 15:46:31 by tlemesle          #+#    #+#             */
/*   Updated: 2021/03/30 11:54:19 by tlemesle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int ac, char **av)
{
	int			fd;
	char		*map_path;
	t_config	c;

	ft_init_t_config(&c);
	map_path = av[1];
	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		f_error("fd", &c);
	ft_check_map(fd, &c);
	c.r.angle = 0;
	init_mlx(&c);
	return (0);
}
