/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemesle <tlemesle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 11:40:06 by tlemesle          #+#    #+#             */
/*   Updated: 2021/02/12 11:05:43 by tlemesle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	ft_line(int fd, char **line, char *save[fd], char *str)
{
	char	*tmp;

	if (str)
	{
		*line = ft_substr(*save, 0, str - *save);
		tmp = ft_substr(str + 1, 0, ft_strlen(str + 1));
		free(*save);
		*save = tmp;
		return (1);
	}
	if (*save)
	{
		*line = *save;
		*save = NULL;
	}
	else
		*line = ft_strdup("");
	return (0);
}

int			get_next_line(int fd, char **line)
{
	static char	*save[256];
	int			n_read;
	static char	buf[20 + 1];
	char		*tmp;
	char		*str;

	n_read = 1;
	if (fd < 0 || !line || 20 <= 0)
		return (-1);
	while ((str = ft_strchr(save[fd], '\n')) == 0 && \
	((n_read = read(fd, buf, 20)) > 0))
	{
		buf[n_read] = '\0';
		if (save[fd] == NULL)
			tmp = ft_substr(buf, 0, 20);
		else
			tmp = ft_strjoin(save[fd], buf, 0);
		if (save[fd])
			free(save[fd]);
		save[fd] = tmp;
	}
	if (n_read < 0)
		return (-1);
	return (ft_line(fd, line, &save[fd], str));
}
