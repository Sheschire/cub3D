/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemesle <tlemesle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 10:58:21 by tlemesle          #+#    #+#             */
/*   Updated: 2021/04/09 13:25:33 by tlemesle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	free_image(t_config *c)
{
	if (PLATFORM == 2)
		mlx_destroy_image(c->v.mlx, c->img.img);
	else
	{
		free(c->img.img);
		c->img.addr = 0;
		free(c->img.addr);
		c->img.addr = 0;
	}
}

void	free_window(t_config *c)
{
	if (c->v.win)
		mlx_destroy_window(c->v.mlx, c->v.win);
	if (c->v.mlx)
	{
		if (PLATFORM == 2)
			mlx_destroy_display(c->v.mlx);
		free(c->v.mlx);
	}
}
