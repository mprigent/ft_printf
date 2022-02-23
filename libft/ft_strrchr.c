/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprigent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 13:39:52 by mprigent          #+#    #+#             */
/*   Updated: 2021/01/15 15:34:05 by mprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *ret;
	char *cs;

	cs = (char *)s;
	ret = NULL;
	while (*cs)
	{
		if (*cs == (char)c)
			ret = cs;
		cs++;
	}
	if (*cs == (char)c)
		ret = cs;
	return (ret);
}
