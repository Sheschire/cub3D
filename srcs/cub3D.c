#include "cub3D.h"

int main(int ac, char **av)
{
    int     fd;
    char    *map_path;
    s_error err;

    ft_init_s_error(&err);
    map_path = av[1];
    fd = open(map_path, O_RDONLY);
    if (fd < 0)
        _ERROR("fd", &err);
    ft_check_map(fd, &err);
    if (!err.boo)
        _ERROR("map", &err);
    return (0);
}