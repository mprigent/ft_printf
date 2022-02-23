/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprigent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 10:38:35 by mprigent          #+#    #+#             */
/*   Updated: 2021/01/15 15:36:23 by mprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_ischarset(unsigned char c, char const *set)
{
	int i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static	int	find_start(char const *s1, char const *set)
{
	int		start;

	start = 0;
	while (ft_ischarset((unsigned char)s1[start], set) == 1)
		start++;
	return (start);
}

static	int	find_end(char const *s1, char const *set)
{
	int		end;

	end = (int)ft_strlen(s1) - 1;
	while (ft_ischarset((unsigned char)s1[end], set) == 1)
		end--;
	return (end);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		start;
	int		end;
	char	*trim;

	if (s1 == NULL || set == NULL)
		return (NULL);
	start = find_start(s1, set);
	end = find_end(s1, set);
	if (end < start)
	{
		if (!(trim = (char*)malloc(1)))
			return (NULL);
	}
	else
	{
		if (!(trim = (char*)malloc((end - start) + 2)))
			return (NULL);
	}
	i = -1;
	while ((start + ++i) <= end)
		trim[i] = s1[start + i];
	trim[i] = '\0';
	return (trim);
}
