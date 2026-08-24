/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megi <megi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 16:46:10 by megi              #+#    #+#             */
/*   Updated: 2026/08/24 14:50:21 by megi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3D.h"

//readthemeap is splitting and getting 1 massive of [identifier and the path]

int parseconfig(t_map *map, char *file) {
	char *line;
	int fd;
	t_results res;
	fd = open(file, O_RDONLY);

	if (fd == -1)
		return (perror("OOPS "), 0);
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (empty_flag(line))
		{
			line = get_next_line(fd);
			continue ;
		}
		res = valid_identifier(map, line);
		if (res == COLOR)
			res = valid_color(map, line);
		if (res == ERROR)
			exit(1);
		line = get_next_line(fd);
	}
	return (0);
}

