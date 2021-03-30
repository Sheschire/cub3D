/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemesle <tlemesle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 15:43:22 by tlemesle          #+#    #+#             */
/*   Updated: 2021/03/30 12:01:11 by tlemesle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_get_path(t_config *c, char **param)
{
	size_t	i;

	i = ft_strlen(param[1]);
	if (param[1][i - 1] == 'm' && param[1][i - 2] == 'p' && \
	param[1][i - 3] == 'x' && param[1][i - 4] == '.')
	{
		if (ft_strcmp(param[0], "NO") == 0)
			c->no = ft_substr(param[1], 0, ft_strlen(param[1]));
		if (ft_strcmp(param[0], "SO") == 0)
			c->so = ft_substr(param[1], 0, ft_strlen(param[1]));
		if (ft_strcmp(param[0], "WE") == 0)
			c->we = ft_substr(param[1], 0, ft_strlen(param[1]));
		if (ft_strcmp(param[0], "EA") == 0)
			c->ea = ft_substr(param[1], 0, ft_strlen(param[1]));
		if (ft_strcmp(param[0], "S") == 0)
			c->s = ft_substr(param[1], 0, ft_strlen(param[1]));
	}
}

int		*get_texture_addr(t_config *c, int n, char *filename)
{
	int	tmp[3];
	int	*addr_value;

	addr_value = 0;
	if (!(c->t[n].img = mlx_xpm_file_to_image(c->v.mlx, filename, &c->t[n].width, &c->t[n].height)))
		f_error("xpm", c);
//	addr_value = (int *)mlx_get_data_addr(c->t[n].img, &tmp[0], &tmp[1], &tmp[2]);
//	if (!addr_value)
//		f_error("xpm", c);
	return (addr_value);
}

void	xpm_to_img(t_config *c)
{
	if (c->no)
		c->t[0].addr = get_texture_addr(c, 0, c->no);
/*	if (c->so)
		c->t[1].addr = get_texture_addr(c, 1, c->so);
	if (c->we)
		c->t[2].addr = get_texture_addr(c, 2, c->we);
	if (c->ea)
		c->t[3].addr = get_texture_addr(c, 3, c->ea);
	if (c->s)
		c->t[4].addr = get_texture_addr(c, 4, c->s);*/
}

void	ft_get_texture(char *line, t_config *c)
{
	char	**param;
	int		i;

	i = 0;
	if ((*line == 'S' && c->s) || (*line == 'N' && c->no) ||\
	(*line == 'E' && c->ea) || (*line == 'W' && c->we))
	{
		f_error("twice", c);
		return ;
	}
	param = ft_split(line, ' ');
	if (!check_param(c, param, line))
		f_error("texture", c);
	else
	{
		xpm_to_img(c);
		free_tab(param, line, ' ');
	}
}
