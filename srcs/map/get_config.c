/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_config.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemesle <tlemesle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 15:33:06 by tlemesle          #+#    #+#             */
/*   Updated: 2021/04/08 16:07:38 by tlemesle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_get_r(char *line, t_config *c)
{
	char	**r;

	r = ft_split(line, ' ');
	if (!check_r(r, c))
	{
		free_tab(r, line, ' ');
		f_error("R", c);
	}
	else
	{
		c->r1 = ft_atoi(r[1]);
		c->r2 = ft_atoi(r[2]);
		free_tab(r, line, ' ');
	}
}

void	ft_get_colors(char **tmp, char **rgb, t_config *c)
{
	int	r;
	int	g;
	int	b;

	r = ft_atoi(rgb[0]);
	g = ft_atoi(rgb[1]);
	b = ft_atoi(rgb[2]);
	if (ft_strcmp(tmp[0], "F") == 0)
		c->f_rgb = (r << 16) + (g << 8) + b;
	if (ft_strcmp(tmp[0], "C") == 0)
		c->c_rgb = (r << 16) + (g << 8) + b;
}

void	ft_split_colors(char *line, t_config *c)
{
	char	**tmp;
	char	**rgb;
	int		i;

	i = 0;
	if ((*line == 'C' && c->c_rgb != -1) || (*line == 'F' && c->f_rgb != -1))
	{
		f_error("twice", c);
		return ;
	}
	tmp = ft_split(line, ' ');
	while (tmp[i])
		i++;
	if (i != 2 || (ft_strcmp(tmp[0], "F") != 0 && ft_strcmp(tmp[0], "C") != 0))
	{
		free_tab(tmp, line, ' ');
		f_error("param", c);
	}
	else
	{
		rgb = ft_split(tmp[1], ',');
		if (!check_colors(rgb))
		{
			free_tab(rgb, line, ',');
			f_error("colors", c);
		}
		else
			ft_get_colors(tmp, rgb, c);
		free_tab(rgb, line, ',');
	}
	free_tab(tmp, line, ' ');
}

void	ft_get_config(char *line, t_config *c)
{
	if (*line)
	{
		while (*line == ' ')
			line++;
		if (!is_in_set(*line, "RSNWEFC"))
			f_error("param", c);
		else
		{
			while (*line)
			{
				if (*line == 'R')
					ft_get_r(line, c);
				if (*line == 'S' || *line == 'N' || \
				*line == 'E' || *line == 'W')
					ft_get_texture(line, c);
				if (*line == 'F' || *line == 'C')
					ft_split_colors(line, c);
				line++;
			}
		}
	}
}

char	*ft_config(int fd, t_config *c)
{
	char		*line;
	int			ret;

	while ((ret = get_next_line(fd, &line)) > 0 && !is_map_1st_line(line))
	{
		ft_get_config(line, c);
		free(line);
	}
	if (!check_config(c) || ret == 0)
	{
		free(line);
		f_error("config", c);
	}
	return (line);
}
