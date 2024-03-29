/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemesle <tlemesle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 15:28:00 by tlemesle          #+#    #+#             */
/*   Updated: 2021/04/09 10:45:27 by tlemesle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int		ft_exit(t_config *c)
{
	if (c->line_bool == 1 && c->line)
		free(c->line);
	play_sound('x');
	ft_free_all(c);
	exit(0);
	return (1);
}

void	f_error(char *s, t_config *c)
{
	if (s)
		ft_putstr("Error\n");
	if (ft_strcmp(s, "fd") == 0)
		ft_putstr("File is invalid or missing.\n");
	if (ft_strcmp(s, "wall") == 0)
		ft_putstr("Problem in game map.(Walls or spaces)\n");
	if (ft_strcmp(s, "player") == 0)
		ft_putstr("Player missing or copies in game map.\n");
	if (ft_strcmp(s, "R") == 0)
		ft_putstr("Resolution is invalid.\n");
	if (ft_strcmp(s, "texture") == 0)
		ft_putstr("Texture parser detected an error.\n");
	if (ft_strcmp(s, "xpm") == 0)
		ft_putstr("Can't open one .xpm file.\n");
	if (ft_strcmp(s, "param") == 0)
		ft_putstr("Too much/few arguments in textures.\n");
	if (ft_strcmp(s, "config") == 0)
		ft_putstr("A config parameter is invalid or missing.\n");
	if (ft_strcmp(s, "colors") == 0)
		ft_putstr("Colors format is invalid.\n");
	if (ft_strcmp(s, "twice") == 0)
		ft_putstr("Repetition of config parameter is forbidden.\n");
	if (ft_strcmp(s, "line_after_map") == 0)
		ft_putstr("Elements detected after map definition.\n");
	ft_exit(c);
}
