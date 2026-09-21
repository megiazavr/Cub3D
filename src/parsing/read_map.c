/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ne <ncruz-ne@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 21:38:02 by ncruz-ne          #+#    #+#             */
/*   Updated: 2026/09/21 21:39:38 by ncruz-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3D.h"

//TODO: CHECK IF I CAN D I++ ONCE
int readthemap(t_map *map, char *l) {
	int	j;
	int	space;

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
