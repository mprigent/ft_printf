/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprigent <mprigent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 19:16:16 by mprigent          #+#    #+#             */
/*   Updated: 2021/03/17 14:18:36 by mprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

static char	*check_base(unsigned long long save, int base, char *ptr, int i)
{
	while (save != 0)
	{
		if ((save % base) < 10)
			ptr[i - 1] = (save % base) + 48;
		else
			ptr[i - 1] = (save % base) + 55;
		save /= base;
		i--;
	}
	return (ptr);
}

char		*ft_convert_base(unsigned long long n, int base)
{
	char				*ptr;
	unsigned long long	save;
	int					i;

	ptr = 0;
	i = 0;
	save = n;
	if (n == 0)
		return (ft_strdup("0"));
	while (n != 0)
	{
		n /= base;
		i++;
	}
	if (!(ptr = malloc(sizeof(char) * (i + 1))))
		return (0);
	ptr[i] = '\0';
	ptr = check_base(save, base, ptr, i);
	return (ptr);
}
