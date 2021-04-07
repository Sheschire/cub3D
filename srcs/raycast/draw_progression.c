#include "../../includes/cub3d.h"

void			adapt_progression_bar(t_config *c, int n)
{
	int		color;
	float	j;

	j = 165;
	c->y_tmp = (float)c->r2 * 0.1 - 1;
	while (++c->y_tmp <= (c->r2 * 0.145 - 1))
	{
		c->x_tmp = ((float)c->r1 * 0.4 - 1);
		c->i_tmp = 18;
		while (c->i_tmp < 343)
		{
			color = c->t[n].addr[(int)((int)j * (c->t[n].width * 4) + (int)c->i_tmp * 4)];
			if (color != 0x0000000)
				c->img.addr[(int)c->y_tmp * (c->r1 * 4) + (int)c->x_tmp * 4] = color;
			color = c->t[n].addr[(int)((int)j * (c->t[n].width * 4) + (int)c->i_tmp * 4 + 1)];
			if (color != 0x0000000)
				c->img.addr[(int)c->y_tmp * (c->r1 * 4) + (int)c->x_tmp * 4 + 1] = color;
			color = c->t[n].addr[(int)((int)j * (c->t[n].width * 4) + (int)c->i_tmp * 4 + 2)];
			if (color != 0x000000)
				c->img.addr[(int)c->y_tmp * (c->r1 * 4) + (int)c->x_tmp * 4 + 2] = color;
			c->i_tmp += (float)(c->t[n].width) / (float)((c->r1) * 0.25);
			c->x_tmp++;
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

void    draw_progression(t_config *c)
{
	if (c->pkmn.progress == 0)
		adapt_progression_bar(c, 14);
	if (c->pkmn.progress == 1)
		adapt_progression_bar(c, 15);
	if (c->pkmn.progress == 2)
		adapt_progression_bar(c, 16);
	if (c->pkmn.progress == 3)
		adapt_progression_bar(c, 17);
	if (c->pkmn.progress == 4)
		adapt_progression_bar(c, 18);
	if (c->pkmn.progress == 5)
	{
		c->pkmn.progress++;
		system("killall afplay");
		system("afplay ./sounds/victory.mp3 &");
	}
	if (c->pkmn.progress == 6)
		game_end_screen(c);
}