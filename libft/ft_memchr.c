/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemesle <tlemesle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 15:49:39 by tlemesle          #+#    #+#             */
/*   Updated: 2020/11/19 16:58:50 by tlemesle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *s2;

	s2 = (unsigned char *)s;
	while (n--)
	{
		if (*s2 == (unsigned char)c)
			return (s2);
		s2++;
	}
	return (0);
}
