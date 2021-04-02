/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemesle <tlemesle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 13:51:58 by tlemesle          #+#    #+#             */
/*   Updated: 2021/03/31 17:55:54 by tlemesle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_sprite(t_config *c, int n, int x, int y)
{
	c->sp[n].topx = 0;
	c->sp[n].topy = 0;
	c->sp[n].botx = 0;
	c->sp[n].boty = 0;
	c->sp[n].screenx = 0;
	c->sp[n].newy = 0;
	c->sp[n].x = x * TILE + TILE / 2;
	c->sp[n].y = y * TILE + TILE / 2;
	c->sp[n].dist = hypot(c->sp[n].x - (c->p.x * TILE), c->sp[n].y - (c->p.y * TILE));
	c->sp[n].num = c->m.map[y][x] - '0';
	c->sp[n].height = c->t[c->sp[n].num + 2].height;
	c->sp[n].width = c->t[c->sp[n].num + 2].width;
}

void	find_sprite(t_config *c)
{
	int	x;
	int	y;

	y = -1;
	if (c->buff)
		free(c->buff);
	c->buff = malloc(sizeof(float) * c->r1);
	ft_bzero(c->buff, sizeof(float) * c->r1);
	while (++y < c->y_max)
	{
		x = -1;
		while (++x < c->x_max)
		{
			if (is_in_set(c->m.map[y][x], "2345"))
			{
				init_sprite(c, c->n_sprite, x, y);
				c->n_sprite++;
			}
		}
	}
}

void	update_dist_sprites(t_config *c)
{
	int	i;
	
	i = -1;
	while (++i < c->n_sprite)
		c->sp[i].dist = hypot(c->sp[i].x - (c->p.x * TILE), c->sp[i].y - (c->p.y * TILE));
}

void	sort_sprites(t_config *c)
{
	int		i;
	int		n;
	int		sorted;
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

void	get_newy(t_config *c, int i)
{
	float	delt_x;
	float	delt_y;
	float	inv_det;
	float	newx;
	float	newy;

	delt_x = c->sp[i].x - c->p.x * TILE;
	delt_y = c->sp[i].y - c->p.y * TILE;
	inv_det = 1.0 / ((c->p.planx * c->p.ydir) - (c->p.xdir * c->p.plany));
	newx = inv_det * (c->p.ydir * delt_x - c->p.xdir * delt_y);
	newy = inv_det * (-c->p.plany * delt_x + c->p.planx * delt_y);
	c->sp[i].screenx = (int)((c->r1 / 2) * (1 + -newx / newy));
	c->sp[i].newy = newy;
}

void	get_sprite_size(t_config *c, int i)
{
	float	coef;

	if (c->sp[i].num == 2)
		coef = 1;
	else if (c->sp[i].num == 3 || c->sp[i].num == 5)
		coef = 0.3;
	else if (c->sp[i].num == 4)
		coef = 2;
	c->sp[i].size = TILE * coef * fabs((int)c->r2 / c->sp[i].newy);
}

void	get_coord_draw(t_sprite *sp, t_config*c)
{
	int		tmpw;
	int		tmph;

	tmpw = sp->size;
	sp->topx = -tmpw / 2 + sp->screenx;
	if (sp->topx < 0)
		sp->topx = 0;
	sp->botx = tmpw / 2 + sp->screenx;
	if (sp->botx >= c->r1)
		sp->botx = c->r1;
	tmph = sp->size;
	sp->topy = -tmph / 2 + c->r2 / 2;
	if (sp->topy < 0)
		sp->topy = 0;
	sp->boty = tmph / 2 + c->r2 / 2;
	if (sp->boty >= c->r2)
		sp->boty = c->r2;
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