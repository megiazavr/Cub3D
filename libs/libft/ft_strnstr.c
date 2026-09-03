/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megiazar <megiazar@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 17:06:15 by megiazar          #+#    #+#             */
/*   Updated: 2025/05/01 15:42:50 by megiazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (big == NULL && !little)
		return (NULL);
	if (little[0] == '\0')
		return ((char *)big);
	if (len > ft_strlen(big))
		len = ft_strlen(big);
	while (big[i] != '\0' && i < len)
	{
		j = 0;
		while (big[i + j] == little[j] && (i + j) < len)
		{
			j++;
		}
		if (little[j] == '\0')
			return ((char *)&big[i]);
		i++;
	}
	if (i == len && big == little)
		return ((char *)&big[i]);
	return (NULL);
}
/*
int	main(void)
{
	const char	str[] = "FindmeowBitch";
	const char	find[] = "meow";
	char	*result;

	result = ft_strnstr(str, find, 9);
	printf("Substring is %s\n", result);
	return (0);
}*/
