/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemesle <tlemesle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 09:00:14 by tlemesle          #+#    #+#             */
/*   Updated: 2020/11/23 11:54:03 by tlemesle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*s1;
	int		i;

	s1 = (char *)s;
	i = 0;
	while (s1[i])
		i++;
	while (s1[i] != s1[0])
	{
		if (s1[i] == c)
		{
			s1 += i;
			return (s1);
		}
		i--;
	}
	if (s1[0] == c)
		return (s1);
	return (0);
}
