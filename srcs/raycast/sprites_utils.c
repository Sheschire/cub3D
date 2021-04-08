/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemesle <tlemesle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 13:57:27 by tlemesle          #+#    #+#             */
/*   Updated: 2021/04/08 13:59:46 by tlemesle         ###   ########.fr       */
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
	c->sp[n].dist = hypot(c->sp[n].x - (c->p.x * TILE), \
	c->sp[n].y - (c->p.y * TILE));
	c->sp[n].num = c->m.map[y][x] - '0';
	if (c->m.map[y][x] == 'T')
		c->sp[n].num = 10;
	c->sp[n].height = c->t[c->sp[n].num + 2].height;
	c->sp[n].width = c->t[c->sp[n].num + 2].width;
}

void	find_sprite(t_config *c)
{
	int	x;
	int	y;

	y = -1;
	c->n_sprite = 0;
	if (c->buff)
		free(c->buff);
	c->buff = malloc(sizeof(float) * c->r1);
	ft_bzero(c->buff, sizeof(float) * c->r1);
	while (++y < c->y_max)
	{
		x = -1;
		while (++x < c->x_max)
		{
			if (is_in_set(c->m.map[y][x], "23456789T"))
			{
				init_sprite(c, c->n_sprite, x, y);
				c->n_sprite++;
			}
		}
	}
}

void	get_coord_draw(t_sprite *sp, t_config *c)
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

void	get_sprite_size(t_config *c, int i)
{
	float	coef;

	if (c->sp[i].num == 3 || c->sp[i].num == 5 || c->sp[i].num == 9)
		coef = 0.3;
	else if (c->sp[i].num == 8)
		coef = 0.8;
	else if (c->sp[i].num == 4)
		coef = 2;
	else if (c->sp[i].num == 7 || c->sp[i].num == 2)
		coef = 3;
	else
		coef = 1.7;
	c->sp[i].size = TILE * coef * fabs((int)c->r2 / c->sp[i].newy);
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
