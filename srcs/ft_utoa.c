/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprigent <mprigent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 18:53:49 by mprigent          #+#    #+#             */
/*   Updated: 2021/03/17 11:32:18 by mprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

static int	ft_first_part_utoa(long n)
{
	size_t	j;
	int		neg;

	j = 0;
	neg = 0;
	if (n < 0)
	{
		j++;
		neg++;
		n = -n;
	}
	while (n >= 1)
	{
		j++;
		n /= 10;
	}
	return (j);
}

static char	*ft_second_part_utoa(char *ptr, long nb, int len, int neg)
{
	if (nb != 0)
		ptr = malloc(sizeof(char) * (len + 1));
	else
		return (ptr = ft_strdup("0"));
	if (!ptr)
		return (0);
	neg = 0;
	if (nb < 0)
	{
		neg++;
		nb = -nb;
	}
	ptr[len] = '\0';
	while (--len)
	{
		ptr[len] = (nb % 10) + '0';
		nb /= 10;
	}
	if (neg == 1)
		ptr[0] = '-';
	else
		ptr[0] = (nb % 10) + '0';
	return (ptr);
}

char		*ft_utoa(unsigned int n)
{
	int		len;
	char	*ptr;
	long	nb;
	int		neg;

	nb = n;
	len = ft_first_part_utoa(nb);
	ptr = 0;
	neg = 0;
	if (!(ptr = ft_second_part_utoa(ptr, nb, len, neg)))
		return (0);
	return (ptr);
}
