/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ne <ncruz-ne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 16:58:00 by ncruz-ne          #+#    #+#             */
/*   Updated: 2026/01/16 20:07:23 by ncruz-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strlen_nl(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	return (i);
}

static char	*append_line(char *old, char const *buf)
{
	char	*new;
	size_t	i_new;
	size_t	i_buf;

	if (!buf || !*buf)
		return (old);
	new = ft_calloc(ft_strlen_nl(old) + ft_strlen_nl(buf) + 2, 1);
	if (!new)
	{
		free(old);
		return (NULL);
	}
	i_new = 0;
	while (old && old[i_new])
	{
		new[i_new] = old[i_new];
		i_new++;
	}
	free(old);
	i_buf = 0;
	while (buf[i_buf] && buf[i_buf] != '\n')
		new[i_new++] = buf[i_buf++];
	if (buf[i_buf] == '\n')
		new[i_new++] = '\n';
	return (new);
}

char	*read_until_nl(int fd, char *buf, char *line)
{
	t_read_to_nl_vars	vars;

	while (1)
	{
		line = append_line(line, buf);
		if (!line)
			return (NULL);
		if (ft_strchr(buf, '\n'))
			break ;
		vars.bytesread = read(fd, buf, BUFFER_SIZE);
		if (vars.bytesread <= 0)
		{
			buf[0] = '\0';
			if (vars.bytesread < 0)
				return (NULL);
			return (line);
		}
		buf[vars.bytesread] = '\0';
	}
	vars.i = 0;
	vars.buf_len_nl = ft_strlen_nl(buf) + 1;
	while (buf[vars.buf_len_nl] && vars.buf_len_nl < BUFFER_SIZE)
		buf[vars.i++] = buf[vars.buf_len_nl++];
	buf[vars.i] = '\0';
	return (line);
}
