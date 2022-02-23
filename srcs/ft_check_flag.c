/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprigent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 11:22:26 by mprigent          #+#    #+#             */
/*   Updated: 2021/03/17 14:46:41 by mprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

t_flags		ft_flag_minus(t_flags flags)
{
	flags.minus = 1;
	flags.zero = 0;
	return (flags);
}

t_flags		ft_flag_width(va_list args, t_flags flags)
{
	flags.star = 0;
	flags.width = va_arg(args, int);
	if (flags.width < 0)
	{
		flags.minus = 1;
		flags.width *= -1;
		flags.zero = 0;
	}
	return (flags);
}

t_flags		ft_flag_digit(char c, t_flags flags)
{
	if (flags.star == 1)
		flags.width = 0;
	flags.width = (flags.width * 10) + (c - '0');
	return (flags);
}

int			ft_flag_dot(const char *save,
			int start, t_flags *flags, va_list args)
{
	int		j;

	j = start;
	j++;
	if (save[j] == '*')
	{
		flags->dot = va_arg(args, int);
		j++;
	}
	else
	{
		flags->dot = 0;
		while (ft_isdigit(save[j]))
			flags->dot = (flags->dot * 10) + (save[j++] - '0');
	}
	return (j);
}
