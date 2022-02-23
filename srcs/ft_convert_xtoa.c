/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_xtoa.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprigent <mprigent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 18:03:22 by mprigent          #+#    #+#             */
/*   Updated: 2021/03/17 12:05:34 by mprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

static int	ft_first_part_hexa(char *hexa, t_flags flags)
{
	int j;

	j = 0;
	if (flags.dot >= 0)
		j += ft_check_width(flags.dot - 1, ft_strlen(hexa) - 1, 1);
	j += ft_putprecision(hexa, ft_strlen(hexa));
	return (j);
}

static int	ft_second_part_hexa(char *hexa, t_flags flags)
{
	int j;

	j = 0;
	if (flags.minus == 1)
		j += ft_first_part_hexa(hexa, flags);
	if (flags.dot >= 0 && (size_t)flags.dot < ft_strlen(hexa))
		flags.dot = ft_strlen(hexa);
	if (flags.dot >= 0)
	{
		flags.width -= flags.dot;
		j += ft_check_width(flags.width, 0, 0);
	}
	else
		j += ft_check_width(flags.width, ft_strlen(hexa), flags.zero);
	if (flags.minus == 0)
		j += ft_first_part_hexa(hexa, flags);
	return (j);
}

int			ft_convert_xtoa(unsigned int i, int min, t_flags flags)
{
	char	*hexa;
	int		j;

	j = 0;
	i = (unsigned int)(4294967295 + 1 + i);
	if (flags.dot == 0 && i == 0)
	{
		j += ft_check_width(flags.width, 0, 0);
		return (j);
	}
	hexa = ft_convert_base((unsigned long long)i, 16);
	if (min == 1)
		hexa = ft_strtolower(hexa);
	j += ft_second_part_hexa(hexa, flags);
	free(hexa);
	return (j);
}
