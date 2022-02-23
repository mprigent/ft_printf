/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprigent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 15:50:35 by mprigent          #+#    #+#             */
/*   Updated: 2021/01/12 16:10:53 by mprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*scpy;
	char			*new;
	unsigned int	i;

	i = 0;
	if (s == NULL || (f) == NULL)
		return (NULL);
	if (!(new = malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (NULL);
	scpy = (char *)s;
	while (*scpy != '\0')
	{
		new[i] = (*f)(i, *scpy);
		i++;
		scpy++;
	}
	new[i] = '\0';
	return (new);
}
