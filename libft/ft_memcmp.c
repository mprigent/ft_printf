/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprigent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 15:48:23 by mprigent          #+#    #+#             */
/*   Updated: 2021/01/15 15:32:03 by mprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char		*mem1;
	unsigned char		*mem2;

	mem1 = (unsigned char *)s1;
	mem2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	n = n - 1;
	while ((n--) && (*mem1 == *mem2))
	{
		mem1++;
		mem2++;
	}
	return (*mem1 - *mem2);
}
