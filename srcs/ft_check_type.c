/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprigent <mprigent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 18:59:00 by mprigent          #+#    #+#             */
/*   Updated: 2021/03/18 12:44:37 by mprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

int		ft_is_in_type_list(int something)
{
	return ((something == 'c') || (something == 'p') || (something == 'u')
		|| (something == 's') || (something == 'd') || (something == 'i')
		|| (something == 'x') || (something == 'X') || (something == '%'));
}

int		ft_is_in_flags_list(int something)
{
	return ((something == '-') || (something == ' ') || (something == '0')
			|| (something == '.') || (something == '*'));
}

int		ft_check_type(int something, t_flags flags, va_list args)
{
	int j;

	j = 0;
	if (something == 'c')
		j = ft_convert_char(va_arg(args, int), flags);
	else if (something == 's')
		j = ft_convert_str(va_arg(args, char *), flags);
	else if (something == 'u')
		j += ft_convert_u((unsigned int)va_arg(args, unsigned int), flags);
	else if (something == 'd' || something == 'i')
		j = ft_convert_int(va_arg(args, int), flags);
	else if (something == 'x')
		j += ft_convert_xtoa(va_arg(args, unsigned int), 1, flags);
	else if (something == 'X')
		j += ft_convert_xtoa(va_arg(args, unsigned int), 0, flags);
	else if (something == 'p')
		j = ft_convert_ptr(va_arg(args, unsigned long long), flags);
	else if (something == '%')
		j += ft_check_percent(flags);
	return (j);
}
