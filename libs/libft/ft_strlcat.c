/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megiazar <megiazar@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 15:02:56 by megiazar          #+#    #+#             */
/*   Updated: 2025/04/29 16:34:24 by megiazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	dest_len;
	size_t	src_len;

	j = 0;
	dest_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	i = dest_len;
	if (size <= dest_len)
		return (size + src_len);
	while (src[j] && i < size - 1)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (dest_len + src_len);
}

/* int	main(int ac, char *av[])
{
	char *dest = av[1];
	if (ac == 4)
	{
		printf("%s\n", av[1]);
		printf("%zu\n", ft_strlcat(dest, av[2], atoi(av[3])));
		printf("%s\n", av[1]);
	}
	return (0);
} */
/* int main(void) {
    char    src[] = "meow meow";
    char    dst[27];

    printf("Before concatenate: %s\n", dst);
    ft_strlcat(dst, src, sizeof(dst));
    printf("After concatenation: %s\n", dst);
	return (0);
} */