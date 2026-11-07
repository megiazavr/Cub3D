/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megiazar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 14:47:07 by megiazar          #+#    #+#             */
/*   Updated: 2025/04/14 16:08:51 by megiazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*str;
	size_t				i;

	i = 0;
	str = (const unsigned char *)s;
	while (i < n)
	{
		if (str[i] == (unsigned char)c)
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}
/*
int	main(void)
{
	const char	s1[] = "djfhiuhfshfvuhv";
	const char	*result;

	result = ft_memchr(s1, 'w', 5);
	if (result != NULL)
		printf("%c found at the position %ld\n", *result, result - s1);
	else
		printf("'%c' NOT found, go cry ab it\n", 'w');
	return (0);
}*/
