/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megiazar <megiazar@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 17:51:31 by megiazar          #+#    #+#             */
/*   Updated: 2025/04/27 18:06:58 by megiazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	unsigned const char	*s;
	size_t				i;

	i = 0;
	if (!dest && !src)
		return (NULL);
	d = (unsigned char *)dest;
	s = (unsigned const char *)src;
	if (d < s)
	{
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	else
	{
		while (n--)
			d[n] = s[n];
	}
	return (d);
}
/*
int	main(void)
{
	char s[] = " meow";
	char d[20] = "bitch";

	printf("before dest = %s src = %s\n", d, s);
	ft_memmove(d, s, 6);
	printf("before dest = %s src = %s\n", d, s);
	return (0);
}*/
/*{
	char	str[] = "ABCDEFGH";

	printf("Before: %s\n", str);
	ft_memmove(str + 3, str, 5);
	printf("After: %s\n", str);
	return (0);
}*/