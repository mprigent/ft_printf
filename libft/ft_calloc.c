/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprigent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 17:30:54 by mprigent          #+#    #+#             */
/*   Updated: 2021/01/15 15:34:59 by mprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	char	*ptrzero;

	if (!(ptr = malloc(nmemb * size)))
		return (NULL);
	ptrzero = (char *)ptr;
	ft_bzero(ptrzero, nmemb * size);
	return (ptr);
}
