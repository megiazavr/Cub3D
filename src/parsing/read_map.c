/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ne <ncruz-ne@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 21:38:02 by ncruz-ne          #+#    #+#             */
/*   Updated: 2026/09/27 20:29:54 by ncruz-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3D.h"

//readthemeap is splitting and getting 1 massive of [identifier and the path
//TODO: CHECK IF I CAN D I++ ONCE
int readthemap(t_map *map, char *l)
{
	int	i;
	int	space;

	(void)map;
	i = -1;
	space = 0;
	while (l[i])
	{
		if (l[i] == '0' || l[i] == '1')
			i++;
		else if (l[i] == ' ')
		{
			space++;
			if (space > 2)
				return (map_errors(ERR_MAP_SPACE), ERROR);
			i++;
		}			
		else if (l[i] == 'N' || l[i] == 'S' || l[i] == 'W' || l[i] == 'E')
		{
			space = 0;
			map->one_player_per_map++;
			if (map->one_player_per_map == 1)
				map->player = l[i];
			if (map->one_player_per_map > 1 || map->one_player_per_map < 1) // TODO: change to just else?
				map_errors(ERR_PLAYER);
			i++;
		}
		// TODO: are the conditions below correct?
		if (map->one_player_per_map == 0)
			map_errors(ERR_PLAYER);
		else
		{
			map_errors(ERR_PLAYER);
			i++;
		}
	}
	return (map->one_player_per_map);
}
