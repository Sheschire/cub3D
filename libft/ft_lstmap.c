/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlemesle <tlemesle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 18:26:48 by tlemesle          #+#    #+#             */
/*   Updated: 2020/11/25 14:12:19 by tlemesle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*aflst;
	t_list	*tmp;

	if (!lst || !f)
		return (0);
	aflst = NULL;
	while (lst)
	{
		tmp = ft_lstnew(f(lst->content));
		if (tmp == NULL)
		{
			ft_lstclear(&aflst, del);
			return (0);
		}
		ft_lstadd_back(&aflst, tmp);
		tmp = tmp->next;
		lst = lst->next;
	}
	return (aflst);
}
