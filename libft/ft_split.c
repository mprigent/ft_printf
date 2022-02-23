/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mprigent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 15:49:12 by mprigent          #+#    #+#             */
/*   Updated: 2021/01/15 15:36:55 by mprigent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_words(int n, char **words)
{
	int i;

	i = 0;
	while (i < n)
	{
		free(words[i]);
		i++;
	}
	free(words);
}

static int	count_words(const char *str, char sep)
{
	int i;
	int count;
	int j;

	i = 0;
	count = 0;
	j = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] != sep)
		{
			if (!j)
				count++;
			j = 1;
		}
		else
			j = 0;
		i++;
	}
	return (count);
}

static int	new_word_pos(const char *str, int n, char sep)
{
	int i;
	int count;
	int j;

	i = 0;
	count = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] != sep)
		{
			if (!j)
			{
				count++;
				if (count == n + 1)
					break ;
			}
			j = 1;
		}
		else
			j = 0;
		i++;
	}
	return (i);
}

static char	*n_word(const char *str, int n, char sep, char **words)
{
	int		i;
	int		j;
	int		y;
	char	*word;

	i = new_word_pos(str, n, sep);
	y = i;
	if (!str)
		return (NULL);
	while (str[y] && str[y] != sep)
		y++;
	if (!(word = (char *)malloc((y - i + 1) * sizeof(char))))
	{
		free_words(n, words);
		return (0);
	}
	j = 0;
	while (str[i] && str[i] != sep)
	{
		word[j] = str[i];
		i++;
		j++;
	}
	word[j] = 0;
	return (word);
}

char		**ft_split(char const *s, char c)
{
	char	**words;
	int		count;
	int		i;

	count = count_words(s, c);
	if (!(words = (char **)malloc((count + 1) * sizeof(char *))))
		return (0);
	words[count] = NULL;
	i = 0;
	while (i < count)
	{
		words[i] = n_word(s, i, c, words);
		i++;
	}
	return (words);
}
