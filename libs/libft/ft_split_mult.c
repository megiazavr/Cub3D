/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_mult.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ne <ncruz-ne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 22:26:34 by ncruz-ne          #+#    #+#             */
/*   Updated: 2026/05/19 22:27:11 by ncruz-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	wordcounter(char const *str, char *skip)
{
	int	words;
	int	i;

	words = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && ft_strchr(skip, (int)str[i]) != NULL)
			i++;
		if (str[i])
		{
			words++;
			while (str[i] && ft_strchr(skip, (int)str[i]) == NULL)
				i++;
		}
	}
	return (words);
}

static char	*allocncpy(char const *str, int len)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((len + 1) * sizeof(char));
	if (!word)
		return (NULL);
	while (i < len)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

int	freeall(char **splat, size_t j)
{
	if (!splat[j])
	{
		while (j > 0)
		{
			free(splat[j - 1]);
			j--;
		}
		free(splat);
		return (1);
	}
	return (0);
}

static char	**in2damatrix(char const *str, char *skip)
{
	char	**splat;
	size_t	strrows;

	if (!str)
		return (NULL);
	strrows = wordcounter(str, skip);
	splat = malloc((strrows + 1) * sizeof(char *));
	if (!splat)
		return (NULL);
	return (splat);
}

char	**ft_split_mult(char const *str, char *skip)
{
	char	**splat;
	size_t	rowlen;
	size_t	i;
	size_t	row;

	i = 0;
	row = 0;
	splat = in2damatrix(str, skip);
	if (!splat)
		return (NULL);
	while (row < wordcounter(str, skip))
	{
		rowlen = 0;
		while (str[i + rowlen] && ft_strchr(skip, (int)str[i + rowlen]) != NULL)
			i++;
		while (str[i + rowlen] && ft_strchr(skip, (int)str[i + rowlen]) == NULL)
			rowlen++;
		splat[row] = allocncpy(&str[i], rowlen);
		if (freeall(splat, row) == 1)
			return (NULL);
		i += rowlen;
		row++;
	}
	splat[row] = NULL;
	return (splat);
}
