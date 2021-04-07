/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_saver.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemesle <tlemesle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 13:25:08 by tlemesle          #+#    #+#             */
/*   Updated: 2021/04/07 13:26:17 by tlemesle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		ft_fill_header(int fd, t_config *c)
{
	int		tmp;
	int		i;

	i = -1;
	write(fd, "BM", 2);
	tmp = 14 + 40 + 4 * c->r1 * c->r2;
	write(fd, &tmp, 4);
	tmp = 0;
	write(fd, &tmp, 2);
	write(fd, &tmp, 2);
	tmp = 54;
	write(fd, &tmp, 4);
	tmp = 40;
	write(fd, &tmp, 4);
	write(fd, &c->r1, 4);
	write(fd, &c->r2, 4);
	tmp = 1;
	write(fd, &tmp, 2);
	write(fd, &c->img.bits_per_pixel, 2);
	tmp = 0;
	while (++i < 6)
		write(fd, &tmp, 4);
}

static void		ft_fill_pixel(int fd, t_config *c)
{
	int		x;
	int		y;
	int		r;
	int		g;
	int		b;

	y = c->r2;
	while (--y >= 0)
	{
		x = -1;
		while (++x < c->r1)
		{
			r = c->img.addr[y * c->img.line_length + x * \
			c->img.bits_per_pixel / 8];
			g = c->img.addr[y * c->img.line_length + x * \
			c->img.bits_per_pixel / 8 + 1];
			b = c->img.addr[y * c->img.line_length + x *\
			c->img.bits_per_pixel / 8 + 2];
			write(fd, &r, 1);
			write(fd, &g, 1);
			write(fd, &b, 1);
			write(fd, "\0", 1);
		}
	}
}

void			ft_bmp_saver(t_config *c)
{
	int		fd;

	fd = open("img_saved.bmp", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	if (fd > 0)
	{
		ft_fill_header(fd, c);
		ft_fill_pixel(fd, c);
	}
	else
		f_error("bmp", c);
}
