#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct  s_data {
	void        *img;
	char        *addr;
	int         bits_per_pixel;
	int         line_length;
	int         endian;
}               t_data;

void            ft_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char    *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

typedef struct  s_vars {
    void        *mlx;
    void        *win;
}               t_vars;

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
} 



/*
int main()
{
	void *mlx;
	void *mlx_win;
	t_data img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 800, 600, "Hello World!");
	mlx_hook(mlx_win, 2, 1L<<0, close, mlx);
	img.img = mlx_new_image(mlx, 800, 600);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

//  DRAW SQUARE / RECTANGLE

	int i = 200;
	int j = 201;
	while (j < 400)
	{
		i = 200;
		while (i < 600)
			ft_mlx_pixel_put(&img, i++, j, 0x00FF0000);
		j++;
	}

//	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}*/

