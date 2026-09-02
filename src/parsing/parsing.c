/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megi <megi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 16:46:10 by megi              #+#    #+#             */
/*   Updated: 2026/08/24 21:34:59 by megi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3D.h"

//readthemeap is splitting and getting 1 massive of [identifier and the path

//TODO:SHOULD I ALSO DO T_RESULTS AND RETURN RESULT AS A COLOR OR MAP ETC
int parseconfig(t_map *map, char *line) {
	t_results 	res;

	res = valid_identifier(map, line);
	if (res == COLOR)
		res = valid_color(map, line);
	if (res == ERROR)
		exit(1);
	return (0);
}

//TODO: CHECK USING ENUM IF IT'S CONFIG OR MAP AND CALL IT INSIDE MONITOR
t_monitor monitor(t_map *map, char *file) {
	char		*line;
	int 		fd;
	int			in_map;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (perror("OOPS "), 0);
	map->one_player_per_map = 0;
	//in_map = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (empty_flag(line))
		{
			line = get_next_line(fd);
			continue ;
		}
		map->identifier= ft_split(line, ' ');
		if (map->identifier[0] && (ft_strcmp(map->identifier[0], "NO") == 0
			|| ft_strcmp(map->identifier[0], "SO") == 0
			|| ft_strcmp(map->identifier[0], "WE") == 0
			|| ft_strcmp(map->identifier[0], "EA") == 0
			|| ft_strcmp(map->identifier[0], "F") == 0
			|| ft_strcmp(map->identifier[0], "C") == 0))
			parseconfig(map, line);
		if (in_map == 1)
		{
			map->one_player_per_map = readthemap(map, line);
			line = get_next_line(fd);
			continue ;
		}
		else
		{
			in_map = 1;
			map->one_player_per_map = readthemap(map, line);
		}
		line = get_next_line(fd);
	}
	return (MAP);
}

//TODO: CHECK IF I CAN D I++ ONCE
int readthemap(t_map *map, char *l) {
	int	j;
	int space;

	(void)map;
	j = -1;
	space = 0;
	while (l[j])
	{
		if (l[j] == '0' || l[j] == '1')
			j++;
		else if (l[j] == ' ') {
			space += 1;
			if (space > 2)
				return (map_errors(ERR_MAP_SPACE), ERROR);
			j++;
		}			
		else if (l[j] == 'N' || l[j] == 'S' || l[j] == 'W' || l[j] == 'E') {
			space = 0;
			map->one_player_per_map += 1;
			if (map->one_player_per_map == 1)
			map->player = l[j];
			if (map->one_player_per_map > 1 || map->one_player_per_map < 1)
			map_errors(ERR_PLAYER);
			j++;
		}
		if (map->one_player_per_map == 0) {
					
			map_errors(ERR_PLAYER);
		}
		else {
			map_errors(ERR_PLAYER);
			j++;
		}
	}
	return (map->one_player_per_map);
}
