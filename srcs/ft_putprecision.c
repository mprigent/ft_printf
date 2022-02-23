/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putprecision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprigent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 12:09:56 by mprigent          #+#    #+#             */
/*   Updated: 2021/03/18 10:48:35 by mprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

int		ft_putprecision(char *str, int precision)
{
	int j;

	j = 0;
	while (str[j] && j < precision)
		ft_putchar(str[j++]);
	return (j);
}
