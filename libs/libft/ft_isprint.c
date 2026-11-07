/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megiazar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 12:15:38 by megiazar          #+#    #+#             */
/*   Updated: 2025/04/11 13:16:23 by megiazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}

/*int	main(void)
{
	char	*str = "9";

	while (*str != '\0')
	{
		printf("%d\n", ft_isprint(*str));
		str++;
	}
	return (0);
}*/

/*int	main(int argc, char *argv[])
{
	int	i;

	i = 0;
	if (argc == 2)
	{
		while (argv[1][i] != '\0')
		{
			printf("%d\n", ft_isprint(argv[1][i]));
			i++;;
		}
	}
	return (0);
}*/
