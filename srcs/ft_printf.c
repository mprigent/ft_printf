/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprigent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 14:07:39 by mprigent          #+#    #+#             */
/*   Updated: 2021/03/18 11:12:56 by mprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"
#include <stdarg.h>

t_flags		ft_init_flags(void)
{
	t_flags	flags;

	flags.type = 0;
	flags.minus = 0;
	flags.zero = 0;
	flags.dot = -1;
	flags.width = 0;
	flags.star = 0;
	return (flags);
}

int			ft_parsing(const char *save, int i, t_flags *flags, va_list args)
{
	while (save[i])
	{
		if (!ft_isdigit(save[i]) && !ft_is_in_type_list(save[i])
		&& !ft_is_in_flags_list(save[i]))
			break ;
		if (save[i] == '0' && flags->width == 0 && flags->minus == 0)
			flags->zero = 1;
		if (save[i] == '.')
			i = ft_flag_dot(save, i, flags, args);
		if (save[i] == '-')
			*flags = ft_flag_minus(*flags);
		if (save[i] == '*')
			*flags = ft_flag_width(args, *flags);
		if (ft_isdigit(save[i]))
			*flags = ft_flag_digit(save[i], *flags);
		if (ft_is_in_type_list(save[i]))
		{
			flags->type = save[i];
			break ;
		}
		i++;
	}
	return (i);
}

int			ft_save(const char *save, va_list args)
{
	int		i;
	t_flags	flags;
	int		j;

	i = 0;
	j = 0;
	while (save[i])
	{
		flags = ft_init_flags();
		if (save[i] == '%' && save[i + 1])
		{
			i = ft_parsing(save, ++i, &flags, args);
			if (ft_is_in_type_list(save[i]))
				j += ft_check_type((char)flags.type, flags, args);
			else if (save[i])
				j += ft_putchar(save[i]);
		}
		else if (save[i] != '%')
			j += ft_putchar(save[i]);
		i++;
	}
	return (j);
}

int			ft_printf(const char *something, ...)
{
	va_list		args;
	int			j;

	j = 0;
	va_start(args, something);
	j += ft_save(something, args);
	va_end(args);
	return (j);
}
