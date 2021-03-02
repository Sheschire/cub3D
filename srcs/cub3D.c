/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemesle <tlemesle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 15:46:31 by tlemesle          #+#    #+#             */
/*   Updated: 2021/03/01 15:43:55 by tlemesle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	return (0);
}
