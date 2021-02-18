#include "cub3D.h"

void    ft_init_s_player(s_player *player)
{
    player->x = 0;
    player->y = 0;
    player->orient = 0;
    player->pos_count = 0;
}

void    ft_init_s_config(s_config *conf)
{
    conf->r1 = 0;
    conf->r2 = 0;
    conf->no = NULL;
    conf->so = NULL;
    conf->we = NULL;
    conf->ea = NULL;
    conf->s = NULL;
    conf->f_rgb = -1;
    conf->c_rgb = -1;
    conf->x = 0;
    conf->y = 0;
}

void    ft_init_s_map(s_map *map)
{
    map->line = NULL;
    map->map = NULL;
}

void    ft_init_s_error(s_error *err)
{
    err->boo = 1;
}