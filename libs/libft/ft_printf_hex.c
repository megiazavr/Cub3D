/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ne <ncruz-ne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 18:34:01 by ncruz-ne          #+#    #+#             */
/*   Updated: 2025/05/26 16:31:04 by ncruz-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf_hex(size_t n, int len, char x)
{
	char	*arr;

	arr = "0123456789abcdef";
	if (x == 'X')
		arr = "0123456789ABCDEF";
	if (n < 16)
		len += ft_putchar_fd_len(arr[n], 1);
	if (n >= 16)
	{
		len += ft_printf_hex(n / 16, len, x);
		ft_putchar_fd_len(arr[n % 16], 1);
		len++;
	}
	return (len);
}
