/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemesle <tlemesle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 14:31:42 by tlemesle          #+#    #+#             */
/*   Updated: 2020/11/26 12:09:39 by tlemesle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*cpy;

	if (!lst || !del)
		return ;
	cpy = *lst;
	while (cpy)
	{
		tmp = cpy->next;
		ft_lstdelone(cpy, del);
		cpy = tmp;
	}
	*lst = NULL;
}
