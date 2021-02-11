#include "cub3D.h"

void    ft_init_s_player(s_player *player)
{
    player->x = 0;
    player->y = 0;
    player->pos = 0;
    player->pos_count = 0;
}

void    ft_init_s_map(s_map *map)
{
    map->R1 = 0;
    map->R2 = 0;
    map->NO = NULL;
    map->SO = NULL;
    map->WE = NULL;
    map->EA = NULL;
    map->S = NULL;
    map->F = NULL;
    map->C = NULL;
    map->x = 0;
    map->y = 0;
    map->param = NULL;
}