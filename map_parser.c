#include "cub3D.h"

int ft_check_empty_lines(char **map)
{
    
}

int main()
{
    int     fd;
    char    *map_path;

    map_path = "./map.cub";
    fd = open (map_path, O_RDONLY);
    if (fd < 0)
        return (-1);
    if (!ft_check_map(fd))
        return (-1);
    return (0);
}