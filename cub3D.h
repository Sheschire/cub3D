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

typedef struct	t_map
{
	int			R1;
	int			R2;
	char		*NO;
	char		*SO;
	char		*WE;
	char		*EA;
	char		*S;
	int			F1;
	int			F2;
	int			F3;
	char		*C;
	int			x;
	int			y;
	char		*param
}				s_map;

# endif