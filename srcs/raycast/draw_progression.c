/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_progression.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemesle <tlemesle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 13:52:15 by tlemesle          #+#    #+#             */
/*   Updated: 2021/04/07 13:56:43 by tlemesle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	adapt_progression_bar(t_config *c, int n, int i)
{
	int		co;
	float	j;

	j = 165;
	c->y_tmp = (float)c->r2 * 0.1 - 1;
	while (++c->y_tmp <= (c->r2 * 0.145 - 1))
	{
		c->xb = ((float)c->r1 * 0.4 - 1);
		c->i_tmp = 18;
		while (c->i_tmp < 343)
		{
			while (++i < 3)
			{
				co = c->t[n].addr[(int)((int)j * (c->t[n].width * 4) \
				+ (int)c->i_tmp * 4 + i)];
				if (co != 0x0000000)
					c->img.addr[(int)c->y_tmp * (c->r1 * 4) \
					+ (int)c->xb * 4 + i] = co;
				c->i_tmp += (float)(c->t[n].width) / (float)((c->r1) * 0.25);
			}
			c->xb++;
		}
		j += (float)(c->t[n].height - 1) / (float)(c->r2 * 0.5);
	}
}

void	game_end_screen(t_config *c)
{
	int x;
	int y;
	int	color;

	y = 0;
	while (y < c->r2)
	{
		x = 0;
		while (x < c->r1)
		{
			color = c->t[19].addr[(c->t[19].width * y * 4) + x * 4];
			c->img.addr[(y * c->r1 * 4) + x * 4] = color;
			color = c->t[19].addr[(c->t[19].width * y * 4) + x * 4 + 1];
			c->img.addr[(y * c->r1 * 4) + x * 4 + 1] = color;
			color = c->t[19].addr[(c->t[19].width * y * 4) + x * 4 + 2];
			c->img.addr[(y * c->r1 * 4) + x * 4 + 2] = color;
			color = c->t[19].addr[(c->t[19].width * y * 4) + x * 4 + 3];
			c->img.addr[(y * c->r1 * 4) + x * 4 + 3] = color;
			x++;
		}
		y++;
	}
}

void	draw_progression(t_config *c)
{
	if (c->pkmn.progress == 0)
		adapt_progression_bar(c, 14, -1);
	if (c->pkmn.progress == 1)
		adapt_progression_bar(c, 15, -1);
	if (c->pkmn.progress == 2)
		adapt_progression_bar(c, 16, -1);
	if (c->pkmn.progress == 3)
		adapt_progression_bar(c, 17, -1);
	if (c->pkmn.progress == 4)
		adapt_progression_bar(c, 18, -1);
	if (c->pkmn.progress == 5)
	{
		c->pkmn.progress++;
		system("killall afplay");
		system("afplay ./sounds/victory.mp3 &");
	}
	if (c->pkmn.progress == 6)
		game_end_screen(c);
}
