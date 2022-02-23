/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprigent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 15:26:22 by mprigent          #+#    #+#             */
/*   Updated: 2021/01/13 15:27:21 by mprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ret;
	t_list	*map;

	if (lst == NULL)
		return (NULL);
	map = ft_lstnew((*f)(lst->content));
	if (map == NULL)
		return (NULL);
	ret = map;
	while (lst->next != NULL)
	{
		map->next = ft_lstnew((*f)(lst->next->content));
		if (map->next == NULL)
		{
			ft_lstclear(&ret, (*del));
			return (NULL);
		}
		lst = lst->next;
		map = map->next;
	}
	return (ret);
}
