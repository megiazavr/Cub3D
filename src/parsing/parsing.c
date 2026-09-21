/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ne <ncruz-ne@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 16:46:10 by megi              #+#    #+#             */
/*   Updated: 2026/09/21 22:38:44 by ncruz-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3D.h"

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

static int	validate_map_identifiers(t_map *map, char *line)
{
	map->identifier = ft_split(line, ' ');
	if (map->identifier[0])
	{
		if (ft_strcmp(map->identifier[0], "NO") == 0
			|| ft_strcmp(map->identifier[0], "SO") == 0
			|| ft_strcmp(map->identifier[0], "WE") == 0
			|| ft_strcmp(map->identifier[0], "EA") == 0
			|| ft_strcmp(map->identifier[0], "F") == 0
			|| ft_strcmp(map->identifier[0], "C") == 0)
			return (0);
	}
	return (1);
}

static void	monitor_loop(t_map *map, int fd, int in_map)
{
	char	*line;

	line = get_next_line(fd);
	while (line != NULL)
	{
		if (empty_flag(line))
		{
			line = get_next_line(fd);
			continue ;
		}
		if (validate_map_identifiers(map, line) == 0)
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
}

//TODO: CHECK USING ENUM IF IT'S CONFIG OR MAP AND CALL IT INSIDE MONITOR
t_monitor monitor(t_map *map, char *file)
{
	// char	*line; // TODO: delete if norm adjustments are good
	int 	fd;
	int		in_map;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (perror("Opening .cub file failed"), EXIT_FAILURE);
	map->one_player_per_map = 0;
	//in_map = 0;
	monitor_loop(map, fd, in_map);
	// TODO: delete commented code below if norm adjustments are good
	// line = get_next_line(fd);
	// while (line != NULL)
	// {
	// 	if (empty_flag(line))
	// 	{
	// 		line = get_next_line(fd);
	// 		continue ;
	// 	}
	// 	map->identifier = ft_split(line, ' ');
	// 	if (map->identifier[0] && (ft_strcmp(map->identifier[0], "NO") == 0
	// 		|| ft_strcmp(map->identifier[0], "SO") == 0
	// 		|| ft_strcmp(map->identifier[0], "WE") == 0
	// 		|| ft_strcmp(map->identifier[0], "EA") == 0
	// 		|| ft_strcmp(map->identifier[0], "F") == 0
	// 		|| ft_strcmp(map->identifier[0], "C") == 0))
	// 		parseconfig(map, line);
	// 	if (in_map == 1)
	// 	{
	// 		map->one_player_per_map = readthemap(map, line);
	// 		line = get_next_line(fd);
	// 		continue ;
	// 	}
	// 	else
	// 	{
	// 		in_map = 1;
	// 		map->one_player_per_map = readthemap(map, line);
	// 	}
	// 	line = get_next_line(fd);
	// }
	return (MAP);
}
