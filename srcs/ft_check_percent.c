/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_percent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprigent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 11:54:00 by mprigent          #+#    #+#             */
/*   Updated: 2021/03/17 14:17:51 by mprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

int	ft_check_percent(t_flags flags)
{
	int j;

	j = 0;
	if (flags.minus == 1)
		j += ft_putprecision("%", 1);
	j += ft_check_width(flags.width, 1, flags.zero);
	if (flags.minus == 0)
		j += ft_putprecision("%", 1);
	return (j);
}
