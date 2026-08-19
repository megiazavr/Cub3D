/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megiazar <megiazar@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 17:18:20 by megiazar          #+#    #+#             */
/*   Updated: 2025/04/22 18:00:03 by megiazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		f(i, s + i);
		i++;
	}
}
/*
void	toupper_wrapper(unsigned int i, char *s)
{
	(void)i;
	*s = ft_toupper(*s);
}
int	main(int ac, char *av[])
{
	if (ac == 2)
	{
		ft_striteri(av[1], toupper_wrapper);
		printf("%s\n", av[1]);
	}
	return (0);
}*/