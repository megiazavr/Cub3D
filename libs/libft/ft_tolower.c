/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megiazar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 13:30:53 by megiazar          #+#    #+#             */
/*   Updated: 2025/04/14 13:37:15 by megiazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}

/*
int	main(int argc, char *argv[])
{
	int	j = 0;
	if (argc != 2)
		return (1);
	while (argv[1][j] != '\0')
	{
		printf("%c", ft_tolower(argv[1][j]));
		j++;
	}
	printf("\n");
	return (0);
}*/
