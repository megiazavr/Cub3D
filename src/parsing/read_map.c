/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ne <ncruz-ne@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 21:38:02 by ncruz-ne          #+#    #+#             */
/*   Updated: 2026/11/07 03:30:59 by ncruz-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3D.h"

int	readthemap(t_map *map, char *l)
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
			{
				free(l);
				return (exit_cleanup(map, ERR_MAP, ERR_MAP_SPACE_MSG), ERROR);
			}
		}
		else if (*l == 'N' || *l == 'S' || *l == 'W' || *l == 'E')
		{
			map->space = 0;
			map->one_player_per_map++;
			if (map->one_player_per_map == 1)
				map->player_dir = *l;
			else if (map->one_player_per_map != 1)
			{
				free(l);
				exit_cleanup(map, ERR_MAP, ERR_PLAYER_MSG);
			}
		}
		else
		{
			free(l);
			exit_cleanup(map, ERR_MAP, ERR_PLAYER_MSG);
		}
		l++;
	}
	return (map->one_player_per_map);
}
