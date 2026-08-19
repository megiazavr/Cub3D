/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ne <ncruz-ne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 06:00:46 by ncruz-ne          #+#    #+#             */
/*   Updated: 2026/01/18 06:01:00 by ncruz-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_printwhat(const char *format, va_list args)
{
	int	len;

	len = 0;
	if (*format == 'c')
		len += ft_putchar_fd_len((char)va_arg(args, int), 1);
	else if (*format == '%')
		len += ft_putchar_fd_len('%', 1);
	else if (*format == 'd' || *format == 'i')
		len += ft_putnbr_fd_len(va_arg(args, int), 1);
	else if (*format == 'u')
		len += ft_putnbr_fd_len(va_arg(args, unsigned int), 1);
	else if (*format == 's')
		len += ft_putstr_fd_len(va_arg(args, char *), 1);
	else if (*format == 'p')
		len += ft_printf_ptr(va_arg(args, void *));
	else if (*format == 'x' || *format == 'X')
		len += ft_printf_hex(va_arg(args, unsigned int), 0, *format);
	else
		return (-1);
	return (len);
}

int	ft_printf(const char *format, ...)
{
	t_fmt	f;
	va_list	args;

	f.i = 0;
	f.len = 0;
	if (!format)
		return (-1);
	va_start(args, format);
	while (format[f.i])
	{
		if (format[f.i] == '%')
		{
			f.i++;
			f.errchck = ft_printwhat(&format[f.i], args);
			if (f.errchck == -1)
				return (-1);
			f.len += f.errchck;
		}
		else
			f.len += ft_putchar_fd_len(format[f.i], 1);
		f.i++;
	}
	va_end(args);
	return (f.len);
}
