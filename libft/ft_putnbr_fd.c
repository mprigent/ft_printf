/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprigent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 16:15:46 by mprigent          #+#    #+#             */
/*   Updated: 2021/01/13 14:22:04 by mprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n / 10 != 0)
	{
		ft_putnbr_fd(n / 10, fd);
		if (n < 0)
			ft_putchar_fd(((unsigned int)-n % 10) + '0', fd);
		else
			ft_putchar_fd((n % 10) + '0', fd);
	}
	else
	{
		if (n < 0)
		{
			ft_putchar_fd('-', fd);
			ft_putchar_fd(-n + '0', fd);
		}
		else
			ft_putchar_fd(n + '0', fd);
	}
}
