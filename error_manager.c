#include "cub3D.h"

void _ERROR(char  *s, s_error *ERR)
{
    ft_putstr("Error\n");
    if (ft_strcmp(s, "fd") == 0)
        ft_putstr("Files Descriptor is invalid or missing.\n");
    if (ft_strcmp(s, "map") == 0)
        ft_putstr("Map file \"*.cub\" is not valid.\n");
    if (ft_strcmp(s, "wall") == 0)
        ft_putstr("Problem in game map.(Walls or spaces)\n");
    if (ft_strcmp(s, "player") == 0)
        ft_putstr("Player missing or copies in game map.\n");
    ERR->boo = 0;
}