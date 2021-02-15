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