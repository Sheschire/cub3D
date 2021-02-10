/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemesle <tlemesle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 15:52:11 by tlemesle          #+#    #+#             */
/*   Updated: 2021/01/08 13:33:53 by tlemesle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_nbrlen(int n)
{
	unsigned int	nbr;
	size_t			len;

	len = 0;
	nbr = n;
	if (n < 0)
	{
		nbr = -n;
		len++;
	}
	while (nbr > 9)
	{
		nbr /= 10;
		len++;
	}
	len++;
	return (len);
}

static char		*ft_convert(char *str, int n, size_t len)
{
	unsigned int	nbr;

	str[len] = '\0';
	nbr = n;
	if (n < 0)
	{
		nbr = -n;
		str[0] = '-';
	}
	len--;
	while (nbr > 9)
	{
		str[len] = nbr % 10 + '0';
		nbr /= 10;
		len--;
	}
	str[len] = nbr + '0';
	return (str);
}

char			*ft_itoa(int n)
{
	char	*str;
	size_t	len;

	len = ft_nbrlen(n);
	str = (char *)malloc(sizeof(char) * len + 1);
	if (str == NULL)
		return (0);
	str = ft_convert(str, n, len);
	return (str);
}
