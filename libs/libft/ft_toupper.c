/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megiazar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 12:45:57 by megiazar          #+#    #+#             */
/*   Updated: 2025/04/14 13:29:29 by megiazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}
/*
int	main(int argc, char *argv[])
{
	int	j = 0;
	if (argc != 2)
		return (1);
	else
	while (argv[1][j] != '\0')
	{
		printf("%c", ft_toupper(argv[1][j]));
		j++;
	}
	return (0);
}*/
