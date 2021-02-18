#include "cub3D.h"

void _ERROR(char  *s, s_error *ERR)
{
    if (s)
        ft_putstr("Error\n");
    if (ft_strcmp(s, "fd") == 0)
        ft_putstr("Files Descriptor is invalid or missing.\n");
    if (ft_strcmp(s, "map") == 0)
        ft_putstr("Map file \"*.cub\" is not valid.\n");
    if (ft_strcmp(s, "wall") == 0)
        ft_putstr("Problem in game map.(Walls or spaces)\n");
    if (ft_strcmp(s, "player") == 0)
        ft_putstr("Player missing or copies in game map.\n");
    if (ft_strcmp(s, "R") == 0)
        ft_putstr("Resolution is invalid.\n");
    if (ft_strcmp(s, "texture") == 0)
        ft_putstr("Texture parser detected an error.\n");
    if (ft_strcmp(s, "xpm") == 0)
        ft_putstr("Can't open one .xpm file.\n");
    if (ft_strcmp(s, "param") == 0)
        ft_putstr("Too much/few arguments in textures.\n");
    if (ft_strcmp(s, "config") == 0)
        ft_putstr("A config parameter is invalid or missing.\n");
    if (ft_strcmp(s, "emptyline") == 0)
        ft_putstr("Empty line detected in map.\n");
    if (ft_strcmp(s, "colors") == 0)
        ft_putstr("Colors format is invalid.\n");
    ERR->boo = 0;
}