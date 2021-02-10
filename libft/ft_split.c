/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemesle <tlemesle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 12:10:16 by tlemesle          #+#    #+#             */
/*   Updated: 2020/11/25 14:48:27 by tlemesle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_wordlen(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] != c && s[len] != '\0')
		len++;
	return (len);
}

static int		ft_wordcount(char const *s, char c)
{
	int		nb_word;
	int		i;

	i = 0;
	nb_word = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i])
			nb_word++;
		while (s[i] != c && s[i])
			i++;
	}
	return (nb_word);
}

static char		**ft_free(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
	return (NULL);
}

char			**ft_split(char const *s, char c)
{
	char	**tab;
	int		nb_word;
	size_t	wordlen;
	int		j;

	if (!s)
		return (0);
	nb_word = ft_wordcount(s, c);
	tab = (char **)malloc(sizeof(char *) * (nb_word + 1));
	if (tab == NULL)
		return (0);
	j = 0;
	while (nb_word--)
	{
		while (*s == c && *s)
			s++;
		wordlen = ft_wordlen(s, c);
		if (!(tab[j] = (char*)malloc(sizeof(char) * wordlen + 1)))
			return (ft_free(tab));
		ft_strlcpy(tab[j], s, wordlen + 1);
		j++;
		s += wordlen;
	}
	tab[j] = NULL;
	return (tab);
}
