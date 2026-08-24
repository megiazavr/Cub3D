/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megi <megi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 14:40:59 by megi              #+#    #+#             */
/*   Updated: 2026/08/24 14:45:27 by megi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3D.h"

t_results valid_identifier(t_map *map, char *str) {
    char **identifier = ft_split(str, ' ');

	if (identifier[0] == NULL)
		return (texture_errors(ERR_IDENTIFIER), ERROR);
	if (ft_strcmp(identifier[0], "C") == 0 || ft_strcmp(identifier[0], "F") == 0)
		return (COLOR);
	if (identifier[1] == NULL)
		return (texture_errors(ERR_IDENTIFIER), ERROR);
	if (ft_strcmp(identifier[0], "NO") == 0) {
		map->path[NO] = identifier[1];
		return (TEXTURE);
	}
	else if (ft_strcmp(identifier[0], "SO") == 0) {
		map->path[SO] = identifier[1];
		return (TEXTURE);
	}
	else if (ft_strcmp(identifier[0], "WE") == 0) {
		map->path[WE] = identifier[1];
		return (TEXTURE);
	}
	else if (ft_strcmp(identifier[0], "EA") == 0) {
		map->path[EA] = identifier[1];
		return (TEXTURE);
	}
    return (texture_errors(ERR_IDENTIFIER), ERROR);
}
