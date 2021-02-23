#include "cub3d.h"

int main(int ac, char **av)
{
    int         fd;
    char        *map_path;
    t_config    c;

    ft_init_t_config(&c);
    map_path = av[1];
    fd = open(map_path, O_RDONLY);
    if (fd < 0)
        f_error("fd", &c);
    ft_check_map(fd, &c);
    if (!c.error)
        f_error("map", &c);
    return (0);
}