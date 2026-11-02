/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megi <megi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 14:40:59 by megi              #+#    #+#             */
/*   Updated: 2026/08/26 18:30:19 by megi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3D.h"

t_results valid_identifier(t_map *map, char *str) 
{
    map->parsing.identifier = ft_split(str, ' ');
	if (map->parsing.identifier[0] == NULL)
		return (texture_errors(ERR_IDENTIFIER), ERROR);
	if (ft_strcmp(map->parsing.identifier[0], "C") == 0 
		|| ft_strcmp(map->parsing.identifier[0], "F") == 0)
		return (COLOR);
	if (map->parsing.identifier[1] == NULL)
		return (texture_errors(ERR_IDENTIFIER), ERROR);
	if (ft_strcmp(map->parsing.identifier[0], "NO") == 0) {
		map->parsing.path[NO] = map->parsing.identifier[1];
		return (TEXTURE);
	}
	else if (ft_strcmp(map->parsing.identifier[0], "SO") == 0) {
		map->parsing.path[SO] = map->parsing.identifier[1];
		return (TEXTURE);
	}
	else if (ft_strcmp(map->parsing.identifier[0], "WE") == 0) {
		map->parsing.path[WE] = map->parsing.identifier[1];
		return (TEXTURE);
	}
	else if (ft_strcmp(map->parsing.identifier[0], "EA") == 0) {
		map->parsing.path[EA] = map->parsing.identifier[1];
		return (TEXTURE);
	}
    return (texture_errors(ERR_IDENTIFIER), ERROR);
}
