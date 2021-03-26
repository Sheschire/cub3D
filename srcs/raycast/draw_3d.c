/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_3d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemesle <tlemesle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 14:22:25 by tlemesle          #+#    #+#             */
/*   Updated: 2021/03/26 16:39:23 by tlemesle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void    clear_rgb_buf(t_config *c, unsigned int color)
{
    int x;
    int y;

    x = 0;
    while (x <c->r1)
    {
        y = 0;
        while (y < c->r2)
        {
            c->w.rgb_buf[(c->r1 * y) + x] = color;
            y++;
        }
        x++;
    }
}

void    draw_background(t_config *c)
{
    int x;
    int y;

    y = 0;
    while (y < c->r2)
    {
        x = 0;
        while (x < c->r1)
        {
            if (y < c->r2 / 2)
                pixel_put(&c->img, x, y, c->c_rgb);
            else
                pixel_put(&c->img, x, y, c->f_rgb);
            x++;
        }
        y++;
    }
}

void    draw_3d(t_config *c)
{
    unsigned int     color;

    color = 0xFF000000;
    draw_background(c);
  //  clear_rgb_buf(c, color);
}