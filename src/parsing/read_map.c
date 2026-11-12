/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megi <megi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 21:38:02 by ncruz-ne          #+#    #+#             */
/*   Updated: 2026/11/09 18:37:52 by megi             ###   ########.fr       */
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
			else if (map->one_player_per_map == 0)
				exit_cleanup(map, ERR_MAP, ERR_PLAYER_MSG);
		}
		else
			exit_cleanup(map, ERR_MAP, ERR_PLAYER_MSG);
		l++;
	}
	return (map->one_player_per_map);
}

// DFS = Depth-First Search. It’s a strategy for exploring a graph (or grid, like your map) where you go as deep as possible down one path before backtracking.

// Concretely, for flood fill: starting from the player, DFS picks one neighbor (say, up), fully explores everything reachable through that neighbor — and everything reachable through its neighbors, and so on, all the way until it hits dead ends (walls or already-visited cells) — before it ever comes back and tries the player’s other neighbors (down, left, right).

// That’s exactly what the recursive version does: flood_fill(y+1, x) doesn’t return until it has completely finished exploring everything reachable from (y+1, x) — only then does control come back and move on to flood_fill(y-1, x). Each recursive call dives one level deeper before anything “returns” — that depth-first order is where the name comes from, and it’s also literally why each pending call sits on the stack (the thing we talked about with recursion depth).

// The alternative is BFS (Breadth-First Search) — explore all immediate neighbors first, then all of their neighbors, spreading outward in rings/layers rather than diving down one path. BFS is usually done with a queue (FIFO) instead of a stack, but for flood fill’s purpose here (just: “is everything reachable enclosed?”), DFS and BFS both give you the same correct answer — they just visit cells in a different order. Which one you pick doesn’t change whether the map validates correctly, only the order cells get marked.


// flood_fill(map, y + 1, x)
// flood_fill(map, y - 1, x)
// flood_fill(map, y, x + 1)
// flood_fill(map, y , x-1)

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
// 			map->one_player_per_map = map->row_y++;
// 			//free_str(&map->read_line);
// 			map->read_line = get_next_line(map->file_fd);
// 			continue ;
// 		}
// 		else
// 		{
// 			in_map = 1;
// 			map->one_player_per_map = map->row_y++;
// 			// free_str(&map->read_line);
// 		}
// 	}
// 	return ;
// }

// int 	rows_counter(t_map *map)
// {
// 	map->read_line = get_next_line(map->file_fd);
// 	while (map->read_line != NULL)
// 	{
// 		if (empty_flag(map->read_line) == true)
// 		{
// 			free_str(&map->read_line);
// 			map->read_line = get_next_line(map->file_fd);
// 			continue ;
// 		}
// 		res = config_done(map);
// 		if (res == PENDING)
// 			parse_map_config(map);
// 		else if (res == ERROR) // TODO: do we reach here? 
// 			exit_cleanup(map, ERR_TEXTURE, ERR_IDENTIFIER_MSG);
// 		else if (res == DONE)
// 			parse_map(map, in_map);
// 		free_str(&map->read_line);
// 		map->read_line = get_next_line(map->file_fd);
// 	}
// }

// int flood_map(t_map *map, char *l) 
// {
// 	size_t len; 

// 	if (map->column_x <=  )
// }