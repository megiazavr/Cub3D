/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megiazar <megiazar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 18:07:23 by megiazar          #+#    #+#             */
/*   Updated: 2025/04/23 19:40:52 by megiazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	sub = malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	i = 0;
	while (i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
/*
int	main(void)
{
	char	*s1 = "Dog burk meow meow";
	char	*s2;
	s2 = ft_substr(s1, 9, 10);
	printf("The string is %s\n", s1);
	printf("Substring is %s\n", s2);
	free (s2);
	s2 = ft_substr(s1, 9, 20);
	printf("Substr %s\n", s2);
	s2 = ft_substr(s1, 18, 5);
	printf("Substr %s\n", s2);
	return (0);
}*/