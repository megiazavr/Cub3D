/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megi <megi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 21:38:02 by ncruz-ne          #+#    #+#             */
/*   Updated: 2026/11/17 18:18:45 by megi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

int	read_map(t_map *map, int y, int x)
{
	char	*l;

	l = map->read_line;
	map->space = 0;
	while (*l)
	{
		if (space(map, *l) == false)
		{
			if (*l == 'N' || *l == 'S' || *l == 'W' || *l == 'E')
			{
				map->space = 0;
				map->one_player_per_map++;
				if (map->one_player_per_map == 1)
				{
					map->player_dir = *l;
					map->row_y = y;
					map->column_x = x;
				}
			}
			else
				exit_cleanup(map, ERR_MAP, ERR_PLAYER_MSG);
		}
		l++;
		x++;
	}
	return (map->one_player_per_map);
}

//TEST FOR THE FLOOD FILL
void	print_matrix(t_map *map)
{
	int	y;

	y = 0;
	while (y < map->rows)
	{
		printf("%s\n", map->matrix[y]);
		y++;
	}
	printf("\n");
}

void	flood_fill(t_map *map, int y, int x)
{
	if (y < 0 || y >= map->rows || x < 0 || x >= map->columns)
		exit_cleanup(map, ERR_MAP, ERR_MAP_NOT_CLOSED_MSG);
	if (map->matrix[y][x] == '1')
		return ;
	while (x < map->columns && map->matrix[y][x] == '0')
	{
		map->matrix[y][x] = 'v';
		flood_fill(map, y + 1, x);
		flood_fill(map, y - 1, x);
		flood_fill(map, y, x - 1);
		x++;
	}
	if (x >= map->columns)
		exit_cleanup(map, ERR_MAP, ERR_MAP_NOT_CLOSED_MSG);
}

// 1111111
// 10000001
// 1001001S1 
// 111010101
// 111110001
// 111111111

void matrix(t_map *map)
{
	int curr_row;

	curr_row = 0;
	map->matrix = ft_calloc(map->rows, sizeof(char *));
	if (!map->matrix)
		exit_cleanup(map, ERR_PERR, ERR_MEM_MATRIX_MSG);
	reopen(map);
	map->read_line = get_next_line(map->file_fd);
	while (map->read_line != NULL && curr_row < map->rows_until_map - 1)
	{
		free_str(&map->read_line);
		map->read_line = get_next_line(map->file_fd);
		curr_row++;
	}
	if (map->read_line != NULL)
		empty_flag(map->read_line);
	return ;
}