/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megi <megi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 16:46:10 by megi              #+#    #+#             */
/*   Updated: 2026/11/04 18:50:26 by megi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3D.h" // bring in t_map, t_id_res, prototypes, error enums

// static t_id_res identifiers_done(t_map *map)
// {
// 	int i;

// 	i = 0;
// 	while (i < 4)
// 	{
// 		if (map->n_s_e_w_paths[i] == NULL)
// 			break ;
// 		i++;
// 	}
// 	if (i > 4)
// 		return (ERROR);
// 	else if (i < 4)
// 		return (PENDING);
// 	i = 0;
// 	while (i < 6)
// 	{
// 		if (map->rgb_c_f[i] == -1)
// 			break ;
// 		i++;
// 	}
// 	if (i > 6)
// 		return (ERROR);
// 	else if (i < 6)
// 		return (PENDING);
// 	return (DONE);
// }

static t_id_res	identifiers_done(t_map *map)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (map->n_s_e_w_paths[i] == NULL)
			break ;
		i++;
	}
	if (i > 4) // TODO: Can it reach here? 
		return (ERROR);
	else if (i < 4)
		return (PENDING);
	if (map->rgb_c_f[C] == -1 || map->rgb_c_f[F] == -1)
		return (PENDING);
	return (DONE);
}

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
		res = identifiers_done(map);
		if (res == PENDING)
			parse_map_identifiers(map, line);
		// if (res == COLOR)
		// 	parseconfig(map, line);
		else if (res == ERROR) // TODO: do we reach here? 
		{
			free(line);
			exit_cleanup(map, ERR_TEXTURE, ERR_IDENTIFIER_MSG);
		}
		else if (res == DONE)
		{
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
		}
		line = get_next_line(fd);
	}
}

/* TODO: don't forget to free(line) before any exit_cleanup()
t_monitor monitor(t_map *map)
{
	int fd;
	int	in_map;
	int	i;

	fd = open(map->file, O_RDONLY);
	if (fd < 0)
		exit_cleanup(map, ERR_PERR, ERR_OPEN_MSG);
	map->one_player_per_map = 0;
	in_map = 0;
	i = 0;
	while (i < 4)
		map->n_s_e_w_paths[i++] = NULL;
	i = 0;
	while (i < 6)
		map->rgb_c_f[i++] = -1;
	monitor_loop(map, fd, in_map);
	return (MAP);
}
*/

t_monitor	monitor(t_map *map)
{
	// char	*line; // TODO: delete if norm adjustments are good
	int fd;
	int	in_map;
	int	i;

	fd = open(map->file, O_RDONLY);
	if (fd < 0)
		exit_cleanup(map, ERR_PERR, ERR_OPEN_MSG);
	map->one_player_per_map = 0;
	map->next_identifier = 0;
	in_map = 0;
	i = 0;
	while (i < 4)
		map->n_s_e_w_paths[i++] = NULL;
	i = 0;
	while (i < 6)
		map->rgb_c_f[i++] = -1;
	// map->rgb_c_f[C] = -1;
	// map->rgb_c_f[F] = -1;
	monitor_loop(map, fd, in_map);
	// if (map->one_player_per_map == 0)
	// 	exit_cleanup(map, ERR_MAP, ERR_PLAYER_MSG);
	return (MAP);
}
