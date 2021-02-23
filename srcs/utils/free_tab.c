/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemesle <tlemesle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 15:30:32 by tlemesle          #+#    #+#             */
/*   Updated: 2021/02/23 15:30:51 by tlemesle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	while (i < n)
	{
		if (tab[i])
			free(tab[i]);
		i++;
	}
	if (tab)
		free(tab);
	tab = 0;
}

void	ft_free(char *tmp)
{
	if (tmp)
	{
		free(tmp);
		tmp = NULL;
	}
}

void	ft_free_all(t_config *c)
{
	if (c->m.map)
		free_tab(c->m.map, c->m.line, '*');
	free(c->m.line);
	ft_free(c->no);
	ft_free(c->so);
	ft_free(c->s);
	ft_free(c->we);
	ft_free(c->ea);
}
