/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprigent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 15:00:59 by mprigent          #+#    #+#             */
/*   Updated: 2021/01/12 16:26:55 by mprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	char	*scpy;

	if (s != NULL)
	{
		scpy = s;
		while (*scpy != '\0')
		{
			ft_putchar_fd(*scpy, fd);
			scpy++;
		}
	}
}
