/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ne <ncruz-ne@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 16:46:10 by megi              #+#    #+#             */
/*   Updated: 2026/11/08 20:10:08 by ncruz-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h" // bring in t_map, t_id_res, prototypes, error enums

static t_id_res	identifiers_done(t_map *map)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (map->n_s_w_e_paths[i] == NULL)
			break ;
		i++;
	}
	if (i > 4)
		return (ERROR);
	else if (i < 4)
		return (PENDING);
	i = 0;
	while (i < 2)
	{
		if (map->rgb_f_c[i] == -1)
			break ;
		i++;
	}
	if (i > 2)
		return (ERROR);
	else if (i < 2)
		return (PENDING);
	return (DONE);
}

// static t_id_res	identifiers_done(t_map *map)
// {
// 	int	i;
//
// 	i = 0;
// 	while (i < 4)
// 	{
// 		if (map->n_s_e_w_paths[i] == NULL)
// 			break ;
// 		i++;
// 	}
// 	if (i > 4) // TODO: Can it reach here? 
// 		return (ERROR);
// 	else if (i < 4)
// 		return (PENDING);
// 	if (map->rgb_c_f[C - 4] == -1 || map->rgb_c_f[F - 4] == -1)
// 		return (PENDING);
// 	return (DONE);
// }

// static t_id_res	identifiers_done(t_map *map)
// {
// 	int	i;
//
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

static void	monitor_loop(t_map *map, int in_map)
{
	t_id_res	res;

	map->read_line = get_next_line(map->file_fd);
	while (map->read_line != NULL)
	{
		if (empty_flag(map->read_line) == true)
		{
			free_str(&map->read_line);
			map->read_line = get_next_line(map->file_fd);
			continue ;
		}
		res = identifiers_done(map);
		if (res == PENDING)
			parse_map_identifiers(map);
		// if (res == COLOR)
		// 	parseconfig(map, line);
		else if (res == ERROR) // TODO: do we reach here? 
			exit_cleanup(map, ERR_TEXTURE, ERR_IDENTIFIER_MSG);
		else if (res == DONE)
		{
			if (in_map == 1)
			{
				map->one_player_per_map = read_map(map, map->read_line);
				free_str(&map->read_line);
				map->read_line = get_next_line(map->file_fd);
				continue ;
			}
			else
			{
				in_map = 1;
				map->one_player_per_map = read_map(map, map->read_line);
				// free_and_null(&map->read_line);
			}
		}
		free_str(&map->read_line);
		map->read_line = get_next_line(map->file_fd);
	}
	free_str(&map->read_line);
}

t_monitor	monitor(t_map *map)
{
	int	in_map;

	map->file_fd = open(map->file, O_RDONLY);
	if (map->file_fd < 0)
		exit_cleanup(map, ERR_PERR, ERR_OPEN_MSG);
	in_map = 0;
	rgb_print(map, 0);
	monitor_loop(map, in_map);
	// if (map->one_player_per_map == 0)
	// 	exit_cleanup(map, ERR_MAP, ERR_PLAYER_MSG);
	return (MAP);
}
