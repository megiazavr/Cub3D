/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megi <megi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 21:38:02 by ncruz-ne          #+#    #+#             */
/*   Updated: 2026/11/16 18:08:23 by megi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

int	read_map(t_map *map, char *l)
{
	while (*l)
	{
		if (*l == '0' || *l == '1')
			map->space = 0;
		else if (*l == ' ' || *l == '\t')
		{
			map->space++;
			if (map->space > 2)
				exit_cleanup(map, ERR_MAP, ERR_MAP_SPACE_MSG);
		}
		else if (*l == 'N' || *l == 'S' || *l == 'W' || *l == 'E')
		{
			map->space = 0;
			map->one_player_per_map++;
			if (map->one_player_per_map == 1)
				map->player_dir = *l;
			// else if (map->one_player_per_map == 0)
			// 	exit_cleanup(map, ERR_MAP, ERR_PLAYER_MSG);
		}
		else
			exit_cleanup(map, ERR_MAP, ERR_PLAYER_MSG);
		l++;
	}
	return (map->one_player_per_map);
}

// int matrix_flood_fill(t_map *map, t_map *y, t_map *x)
// {

// 	}
// 	matrix_flood_fill(map, y->row_y + 1, x->column_x);
// 	matrix_flood_fill(map, y->row_y - 1, x->column_x);
// 	matrix_flood_fill(map, y->row_y, x->column_x + 1);
// 	matrix_flood_fill(map, y->row_y + 1, x->column_x - 1);
// }

// int flood_fill(t_map *map)
// {
	
// }

// DFS = Depth-First Search.
// flood_fill(map, y + 1, x)
// flood_fill(map, y - 1, x)
// flood_fill(map, y, x + 1)
// flood_fill(map, y , x-1)
