/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megi <megi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 16:46:10 by megi              #+#    #+#             */
/*   Updated: 2026/11/03 17:37:05 by megi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3D.h"

int parseconfig(t_map *map, char *line) {
	t_id_res 	res;

	res = valid_identifier(map, line);
	if (res == COLOR)
		res = valid_color(map, line);
	if (res == ERROR)
		exit_cleanup(map, ERR_TEXTURE, ERR_MISSING_ID);
	return (0);
}

static t_id_res is_config_identifier(char *line)
{
	char		**av;
	t_id_res	res;

	av = ft_split(line, ' '); //splitting to see the first word 
	res = ERROR;
	if (av[0] && (ft_strcmp(av[0], "NO") == 0
		|| ft_strcmp(av[0], "SO") == 0
		|| ft_strcmp(av[0], "WE") == 0
		|| ft_strcmp(av[0], "EA") == 0
		|| ft_strcmp(av[0], "F") == 0
		|| ft_strcmp(av[0], "C") == 0))
		res = TEXTURE;
	free_split(av);
	return (res);
}

static void monitor_loop(t_map *map, int fd, bool in_map)
{
	char	*line;
	//int i;

	line = get_next_line(fd);
	//i = 0;
	while (line != NULL)
	{
		if (empty_flag(line) == true) {
			line = get_next_line(fd);
			continue ;
		}
		// if (empty_flag(line)) {
		// 	line = get_next_line(fd);
		// 	continue ;
		// }
		if (in_map == false)
		{
			if (is_config_identifier(line) != ERROR)
			{
				parseconfig(map, line);
				line = get_next_line(fd);
				continue ;
			}
			//in_map = true;
		}
		else if (in_map == true)
			readthemap(map, line);
		line = get_next_line(fd);
	}
}

t_monitor monitor(t_map *map) {
	int 		fd;

	map->identifier = NULL;
	fd = open(map->file, O_RDONLY);
	if (fd == -1)
		exit_cleanup(map, ERR_PERR, ERR_OPEN_MSG);
	map->one_player_per_map = 0;
	map->rows = 0;
	map->lines.head = NULL;
	map->lines.tail = NULL;
	monitor_loop(map, fd, false);
	build_grid(map);
	if (map->one_player_per_map == 0)
		exit_cleanup(map, ERR_MAP, ERR_PLAYER_MSG);
	//check_walls(map);
	return (MAP);
}
