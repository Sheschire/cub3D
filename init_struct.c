#include "cub3D.h"

void    ft_init_s_player(s_player *player)
{
    player->x = 0;
    player->y = 0;
    player->pos = 0;
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
    conf->F = NULL;
    conf->C = NULL;
    conf->x = 0;
    conf->y = 0;
}