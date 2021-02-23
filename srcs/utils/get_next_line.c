/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemesle <tlemesle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 15:31:13 by tlemesle          #+#    #+#             */
/*   Updated: 2021/02/23 15:31:51 by tlemesle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_concat(char *s1, char *s2, int len)
{
	char		*s3;
	int			i;
	int			j;
	int			size_s1;

	i = 0;
	size_s1 = 0;
	while ((j = -1) && s1 && s1[size_s1])
		size_s1++;
	if (!(s3 = malloc(sizeof(char) * (len + size_s1 + 1))))
		return (0);
	while (s1 && s1[i])
	{
		s3[i] = s1[i];
		i++;
	}
	while (s2 && ++j < len)
	{
		s3[i] = s2[j];
		i++;
	}
	if (s1)
		free(s1);
	s3[i] = '\0';
	return (s3);
}

int		check_n(char *p)
{
	int			i;

	i = 0;
	while (p[i] && p[i] != '\n')
		i++;
	return (i);
}

int		handling_return(int r, char *buf, char **line, char *p)
{
	if (r > 0)
	{
		buf[r] = '\0';
		if (!(*line = ft_concat(p, buf, check_n(buf))))
			return (-1);
		return (r);
	}
	else if (r == 0)
	{
		if (!*line)
			if (!(*line = ft_concat(0, 0, 0)))
				return (-1);
		return (0);
	}
	*line = ft_concat(0, 0, 0);
	return (-1);
}

int		get_next_line(int fd, char **line)
{
	static char	buf[BUFFER_SIZE + 1];
	static int	i = 0;
	int			r;
	char		*p;

	if (!line)
		return (-1);
	p = 0;
	*line = 0;
	while (BUFFER_SIZE > 0)
	{
		if (i && !(*line = ft_concat(p, buf + i, check_n(buf + i))))
			return (-1);
		else if (!i && (r = read(fd, buf, BUFFER_SIZE)) >= -1)
			if ((handling_return(r, buf, line, p)) <= 0)
				return (r);
		p = *line;
		i += check_n(buf + i) + 1;
		if (!buf[i - 1])
			i = 0;
		if (buf[i - 1] == '\n')
			return (1);
	}
	return (-1);
}
