/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprigent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 13:44:24 by mprigent          #+#    #+#             */
/*   Updated: 2021/01/15 15:34:33 by mprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned	char *str1;
	unsigned	char *str2;

	str1 = (unsigned	char *)s1;
	str2 = (unsigned	char *)s2;
	if (n == 0)
		return (0);
	n = n - 1;
	while ((*str1 == *str2) && (n-- > 0) && *str1 && *str2)
	{
		str1++;
		str2++;
	}
	return (*str1 - *str2);
}
