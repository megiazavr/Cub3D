/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ne <ncruz-ne@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 16:46:10 by megi              #+#    #+#             */
/*   Updated: 2026/11/12 00:32:50 by ncruz-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h" 
#include <stdbool.h>
static t_id_res	config_done(t_map *map)
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

static void	count_map_rows(t_map *map)
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
		res = config_done(map);
		if (res == PENDING)
			parse_map_config(map);
		else if (res == ERROR)
			exit_cleanup(map, ERR_TEXTURE, ERR_IDENTIFIER_MSG);
		else if (res == DONE)
			map->rows++;
		free_str(&map->read_line);
		map->read_line = get_next_line(map->file_fd);
	}
}

// static void	parse_map(t_map *map, int in_map)
// {
// 	while (map->read_line != NULL)
// 	{
// 		if (empty_flag(map->read_line) == true)
// 		{
// 			//free_str(&map->read_line);
// 			map->read_line = get_next_line(map->file_fd);
// 			continue ;
// 		}
// 		if (in_map == 1)
// 		{
// 			map->one_player_per_map = read_map(map, map->read_line);
// 			//map->row_y++;
// 			//free_str(&map->read_line);
// 			map->read_line = get_next_line(map->file_fd);
// 			continue ;
// 		}
// 		else
// 		{
// 			in_map = 1;
// 			map->one_player_per_map = read_map(map, map->read_line);
// 			//map->row_y++;
// 			// free_str(&map->read_line);
// 		}
// 	}
// 	return ;
// }

static void	parse_map(t_map *map, int in_map)
{
	int	i;
	int	curr_file_row;

	i = 0;
	curr_file_row = 0;
	map->matrix = malloc(sizeof(char *) * map->rows);
	if (!map->matrix)
		exit_cleanup(map, ERR_PERR, ERR_MEM_MATRIX_MSG);
	map->file_fd = open(map->file, O_RDONLY);
	if (map->file_fd < 0)
		exit_cleanup(map, ERR_PERR, ERR_OPEN_MSG);
	while (map->read_line != NULL)
	{
		while (curr_file_row < map->rows_until_map)
		{
			map->read_line = get_next_line(map->file_fd);
		}
		// if (empty_flag(map->read_line) == true)
		// {
		// 	free_str(&map->read_line);
		// 	map->read_line = get_next_line(map->file_fd);
		// 	continue ;
		// }
		if (in_map == 1)
		{
			map->one_player_per_map = read_map(map, map->read_line);
			map->matrix[i++] = map->read_line;
			map->rows++;
			map->read_line = get_next_line(map->file_fd);
			continue ;
		}
		else
		{
			in_map = 1;
			map->one_player_per_map = read_map(map, map->read_line);
			map->matrix[i++] = map->read_line;
			map->read_line = get_next_line(map->file_fd);
		}
	}
	return ;
}

static void	monitor_loop(t_map *map, int in_map)
{
	t_id_res	res;
	bool		first_open;

	map->read_line = get_next_line(map->file_fd);
	map->rows_until_map = 1;
	first_open = true;
	res = PENDING;
	while (map->read_line != NULL)
	{
		if (empty_flag(map->read_line) == true)
		{
			free_str(&map->read_line);
			map->read_line = get_next_line(map->file_fd);
			if (res != DONE)
				map->rows_until_map++;
			continue ;
		}
		res = config_done(map);
		if (res == PENDING)
			parse_map_config(map);
		else if (res == ERROR) // TODO: do we reach here? 
			exit_cleanup(map, ERR_TEXTURE, ERR_IDENTIFIER_MSG);
		else if (res == DONE)
		{
			if (res == DONE && first_open == true)
			{
				count_map_rows(map);
				close(map->file_fd);
				first_open = false;
			}
			if (res == DONE && first_open == false)
				parse_map(map, in_map);
		}
		// {
		// 	if (in_map == 1)
		// 	{
		// 		map->one_player_per_map = read_map(map, map->read_line);
		// 		free_str(&map->read_line);
		// 		map->read_line = get_next_line(map->file_fd);
		// 		continue ;
		// 	}
		// 	else
		// 	{
		// 		in_map = 1;
		// 		map->one_player_per_map = read_map(map, map->read_line);
		// 		// free_str(&map->read_line);
		// 	}
		// }
		free_str(&map->read_line);
		map->read_line = get_next_line(map->file_fd);
		if (res != DONE)
			map->rows_until_map++;
	}
	free_str(&map->read_line);
	return ;
}


// t_monitor	monitor(t_map *map)
// {
// 	int	in_map;
//
// 	map->file_fd = open(map->file, O_RDONLY);
// 	if (map->file_fd < 0)
// 		exit_cleanup(map, ERR_PERR, ERR_OPEN_MSG);
// 	in_map = 0; // TODO: confirm if we need var in this function
// 	rgb_print(map, 0);
// 	monitor_loop(map, in_map);
// 	// if (map->one_player_per_map == 0)
// 	// 	exit_cleanup(map, ERR_MAP, ERR_PLAYER_MSG);
// 	return (MAP);
// }

//TODO: this function isn't doing much, it's always returning map. We need to check inside the main if there is a map in the end and if not - return an error?
// t_monitor	monitor(t_map *map)
// {
// 	int	i;
//
// 	map->file_fd = open(map->file, O_RDONLY);
// 	if (map->file_fd < 0)
// 		exit_cleanup(map, ERR_PERR, ERR_OPEN_MSG);
// 	count_map_rows(map);
// 	close(map->file_fd);
// 	i = 0;
// 	while (i < 4)
// 		free_str(&map->n_s_w_e_paths[i++]);
// 	map->rgb_f_c[0] = -1;
// 	map->rgb_f_c[1] = -1;
// 	map->next_identifier = 0;
// 	map->matrix = malloc(sizeof(char *) * map->rows);
// 	if (!map->matrix)
// 		exit_cleanup(map, ERR_PERR, ERR_MEM_MATRIX_MSG);
// 	map->file_fd = open(map->file, O_RDONLY);
// 	if (map->file_fd < 0)
// 		exit_cleanup(map, ERR_PERR, ERR_OPEN_MSG);
// 	rgb_print(map, 0);
// 	monitor_loop(map, 0);
// 	// if (map->one_player_per_map == 0)
// 	// 	exit_cleanup(map, ERR_MAP, ERR_PLAYER_MSG);
// 	return (MAP);
// }

t_monitor	monitor(t_map *map)
{
	int	in_map;

	map->file_fd = open(map->file, O_RDONLY);
	if (map->file_fd < 0)
		exit_cleanup(map, ERR_PERR, ERR_OPEN_MSG);
	rgb_print(map, 0);
	in_map = 0;
	monitor_loop(map, in_map);
	// if (map->one_player_per_map == 0)
	// 	exit_cleanup(map, ERR_MAP, ERR_PLAYER_MSG);
	return (MAP);
}
