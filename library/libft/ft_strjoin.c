/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ne <ncruz-ne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 20:20:34 by megiazar          #+#    #+#             */
/*   Updated: 2026/05/20 13:35:49 by ncruz-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		index;
	size_t		size;
	char		*str;
	const char	*tmp1;
	const char	*tmp2;

	tmp1 = s1;
	tmp2 = s2;
	if (!s1 || !s2)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc((size + 1) * sizeof(char));
	if (!str)
		return (NULL);
	index = 0;
	while (*tmp1)
		str[index++] = *tmp1++;
	while (*tmp2)
		str[index++] = *tmp2++;
	str[index] = '\0';
	return (str);
}

char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*res;

	res = ft_strjoin(s1, s2);
	free(s1);
	return (res);
}

/*
int	main(void)
{
	char	*str_preffix = "dogs says ";
	char	*str_suffix = "meow meow";

	printf("The result is: %s\n", ft_strjoin(str_preffix, str_suffix));
	return (0);
}*/