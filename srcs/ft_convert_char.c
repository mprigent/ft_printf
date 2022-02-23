/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprigent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 12:58:41 by mprigent          #+#    #+#             */
/*   Updated: 2021/03/17 11:59:50 by mprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

int	ft_convert_char(char c, t_flags flags)
{
	int j;

	j = 0;
	if (flags.minus == 1)
		ft_putchar(c);
	j = ft_check_width(flags.width, 1, 0);
	if (flags.minus == 0)
		ft_putchar(c);
	return (j + 1);
}
