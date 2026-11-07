/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megiazar <megiazar@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 17:36:49 by megiazar          #+#    #+#             */
/*   Updated: 2025/04/29 15:55:55 by megiazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

static int	ft_sign(int n)
{
	int	sign;

	sign = 1;
	if (n < 0)
		sign = -1;
	return (sign);
}

static char	*ft_nul(int n, char *str)
{
	if (n == 0)
		str[0] = '0';
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		sign;

	sign = ft_sign(n);
	len = ft_len(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	ft_nul(n, str);
	str[len] = '\0';
	while (n != 0)
	{
		str[--len] = (n % 10) * (2 * (n > 0) - 1) + '0';
		n = n / 10;
	}
	len--;
	if (sign < 0)
		str[len] = '-';
	return (str);
}
/*
int	main(int ac, char *av[])
{
	if (ac == 2)
		printf("%s", ft_itoa(atoi(av[1])));
}

int	main(void)
{
	printf("%s\n", ft_itoa(-214748368LL));
	printf("%s\n", ft_itoa(           -214748368LL));
	printf("%s\n", ft_itoa(21474837));
	printf("%s\n", ft_itoa(    -10));
	printf("%s\n", ft_itoa(000000));
}*/