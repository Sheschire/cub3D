/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemesle <tlemesle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 15:43:22 by tlemesle          #+#    #+#             */
/*   Updated: 2021/03/31 16:58:56 by tlemesle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	get_path_2(t_config *c, char **param)
{
	if (ft_strcmp(param[0], "S1") == 0)
		c->s1 = ft_substr(param[1], 0, ft_strlen(param[1]));
	if (ft_strcmp(param[0], "S2") == 0)
		c->s2 = ft_substr(param[1], 0, ft_strlen(param[1]));
	if (ft_strcmp(param[0], "S3") == 0)
		c->s3 = ft_substr(param[1], 0, ft_strlen(param[1]));
	if (ft_strcmp(param[0], "S4") == 0)
		c->s4 = ft_substr(param[1], 0, ft_strlen(param[1]));
	if (ft_strcmp(param[0], "S5") == 0)
		c->s5 = ft_substr(param[1], 0, ft_strlen(param[1]));
	if (ft_strcmp(param[0], "S6") == 0)
		c->s6 = ft_substr(param[1], 0, ft_strlen(param[1]));
	if (ft_strcmp(param[0], "S7") == 0)
		c->s7 = ft_substr(param[1], 0, ft_strlen(param[1]));
	if (ft_strcmp(param[0], "S8") == 0)
		c->s8 = ft_substr(param[1], 0, ft_strlen(param[1]));
}

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
		get_path_2(c, param);
	}
}

void	xpm_to_img_2(t_config *c)
{
	if (c->s1)
		c->t[5].addr = get_texture_addr(c, 5, c->s1);
	if (c->s2)
		c->t[6].addr = get_texture_addr(c, 6, c->s2);
	if (c->s3)
		c->t[7].addr = get_texture_addr(c, 7, c->s3);
	if (c->s4)
		c->t[8].addr = get_texture_addr(c, 8, c->s4);
	if (c->s5)
		c->t[9].addr = get_texture_addr(c, 9, c->s5);
	if (c->s6)
		c->t[10].addr = get_texture_addr(c, 10, c->s6);
	if (c->s7)
		c->t[11].addr = get_texture_addr(c, 11, c->s7);
	if (c->s8)
		c->t[12].addr = get_texture_addr(c, 12, c->s8);
	c->t[13].addr = get_texture_addr(c, 13, "./images/startscreen.xpm");
	c->t[14].addr = get_texture_addr(c, 14, "./images/progression.xpm");
	c->t[15].addr = get_texture_addr(c, 15, "./images/progression2.xpm");
	c->t[16].addr = get_texture_addr(c, 16, "./images/progression3.xpm");
	c->t[17].addr = get_texture_addr(c, 17, "./images/progression4.xpm");
	c->t[18].addr = get_texture_addr(c, 18, "./images/progression5.xpm");
	c->t[19].addr = get_texture_addr(c, 19, "./images/end_screen.xpm");
}

void	xpm_to_img(t_config *c)
{
	if (c->no)
		c->t[0].addr = get_texture_addr(c, 0, c->no);
	if (c->so)
		c->t[1].addr = get_texture_addr(c, 1, c->so);
	if (c->we)
		c->t[2].addr = get_texture_addr(c, 2, c->we);
	if (c->ea)
		c->t[3].addr = get_texture_addr(c, 3, c->ea);
	if (c->s)
		c->t[4].addr = get_texture_addr(c, 4, c->s);
	xpm_to_img_2(c);
}

void	ft_get_texture(char *line, t_config *c)
{
	char	**param;
	int		i;

	i = 0;
	param = ft_split(line, ' ');
	if (!check_param(c, param, line))
		f_error("texture", c);
	else
	{
		xpm_to_img(c);
		free_tab(param, line, ' ');
	}
}
