/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megiazar <megiazar@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 16:18:39 by megiazar          #+#    #+#             */
/*   Updated: 2025/04/23 17:27:53 by megiazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;

	i = 0;
	while (s[i])
		i++;
	while (i >= 0)
	{
		if ((unsigned char)s[i] == (unsigned char)c)
			return ((char *)s + i);
		i--;
	}
	return (NULL);
}
/*
int	main(void)
{
	char	s1[] = "meowwoo2o34w";
	char	*result;

	result = ft_strrchr(s1, 'o');
	if (result != NULL)
	{
		printf("Str starting from %c is: %s\n", 'o', result);
	}
	else
	{
		printf("Char %c NOT FOUND, go cry about it\n", 'o');
	}
	return (0);
}*/