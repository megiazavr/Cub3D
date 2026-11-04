/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megi <megi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 21:38:02 by ncruz-ne          #+#    #+#             */
/*   Updated: 2026/11/04 18:39:27 by megi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3D.h"

int readthemap(t_map *map, char *l)
{
	map->space = 0;
	while (*l)
	{
		if (*l == '0' || *l == '1')
			map->space = 0;
		else if (*l == ' ' || *l == '\t')
		{
			map->space++;
			if (map->space > 2)
				return (exit_cleanup(map, ERR_MAP, ERR_MAP_SPACE_MSG), ERROR);
		}
		else if (*l == 'N' || *l == 'S' || *l == 'W' || *l == 'E') 
		{
			map->space = 0;
			map->one_player_per_map++;
			if (map->one_player_per_map == 1)
				map->player_dir = *l;
			else if (map->one_player_per_map != 1) 
				exit_cleanup(map, ERR_MAP, ERR_PLAYER_MSG);
		}
		else
			exit_cleanup(map, ERR_MAP, ERR_PLAYER_MSG);
		l++;
	}
	return (map->one_player_per_map);
}

