/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprigent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 14:35:01 by mprigent          #+#    #+#             */
/*   Updated: 2021/01/15 15:31:10 by mprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char	*dest;
	char	*source;

	if (dst == NULL && src == NULL)
		return (NULL);
	if (dst > src)
	{
		dest = (char *)(dst + n - 1);
		source = (char *)(src + n - 1);
		while (n-- > 0)
			*dest-- = *source--;
	}
	else
	{
		dest = (char *)dst;
		source = (char *)src;
		while (n-- > 0)
			*dest++ = *source++;
	}
	return (dst);
}
