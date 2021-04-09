/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemesle <tlemesle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 13:23:15 by tlemesle          #+#    #+#             */
/*   Updated: 2021/04/09 13:36:20 by tlemesle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_ray(t_config *c)
{
	c->r.speed = 2 * (PI / 180);
	c->r.angle = 0;
	c->r.dir = 0;
	c->r.fov = 66 * (PI / 180);
	c->r.fov_angle = 0;
	c->r.n_rays = 0;
	c->r.verthit = 0;
}

char	*get_texture_addr_bonus(t_config *c, int n, char *filename)
{
	int		tmp[3];
	char	*addr_value;

	if (c->t[n].img != NULL)
		f_error("twice", c);
	if (!(c->t[n].img = mlx_xpm_file_to_image(c->v.mlx, filename, \
	&c->t[n].width, &c->t[n].height)))
		f_error("xpm", c);
	addr_value = mlx_get_data_addr(c->t[n].img, &tmp[0], &tmp[1], &tmp[2]);
	if (!addr_value)
		f_error("xpm", c);
	return (addr_value);
}

char	*get_texture_addr(t_config *c, int n, char **param)
{
	int		tmp[3];
	char	*addr_value;

	if (c->t[n].img != NULL)
	{
		free_tab(param, c->line, ' ');
		f_error("twice", c);
	}
	if (!(c->t[n].img = mlx_xpm_file_to_image(c->v.mlx, param[1], \
	&c->t[n].width, &c->t[n].height)))
	{
		free_tab(param, c->line, ' ');
		f_error("xpm", c);
	}
	addr_value = mlx_get_data_addr(c->t[n].img, &tmp[0], &tmp[1], &tmp[2]);
	if (!addr_value)
	{
		free_tab(param, c->line, ' ');
		f_error("xpm", c);
	}
	return (addr_value);
}

void	normalize_r_angle(t_config *c)
{
	if (c->r.angle > 2 * PI)
		c->r.angle -= 2 * PI;
	if (c->r.angle < 2 * -PI)
		c->r.angle += 2 * PI;
	if (c->r.angle < 0)
		c->r.angle += 2 * PI;
}

void	pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
