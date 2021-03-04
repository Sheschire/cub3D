#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
/*
void            ft_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char    *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	close(int keycode, t_vars *vars)
{
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	return (1);
}

int             key_hook(int keycode, t_vars *vars)
{
    printf("You pressed : %d\n", keycode);
	close(keycode, vars);
}

int             main(void)
{
    t_vars      vars;

    vars.mlx = mlx_init();
    vars.win = mlx_new_window(vars.mlx, 640, 480, "Hello world!");
    mlx_key_hook(vars.win, key_hook, &vars);
    mlx_loop(vars.mlx);
}*/
