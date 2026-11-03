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

t_id_res valid_identifier(t_map *map, char *str)
{
    map->identifier = ft_split(str, ' ');
	if (map->identifier[0] == NULL)
		exit_cleanup(map, ERR_TEXTURE, ERR_IDENTIFIER_MSG);
	if (ft_strcmp(map->identifier[0], "C") == 0
		|| ft_strcmp(map->identifier[0], "F") == 0)
		return (COLOR);
	if (map->identifier[1] == NULL)
		exit_cleanup(map, ERR_TEXTURE, ERR_IDENTIFIER_MSG);
	if (ft_strcmp(map->identifier[0], "NO") == 0) {
		map->n_s_e_w_paths[NO] = map->identifier[1];
		return (TEXTURE);
	}
	else if (ft_strcmp(map->identifier[0], "SO") == 0) {
		map->n_s_e_w_paths[SO] = map->identifier[1];
		return (TEXTURE);
	}
	else if (ft_strcmp(map->identifier[0], "WE") == 0) {
		map->n_s_e_w_paths[WE] = map->identifier[1];
		return (TEXTURE);
	}
	else if (ft_strcmp(map->identifier[0], "EA") == 0) {
		map->n_s_e_w_paths[EA] = map->identifier[1];
		return (TEXTURE);
	}
    exit_cleanup(map, ERR_TEXTURE, ERR_IDENTIFIER_MSG);
    return (ERROR);
}
