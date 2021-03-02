/*
void	add_walls(t_config *c, int y, int x, int len)
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

void	fill_spaces(t_config *c)
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
			if (c->m.map[y][x] == ' ')
				c->m.map[y][x] = '1';
			x++;
		}
		if (ft_strlen(c->m.map[y]) < (size_t)len)
			add_walls(c, y, x, len);
		y++;
	}
}*/

/*
int		greatest_line_len(char **map)
{
	int	y;
	int	x;
	int	len;

	y = 0;
	len = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
			x++;
		if (x > len)
			len = x;
		y++;
	}
	return (len);
}*/