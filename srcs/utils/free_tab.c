#include "cub3D.h"

int		ft_wordcount(char const *str, char c)
{
	int		i;
	int		cmp;

	cmp = 0;
	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i] && str[i] != c)
			cmp++;
		while (str[i] && str[i] != c)
			i++;
	}
	return (cmp);
}

void	free_tab(char **tab, char const *s, char sep)
{
	int		i;
	int		n;

	n = ft_wordcount(s, sep);
	i = 0;
	while (i < n )
	{
		free(tab[i]);
		i++;
	}
	if (tab)
		free(tab);
	tab = 0;
}

void	ft_free_all(s_map *map, s_config *conf)
{
//	if (map->map)
//		free_tab(map->map, map->line, '*');
//	if (map->line)
//		free(map->line);
	if (conf->no)
		free(conf->no);
	if (conf->so)
		free(conf->so);
	if (conf->s)
		free(conf->s);
	if (conf->we)
		free(conf->we);
	if (conf->ea)
		free(conf->ea);
}