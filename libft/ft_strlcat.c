/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprigent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 16:12:09 by mprigent          #+#    #+#             */
/*   Updated: 2021/01/11 15:02:28 by mprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char	*dest;
	char	*source;
	size_t	copy;
	size_t	save;

	dest = dst;
	source = (char *)src;
	copy = size;
	save = ft_strlen(dst);
	while (copy-- > 0 && *dest != '\0')
		dest++;
	copy = size - (dest - dst);
	if (copy == 0)
		return ((dest - dst) + ft_strlen(src));
	while (*source != '\0')
	{
		if (copy != 1)
		{
			*dest++ = *source;
			copy--;
		}
		source++;
	}
	*dest = '\0';
	return (save + ft_strlen(src));
}
