/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprigent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 15:22:24 by mprigent          #+#    #+#             */
/*   Updated: 2021/01/13 15:24:44 by mprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	int		i;
	int		j;
	t_list	*temp;

	i = ft_lstsize(*lst);
	while (i)
	{
		ft_lstdelone(ft_lstlast((*lst)), (*del));
		if (i > 1)
		{
			j = i - 1;
			temp = (*lst);
			while (j > 1)
			{
				temp = temp->next;
				j--;
			}
			temp->next = NULL;
		}
		i--;
	}
	*lst = NULL;
}
