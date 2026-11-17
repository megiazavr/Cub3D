/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ne <ncruz-ne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 16:57:35 by ncruz-ne          #+#    #+#             */
/*   Updated: 2026/01/16 20:02:15 by ncruz-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	g_gnl_buf[FOPEN_MAX][BUFFER_SIZE + 1];

void	gnl_reset(int fd)
{
	if (fd >= 0 && fd < FOPEN_MAX)
		g_gnl_buf[fd][0] = '\0';
}

char	*get_next_line(int fd)
{
	char		*line;
	ssize_t		bytesread;

	if (BUFFER_SIZE <= 0 || fd < 0 || fd >= FOPEN_MAX)
		return (NULL);
	line = NULL;
	if (!g_gnl_buf[fd][0])
	{
		bytesread = read(fd, g_gnl_buf[fd], BUFFER_SIZE);
		if (bytesread <= 0)
		{
			g_gnl_buf[fd][0] = '\0';
			return (NULL);
		}
		g_gnl_buf[fd][bytesread] = '\0';
	}
	line = read_until_nl(fd, g_gnl_buf[fd], line);
	if (!line)
		return (NULL);
	return (line);
}
