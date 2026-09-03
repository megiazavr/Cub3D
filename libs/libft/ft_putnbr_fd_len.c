/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd_len.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ne <ncruz-ne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 15:27:50 by ncruz-ne          #+#    #+#             */
/*   Updated: 2025/05/26 16:31:01 by ncruz-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_fd_len(long long n, int fd)
{
	int	len;

	len = ft_nlen(n);
	if (n < 0)
	{
		ft_putchar_fd_len('-', 1);
		n = -n;
	}
	if (n > 9)
	{
		ft_putnbr_fd_len(n / 10, fd);
		ft_putchar_fd_len((n % 10) + '0', 1);
	}
	if (n < 10 && n >= 0)
	{
		ft_putchar_fd_len(n + '0', 1);
	}
	return (len);
}
