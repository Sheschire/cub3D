# ifndef CUBE3D_H
# define CUBE3D_H

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <libc.h>
#include <stdlib.h>
#include "./gnl/get_next_line.h"
#include "./libft/libft.h"

typedef struct  t_player
{
	int         x;
	int         y;
	char        pos;
	int         pos_count;
}               s_player;

# endif