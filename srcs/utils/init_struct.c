#include "cub3D.h"

void    ft_init_s_config(s_config *c)
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
    c->p.x = 0;
    c->p.y = 0;
    c->p.orient = 0;
    c->p.pos_count = 0;
    c->m.line = NULL;
    c->m.map = NULL;
    c->error = 1;
}
