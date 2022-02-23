/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_u.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprigent <mprigent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 18:39:20 by mprigent          #+#    #+#             */
/*   Updated: 2021/03/17 11:07:28 by mprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

static int	ft_first_part_u(char *uns_int, t_flags flags)
{
	int j;

	j = 0;
	if (flags.dot >= 0)
		j += ft_check_width(flags.dot - 1, ft_strlen(uns_int) - 1, 1);
	j += ft_putprecision(uns_int, ft_strlen(uns_int));
	return (j);
}

static int	ft_second_part_u(char *uns_int, t_flags flags)
{
	int j;

	j = 0;
	if (flags.minus == 1)
		j += ft_first_part_u(uns_int, flags);
	if (flags.dot >= 0 && (size_t)flags.dot < ft_strlen(uns_int))
		flags.dot = ft_strlen(uns_int);
	if (flags.dot >= 0)
	{
		flags.width -= flags.dot;
		j += ft_check_width(flags.width, 0, 0);
	}
	else
		j += ft_check_width(flags.width, ft_strlen(uns_int), flags.zero);
	if (flags.minus == 0)
		j += ft_first_part_u(uns_int, flags);
	return (j);
}

int			ft_convert_u(unsigned int uns, t_flags flags)
{
	char	*uns_int;
	int		j;

	j = 0;
	uns = (unsigned int)(4294967295 + 1 + uns);
	if (flags.dot == 0 && uns == 0)
	{
		j += ft_check_width(flags.width, 0, 0);
		return (j);
	}
	uns_int = ft_utoa(uns);
	j += ft_second_part_u(uns_int, flags);
	free(uns_int);
	return (j);
}
