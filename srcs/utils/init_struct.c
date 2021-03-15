/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemesle <tlemesle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 15:32:01 by tlemesle          #+#    #+#             */
/*   Updated: 2021/03/15 16:00:27 by tlemesle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_player(t_config *c)
{
	c->p.x = 0;
	c->p.y = 0;
	c->p.orient = 0;
	c->p.pos_count = 0;
	c->p.walk = 0;
	c->p.left = 0;
	c->p.right = 0;
	c->p.speed = 0.05;
	c->p.dir_x = -1;
	c->p.dir_y = 0;
	c->p.plan_x = 0;
	c->p.plan_y = 0.66;
}

void	init_ray(t_config *c)
{
	c->r.speed = 4 * (PI / 180);
	c->r.angle = 0;
	c->r.dir = 0;
	c->r.fov = 90 * (PI / 180);
	c->r.fov_angle = 0;
	c->r.n_rays = 0;
	c->r.hit_x = 0;
	c->r.hit_y = 0;
}

void	ft_init_t_config(t_config *c)
{
	c->r1 = 0;
	c->r2 = 0;
	c->no = NULL;
	c->so = NULL;
	c->we = NULL;
	c->ea = NULL;
	c->s = NULL;
	c->f_rgb = -1;
	c->c_rgb = -1;
	c->x = 0;
	c->y = 0;
	c->m.line = NULL;
	c->m.map = NULL;
	init_player(c);
	init_ray(c);
}
