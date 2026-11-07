/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megiazar <megiazar@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 14:10:48 by megiazar          #+#    #+#             */
/*   Updated: 2025/05/01 12:02:54 by megiazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_words(const char *str, char c)
{
	int	i;
	int	k;

	k = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			i++;
		else
		{
			k++;
			while (str[i] && str[i] != c)
				i++;
		}
	}
	return (k);
}

static char	*ft_wd(const char **s, char c)
{
	int			i;
	char		*wd;
	const char	*str;

	i = 0;
	str = *s;
	while (*str && *str == c)
		str++;
	while (str[i] && str[i] != c)
		i++;
	wd = malloc(sizeof(char) * (i + 1));
	if (!wd)
		return (NULL);
	i = 0;
	while (*str && *str != c)
	{
		wd[i++] = *str++;
	}
	wd[i] = '\0';
	*s = str;
	return (wd);
}

static void	free_words(int i, char **ptr)
{
	while (i > 0)
	{
		free(ptr[i - 1]);
		i--;
	}
	free(ptr);
}

static char	**ft_split_half(const char *s, char c, char **ptr_words, int words)
{
	int	i;

	i = 0;
	while (i < words)
	{
		while (*s && *s == c)
			s++;
		ptr_words[i] = ft_wd(&s, c);
		if (!ptr_words[i])
		{
			free_words(i, ptr_words);
			return (NULL);
		}
		i++;
	}
	ptr_words[i] = NULL;
	return (ptr_words);
}

char	**ft_split(const char *s, char c)
{
	char	**ptr_words;
	int		words;

	if (!s)
		return (NULL);
	words = ft_words(s, c);
	if (ft_strlen(s) == 0 || words == 0)
	{
		ptr_words = malloc(sizeof(char *) * 1);
		if (ptr_words == NULL)
			return (NULL);
		ptr_words[0] = NULL;
		return (ptr_words);
	}
	ptr_words = malloc(sizeof(char *) * (words + 1));
	if (ptr_words == NULL)
		return (NULL);
	return (ft_split_half(s, c, ptr_words, words));
}
/*int	main(void)
{
	//printf("num of words %d\n", ft_words("", ' '));
	
	//free(split[0]);
	//printf("%s", split[1]);

	//char	*str = "      split       this for   me  !       ";
	//char 	c = ' ';
	//char	**split = ft_split(str, c);
	//int		i = 0;

	const char	*str = "loren blah blah , blah. Blah";
	char		c = ' ';
	char		**split = ft_split(str, c);
	int			i = 0;
	if (!split)
	{
		printf("Split failed.\n");
		return (1);
	}
	while (split[i])
	{s + i
		printf("Split[%d]: %s\n", i, split[i]);
		free(split[i]);
		i++;
	}
	free(split);
	return (0);
	char *s = "";
 
	char **result = ft_split(s, ' ');
	if (!result)
		printf("Split work");
	else
		printf("Split failed.\n");
}*/