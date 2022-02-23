/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_ptr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprigent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 14:08:39 by mprigent          #+#    #+#             */
/*   Updated: 2021/03/17 10:56:11 by mprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

static int	ft_first_part_ptr(char *ptr, t_flags flags)
{
	int j;

	j = 0;
	j += ft_putprecision("0x", 2);
	if (flags.dot >= 0)
	{
		j += ft_check_width(flags.dot, ft_strlen(ptr), 1);
		j += ft_putprecision(ptr, flags.dot);
	}
	else
		j += ft_putprecision(ptr, ft_strlen(ptr));
	return (j);
}

int			ft_convert_ptr(unsigned long long base, t_flags flags)
{
	char	*ptr;
	int		j;

	j = 0;
	if (base == 0 && flags.dot == 0)
	{
		j += ft_putprecision("0x", 2);
		return (j += ft_check_width(flags.width, 0, 1));
	}
	ptr = ft_convert_base(base, 16);
	ptr = ft_strtolower(ptr);
	if ((size_t)flags.dot < ft_strlen(ptr))
		flags.dot = ft_strlen(ptr);
	if (flags.minus == 1)
		j += ft_first_part_ptr(ptr, flags);
	j += ft_check_width(flags.width, ft_strlen(ptr) + 2, 0);
	if (flags.minus == 0)
		j += ft_first_part_ptr(ptr, flags);
	free(ptr);
	return (j);
}
