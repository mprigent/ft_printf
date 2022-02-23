/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprigent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 18:21:19 by mprigent          #+#    #+#             */
/*   Updated: 2021/01/15 15:33:34 by mprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char *cs;

	cs = (char *)s;
	if (*cs == (char)c)
		return (cs);
	while (*cs++)
	{
		if (*cs == (char)c)
			return (cs);
	}
	if ((char)c == '\0')
		return (cs);
	return (NULL);
}
