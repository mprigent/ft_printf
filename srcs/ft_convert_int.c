/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprigent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 13:02:10 by mprigent          #+#    #+#             */
/*   Updated: 2021/03/18 12:51:52 by mprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

static int	ft_convert_int_2(t_flags flags, char *itoa, int is_neg)
{
	int j;

	j = 0;
	while (flags.width > flags.dot + is_neg && !flags.zero)
	{
		j += write(1, " ", 1);
		flags.width--;
	}
	if (is_neg)
		j += write(1, "-", 1);
	while (flags.width > flags.dot + is_neg && flags.zero)
	{
		j += write(1, "0", 1);
		flags.width--;
	}
	while (flags.dot > (int)ft_strlen(itoa))
	{
		j += write(1, "0", 1);
		flags.dot--;
	}
	j += write(1, itoa, ft_strlen(itoa));
	return (j);
}

static int	ft_convert_int_3(t_flags flags, char *itoa, int is_neg, int save)
{
	int j;

	j = 0;
	if (is_neg)
		j += write(1, "-", 1);
	while (flags.dot > (int)ft_strlen(itoa))
	{
		j += write(1, "0", 1);
		flags.dot--;
	}
	j += write(1, itoa, ft_strlen(itoa));
	while (flags.width > save + is_neg)
	{
		j += write(1, " ", 1);
		flags.width--;
	}
	return (j);
}

int			ft_convert_int(long int i, t_flags flags)
{
	char	*itoa;
	int		is_neg;
	int		j;
	int		save;

	if (flags.dot == 0 && i == 0)
	{
		j = ft_check_width(flags.width, 0, 0);
		return (j);
	}
	is_neg = (i < 0) ? 1 : 0;
	i = (i < 0) ? -i : i;
	itoa = ft_itoa(i);
	if (flags.dot >= 0)
		flags.zero = 0;
	flags.dot = ((int)ft_strlen(itoa) > flags.dot)
		? ft_strlen(itoa) : flags.dot;
	save = flags.dot;
	j = 0;
	if (!flags.minus)
		j += ft_convert_int_2(flags, itoa, is_neg);
	else
		j += ft_convert_int_3(flags, itoa, is_neg, save);
	free(itoa);
	return (j);
}
