/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprigent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 15:12:59 by mprigent          #+#    #+#             */
/*   Updated: 2021/01/13 15:19:38 by mprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*cpy;

	if ((*alst) == NULL)
	{
		(*alst) = new;
		new->next = NULL;
	}
	else
	{
		cpy = *alst;
		while ((*alst)->next != NULL)
			(*alst) = (*alst)->next;
		new->next = NULL;
		(*alst)->next = new;
		*alst = cpy;
	}
}
