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
    conf->R1 = 0;
    conf->R2 = 0;
    conf->NO = NULL;
    conf->SO = NULL;
    conf->WE = NULL;
    conf->EA = NULL;
    conf->S = NULL;
    conf->F_rgb = -1;
    conf->C_rgb = -1;
    conf->x = 0;
    conf->y = 0;
}

void    ft_init_s_map(s_map *map)
{
    map->line = NULL;
    map->map = NULL;
}

void    ft_init_s_error(s_error *ERR)
{
    ERR->boo = 1;
}