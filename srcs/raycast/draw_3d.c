/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_3d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemesle <tlemesle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 14:22:25 by tlemesle          #+#    #+#             */
/*   Updated: 2021/03/29 14:38:44 by tlemesle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void    draw_3d(t_config *c, int column)
{
    float   dist_proj_plane;
    float   wall_height;
    float   perp_dist;
    int     wall_strip;
    int     wall_top;
    int     wall_bottom;
    int     y;
    
    perp_dist = c->r.dist_p_hit * cos(c->r.fov_angle - c->r.angle);
    dist_proj_plane = (c->r1 / 2) / tan(c->r.fov / 2);
    wall_height = (TILE / perp_dist) * dist_proj_plane;
    wall_strip = (int)wall_height;
    wall_top = (c->r2 / 2) - (wall_strip / 2);
    if (wall_top < 0)
        wall_top = 0;
    wall_bottom = (c->r2 / 2) + (wall_strip / 2);
    if (wall_bottom > c->r2)
        wall_bottom = c->r2;
    y = wall_top;
    while (y < wall_bottom)
    {
        if (c->r.verthit == 0)
            pixel_put(&c->img, column, y, 0x00D6C5CC);
        else
            pixel_put(&c->img, column, y, 0x00D6C5EE);
        y++;
    }
}