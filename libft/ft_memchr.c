/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprigent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 15:11:20 by mprigent          #+#    #+#             */
/*   Updated: 2021/01/15 15:31:41 by mprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*cs;

	cs = (unsigned char *)s;
	while (n-- > 0)
	{
		if (*cs == (unsigned char)c)
			return (cs);
		else
			cs++;
	}
	return (NULL);
}
