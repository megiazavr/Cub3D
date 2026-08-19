/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd_len.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ne <ncruz-ne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 13:15:25 by ncruz-ne          #+#    #+#             */
/*   Updated: 2025/05/26 16:30:57 by ncruz-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_fd_len(const char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
		return (ft_putstr_fd_len("(null)", 1));
	while (s[i] && s[i] != '%')
	{
		ft_putchar_fd_len(s[i], 1);
		i++;
	}
	return (i);
}
