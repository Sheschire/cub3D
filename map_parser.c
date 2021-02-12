#include "cub3D.h"

int main()
{
    int     fd;
    char    *map_path;
    s_error ERR;

    ft_init_s_error(&ERR);
    map_path = "./map.cub";
    fd = open(map_path, O_RDONLY);
    if (fd < 0)
        _ERROR("fd", &ERR);
    if (!ft_check_map(fd, &ERR))
        _ERROR("map", &ERR);
    return (0);
}