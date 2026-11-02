/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ne <ncruz-ne@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 16:46:10 by megi              #+#    #+#             */
/*   Updated: 2026/11/02 00:48:15 by ncruz-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3D.h"

//TODO:SHOULD I ALSO DO T_RESULTS AND RETURN RESULT AS A COLOR OR MAP ETC
int parseconfig(t_map *map, char *line)
{
	t_id_res 	res;

	res = valid_identifier(map, line);
	if (res == COLOR)
		res = valid_color(map, line);
	if (res == ERROR)
		exit_cleanup(map, NULL, EXIT_FAILURE);
	return (0);
}

// static t_id_res	parse_map_identifiers(t_map *map, char *line)
// {
// 	char	*trmd_line;
//
// 	trmd_line = ft_strtrim(line, " \n\t\v");
// 	map->identifier = ft_split(trmd_line, ' ');
// 	if (map->identifier && map->identifier[0])
// 	{
// 		if (ft_strcmp(map->identifier[0], "NO") == 0
// 			|| ft_strcmp(map->identifier[0], "SO") == 0
// 			|| ft_strcmp(map->identifier[0], "EA") == 0
// 			|| ft_strcmp(map->identifier[0], "WE") == 0
// 			|| ft_strcmp(map->identifier[0], "F") == 0
// 			|| ft_strcmp(map->identifier[0], "C") == 0)
// 			return (COLOR);
// 	}
// 	free(trmd_line);
// 	return (ERROR);
// }

// static bool	valid_map_identifiers(t_map *map, char *line)
// {
// 	char	*trmd_line;
//
// 	trmd_line = ft_strtrim(line, " \n\t\v");
// 	map->identifier = ft_split(trmd_line, ' ');
// 	if (map->identifier[0])
// 	{
// 		if (ft_strcmp(map->identifier[0], "NO") == 0
// 			|| ft_strcmp(map->identifier[0], "SO") == 0
// 			|| ft_strcmp(map->identifier[0], "WE") == 0
// 			|| ft_strcmp(map->identifier[0], "EA") == 0
// 			|| ft_strcmp(map->identifier[0], "F") == 0
// 			|| ft_strcmp(map->identifier[0], "C") == 0)
// 			return (true);
// 	}
// 	free(trmd_line);
// 	return (false);
// }

static void	monitor_loop(t_map *map, int fd, int in_map)
{
	char		*line;
	t_id_res	res;

	line = get_next_line(fd);
	while (line != NULL)
	{
		if (empty_flag(line) == true)
		{
			line = get_next_line(fd);
			continue ;
		}
		res = parse_map_identifiers(map, line);
		if (res == COLOR)
			parseconfig(map, line);
		else if (res == ERROR)
		{
			texture_errors(ERR_IDENTIFIER);
			exit_cleanup(map, NULL, EXIT_FAILURE);
		}
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
t_monitor monitor(t_map *map)
{
	// char	*line; // TODO: delete if norm adjustments are good
	int 	fd;
	int		in_map;

	fd = open(map->file, O_RDONLY);
	if (fd < 0)
		exit_cleanup(map, "Opening .cub file failed", EXIT_FAILURE);
	map->one_player_per_map = 0;
	in_map = 0;
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
