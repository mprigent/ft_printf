/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprigent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 14:09:11 by mprigent          #+#    #+#             */
/*   Updated: 2021/03/17 15:26:19 by mprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

static int	ft_first_part_str(char *str, t_flags flags)
{
	int		j;

	j = 0;
	if (flags.dot >= 0)
	{
		j += ft_check_width(flags.dot, ft_strlen(str), 0);
		j += ft_putprecision(str, flags.dot);
	}
	else
		j += ft_putprecision(str, ft_strlen(str));
	return (j);
}

int			ft_convert_str(char *str, t_flags flags)
{
	int		j;

	j = 0;
	if (!str)
		str = "(null)";
	if (flags.dot >= 0 && (size_t)flags.dot > ft_strlen(str))
		flags.dot = ft_strlen(str);
	if (flags.minus == 1)
		j += ft_first_part_str(str, flags);
	if (flags.dot >= 0)
		j += ft_check_width(flags.width, flags.dot, 0);
	else
		j += ft_check_width(flags.width, ft_strlen(str), 0);
	if (flags.minus == 0)
		j += ft_first_part_str(str, flags);
	return (j);
}
