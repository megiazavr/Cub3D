/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megiazar <megiazar@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 18:31:21 by megiazar          #+#    #+#             */
/*   Updated: 2025/04/29 16:20:19 by megiazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	len;

	len = 0;
	if (size)
	{
		while (*(src + len) && --size)
			*dst++ = *(src + len++);
		*dst = '\0';
	}
	else
	{
		while (src[len])
			len++;
		return (len);
	}
	while (*(src + len))
		++len;
	return (len);
}

/*
int	main(void)
{
	char	src[] = "meow meow";
	char	dst[15];
	size_t	len;

	len = ft_strlcpy(dst, src, sizeof(dst));
	printf("String to copy: %s\n", dst);
	printf("Lenght of src: %zu\n", len);
	return (0);
}*/