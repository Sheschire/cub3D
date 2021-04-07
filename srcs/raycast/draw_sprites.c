/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemesle <tlemesle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 13:51:58 by tlemesle          #+#    #+#             */
/*   Updated: 2021/04/07 14:02:29 by tlemesle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	update_dist_sprites(t_config *c)
{
	int	i;

	i = -1;
	while (++i < c->n_sprite)
		c->sp[i].dist = hypot(c->sp[i].x - (c->p.x * TILE), \
		c->sp[i].y - (c->p.y * TILE));
}

void	sort_sprites(t_config *c)
{
	int			i;
	int			n;
	int			sorted;
	t_sprite	tmp;

	sorted = 0;
	n = c->n_sprite;
	update_dist_sprites(c);
	while (sorted == 0)
	{
		sorted = 1;
		i = 0;
		while (i < n - 1)
		{
			if (c->sp[i].dist < c->sp[i + 1].dist)
			{
				tmp = c->sp[i];
				c->sp[i] = c->sp[i + 1];
				c->sp[i + 1] = tmp;
				sorted = 0;
			}
			i++;
		}
		n--;
	}
}

void	draw_textures_sprite(t_sprite *sp, int x, int y, t_config *c)
{
	int	color;
	int	textx;
	int	texty;
	int	offsety;

	textx = (int)(256 * (x - (-sp->size / 2 + sp->screenx)) *
				(sp->width - 1) / sp->size) / 256;
	while (y < sp->boty)
	{
		offsety = y * 256 - c->r2 * 128 + sp->size * 128;
		texty = ((offsety * sp->height) / sp->size) / 256;
		if ((texty * sp->width) + textx < (int)sizeof(c->t[sp->num + 2].addr))
			return ;
		color = c->t[sp->num + 2].addr[(texty * sp->width * 4) + textx * 4];
		if (color != -16777216 && color != 0x000000)
			c->img.addr[(y * c->r1 * 4) + x * 4] = color;
		color = c->t[sp->num + 2].addr[(texty * sp->width * 4) + textx * 4 + 1];
		if (color != -16777216 && color != 0x000000)
			c->img.addr[(y * c->r1 * 4) + x * 4 + 1] = color;
		color = c->t[sp->num + 2].addr[(texty * sp->width * 4) + textx * 4 + 2];
		if (color != -16777216 && color != 0x000000)
			c->img.addr[(y * c->r1 * 4) + x * 4 + 2] = color;
		y++;
	}
}

void	draw_one_sprite(t_sprite *sp, float newy, t_config *c)
{
	int	x;
	int	y;

	x = sp->topx;
	while (x <= sp->botx)
	{
		if (newy > 0 && x > 0 && x < c->r1 && newy < c->buff[x])
		{
			y = sp->topy;
			draw_textures_sprite(sp, x, y, c);
		}
		x++;
	}
}

void	draw_sprites(t_config *c)
{
	int	i;

	i = 0;
	sort_sprites(c);
	while (i < c->n_sprite)
	{
		get_newy(c, i);
		get_sprite_size(c, i);
		get_coord_draw(&c->sp[i], c);
		draw_one_sprite(&c->sp[i], c->sp[i].newy, c);
		i++;
	}
}
