#include "cub3D.h"

int main(int ac, char **av)
{
    int         fd;
    char        *map_path;
    s_config    c;

    ft_init_s_config(&c);
    map_path = av[1];
    fd = open(map_path, O_RDONLY);
    if (fd < 0)
        _ERROR("fd", &c);
    ft_check_map(fd, &c);
    if (!c.error)
        _ERROR("map", &c);
    return (0);
}