#include "cub3D.h"

int ft_error_manager(int n)
{
    if (n == 1)
        ft_putstr_fd("Error\nFile Descriptor is invalid or missing.\n", 1);
    if (n == 2)
        ft_putstr_fd("Error\nMap file \"*.cub\" is not valid.\n", 1);
    return (-1);
}

int main()
{
    int     fd;
    char    *map_path;

    map_path = "./map.cub";
    fd = open(map_path, O_RDONLY);
    if (fd < 0)
        return (ft_error_manager(1));
    if (!ft_check_map(fd))
        return (ft_error_manager(2));
    return (0);
}