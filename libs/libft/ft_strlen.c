/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megiazar <megiazar@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 14:49:34 by megiazar          #+#    #+#             */
/*   Updated: 2025/05/01 14:41:19 by megiazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

/*int	main(void)
{
	char	*str = "Hello, meow   ";

	printf("%zu\n", ft_strlen(str));
	return (0);
}*/

/*int	main(int argc, char *argv[])
{
	int	i;

	i = 1;
	if (argc == 2)
		printf("%zu\n", ft_strlen(argv[i]));
	return (0);
}*/
