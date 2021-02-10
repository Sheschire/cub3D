/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemesle <tlemesle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 08:57:21 by tlemesle          #+#    #+#             */
/*   Updated: 2020/11/19 17:00:30 by tlemesle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const unsigned char		*src2;
	unsigned char			*dest2;

	src2 = (const unsigned char *)src;
	dest2 = (unsigned char *)dest;
	if (src2 < dest2)
	{
		while (n--)
			dest2[n] = src2[n];
	}
	else
	{
		ft_memcpy(dest2, src2, n);
	}
	return (dest);
}
