/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megiazar <megiazar@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 15:29:07 by megiazar          #+#    #+#             */
/*   Updated: 2025/05/01 16:10:54 by megiazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	str;
	int				i;

	str = (unsigned char)c;
	i = 0;
	while (s[i] != '\0')
	{
		if ((unsigned char)s[i] == str)
			return ((char *)s + i);
		i++;
	}
	if (str == '\0')
	{
		return ((char *)s + i);
	}
	return (NULL);
}
/*
int	main(void)
{
	char	s1[] = "meow";
	char	*result;

	result = ft_strchr(s1, 'r');
	if (result != NULL)
	{
		printf("Str starting from %c is: %s\n", 'r', result);
	}
	else
	{
		printf("Char %c NOT FOUND, go cry about it\ni", 'r');
	}
	return (0);
}*/
