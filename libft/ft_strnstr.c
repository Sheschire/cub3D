/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemesle <tlemesle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 09:00:05 by tlemesle          #+#    #+#             */
/*   Updated: 2020/11/20 14:12:16 by tlemesle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	char	*str1;
	size_t	i;
	int		j;

	str1 = (char *)s1;
	i = 0;
	if (!*s2)
		return (str1);
	while (str1[i] && i < len)
	{
		j = 0;
		if (str1[i] == s2[j])
		{
			while (i + j < len && str1[i + j] == s2[j])
			{
				j++;
				if (!s2[j])
					return (str1 + i);
			}
		}
		i++;
	}
	return (0);
}
