#include "cub3D.h"

void	ft_get_player(s_config *c, int x, int y)
{
		c->p.pos_count++;
		c->p.x = x;
		c->p.y = y;
		c->p.orient = c->m.map[y][x];
		c->m.map[y][x] = '0';
}

void		add_walls(s_config *c, int y, int x, int len)
{
	int		diff;
	char	*to_join;

	diff = len - x;
	to_join = (char *)malloc(sizeof(char) * diff + 1);
	if (!to_join)
		return ;
	x = 0;
	while (x < diff)
		to_join[x++] = '1';
	to_join[x] = '\0';
	c->m.map[y] = ft_strjoin(c->m.map[y], to_join, 3);
}

void		fill_spaces(s_config *c)
{
	int	len;
	int	y;
	int	x;

	y = 0;
	len = greatest_line_len(c->m.map);
	while (c->m.map[y])
	{
		x = 0;
		while (c->m.map[y][x])
		{
			if (c->m.map[y][x] == ' ' || c->m.map[y][x] == '	')
				c->m.map[y][x] = '1';
			x++;
		}
		if (ft_strlen(c->m.map[y]) < (size_t)len)
			add_walls(c, y, x, len);
		y++;
	}
}

void		get_map(char *line, s_config *c)
{
	char	*tmp;

	tmp = ft_strjoin(line, "*", 1);
	if (c->m.line == NULL)
		c->m.line = ft_strdup(tmp);
	else
		c->m.line = ft_strjoin(c->m.line, tmp, 1);
	free(tmp);
}

void 		ft_check_map(int fd, s_config *c)
{
	char    	*line;
	int			ret;

	line = ft_config(fd, c);
	if (is_map_1st_line(line))
		get_map(line, c);
	while ((ret = get_next_line(fd, &line)) > 0 && !is_map_1st_line(line))
		get_map(line, c);
	get_map(line, c);
	if (!check_empty_line(c->m.line))
		_ERROR("emptyline", c);
	c->m.map = ft_split(c->m.line, '*');
	if (!ft_check_walls(c))
		_ERROR("wall", c);
	fill_spaces(c);
	if (c->p.pos_count != 1)
		_ERROR("player", c);
	if (!c->error)
		ft_exit(c);
	tmp_print_check(c);
}