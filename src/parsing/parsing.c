/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megi <megi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 16:46:10 by megi              #+#    #+#             */
/*   Updated: 2026/11/16 18:07:33 by megi             ###   ########.fr       */
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

void	count_map_rows(t_map *map)
{
	int	curr_row;

	curr_row = 0;
	reopen(map);
	map->read_line = get_next_line(map->file_fd);
	while (map->read_line != NULL && curr_row < map->rows_until_map - 1)
	{
		free_str(&map->read_line);
		map->read_line = get_next_line(map->file_fd);
		curr_row++;
	}
	while (map->read_line != NULL)
	{
		if (empty_flag(map->read_line) == false)
			map->rows++;
		free_str(&map->read_line);
		map->read_line = get_next_line(map->file_fd);
	}
}

void	count_map_columns(t_map *map)
{
	int	curr_row;
	int	len;

	curr_row = 0;
	reopen(map);
	map->read_line = get_next_line(map->file_fd);
	while (map->read_line != NULL && curr_row < map->rows_until_map - 1)
	{
		free_str(&map->read_line);
		map->read_line = get_next_line(map->file_fd);
		curr_row++;
	}
	while (map->read_line != NULL)
	{
		if (empty_flag(map->read_line) == false)
		{
			len = ft_strlen(map->read_line);
			if (len > map->columns)
				map->columns = len;
		}
		free_str(&map->read_line);
		map->read_line = get_next_line(map->file_fd);
		printf("lenght of the column line is %d\n\n\n", len);
	}
	return ;
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

void	parse_map(t_map *map, int i)
{
	matrix(map);
	while (map->read_line != NULL)
	{
		map->one_player_per_map = read_map(map, map->read_line);
		map->matrix[i] = column_line(map);
		if (!map->matrix[i])
			exit_cleanup(map, ERR_PERR, ERR_MEM_MATRIX_MSG);
		free_str(&map->read_line);
		i++;
		map->read_line = get_next_line(map->file_fd);
		if (map->read_line != NULL)
			empty_flag(map->read_line);
	}
	return ;
}

static void	monitor_loop(t_map *map)
{
	t_id_res	res;
	bool		first_open;

	map->read_line = get_next_line(map->file_fd);
	map->rows_until_map = 1;
	first_open = true;
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
		results(map, res, &first_open);
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

t_monitor	monitor(t_map *map)
{
	reopen(map);
	// map->file_fd = open(map->file, O_RDONLY);
	// if (map->file_fd < 0)
	// 	exit_cleanup(map, ERR_PERR, ERR_OPEN_MSG);
	//rgb_print(map, 0);
	printf("here before monitor_loop\n\n");
	monitor_loop(map);
	printf("here after monitor_loop\n\n");
	if (map->rows == 0)
		exit_cleanup(map, ERR_MAP, ERR_MAP_IS_EMPTY);
	printf("here after map_rows counter\n\n");
	if (map->one_player_per_map != 1)
		exit_cleanup(map, ERR_MAP, ERR_PLAYER_MSG);
	printf("here after one player per map checker\n\n");
	// if (map->one_player_per_map == 0)
	// 	exit_cleanup(map, ERR_MAP, ERR_PLAYER_MSG);
	return (MAP);
}
