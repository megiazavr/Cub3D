/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ne <ncruz-ne@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 14:40:59 by megi              #+#    #+#             */
/*   Updated: 2026/11/08 22:48:32 by ncruz-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h" // bring in t_map, t_map_ids, prototypes, error enums

static void	valid_texture_path(t_map *map, t_map_ids id)
{
	if ((int)id != map->next_identifier)
		exit_cleanup(map, ERR_TEXTURE, ERR_ORDER_MSG);
	map->next_identifier++;
	if (map->identifier[1] && map->n_s_w_e_paths[id] == NULL)
	{
		map->n_s_w_e_paths[id] = ft_strtrim(map->identifier[1], " \t");
		if (!map->n_s_w_e_paths[id])
			exit_cleanup(map, ERR_PERR, ERR_MEM_PATH_MSG);
	}
	else
		exit_cleanup(map, ERR_TEXTURE, ERR_DUPE_PATH_MSG);
	return ;
}

// static void valid_identifier(t_map *map)
// { 
// 	if (map->identifier[0] && map->identifier[1]) // ?
// 	{
// 		if (ft_strcmp(map->identifier[0], "NO") == 0)
// 			valid_texture_path(map, NO);
// 		else if (ft_strcmp(map->identifier[0], "SO") == 0)
// 			valid_texture_path(map, SO);
// 		else if (ft_strcmp(map->identifier[0], "EA") == 0)
// 			valid_texture_path(map, EA);
// 		else if (ft_strcmp(map->identifier[0], "WE") == 0)
// 			valid_texture_path(map, WE);
// 		else if (ft_strcmp(map->identifier[0], "C") == 0)
// 			valid_color(map, C);
// 		else if (ft_strcmp(map->identifier[0], "F") == 0)
// 			valid_color(map, F);
// 		else
// 			exit_cleanup(map, ERR_TEXTURE, ERR_MISSING_ID);
// 	}
// 	return ;
// }

static void	valid_identifier(t_map *map, char *trmd_line)
{
	if (map->identifier[0] == NULL)
	{
		free_str(&trmd_line);
		exit_cleanup(map, ERR_TEXTURE, ERR_MISS_ID_MSG);
	}
	if (ft_strcmp(map->identifier[0], "NO") == 0)
		valid_texture_path(map, NO);
	else if (ft_strcmp(map->identifier[0], "SO") == 0)
		valid_texture_path(map, SO);
	else if (ft_strcmp(map->identifier[0], "WE") == 0)
		valid_texture_path(map, WE);
	else if (ft_strcmp(map->identifier[0], "EA") == 0)
		valid_texture_path(map, EA);
	else if (ft_strcmp(map->identifier[0], "F") == 0)
		valid_color(map, F);
	else if (ft_strcmp(map->identifier[0], "C") == 0)
		valid_color(map, C);
	else
		exit_cleanup(map, ERR_TEXTURE, ERR_MISS_ID_MSG);
	return ;
}

void	parse_map_config(t_map *map)
{
	char	*trmd_line;
	size_t	i;
	size_t	len;

	trmd_line = ft_strtrim(map->read_line, " \n\t\v");
	free_str(&map->read_line);
	i = 0;
	len = ft_strlen(trmd_line);
	while (trmd_line[i])
	{
		if (ft_strchr(" \t", trmd_line[i]) != NULL)
		{
			map->identifier[0] = ft_substr(trmd_line, 0, i);
			map->identifier[1] = ft_substr(trmd_line, i, len - i);
			break ;
		}
		i++;
	}
	free_str(&trmd_line);
	if (!map->identifier[0] || !map->identifier[1])
		exit_cleanup(map, ERR_PERR, ERR_MAP_ID_MSG);
	valid_identifier(map, trmd_line);
	free_str(&map->identifier[0]);
	free_str(&map->identifier[1]);
	return ;
}

// void	parse_map_identifiers(t_map *map)
// {
// 	char	*trmd_line;
//
// 	trmd_line = ft_strtrim(map->read_line, " \n\t\v");
// 	free_str(&map->read_line);
// 	map->identifier = ft_split(trmd_line, ' ');
// 	// TODO: if we want to accept file paths with spaces we'll have to split only in 2
// 	// i.e. we only consider first sequence of spaces to divide in 2 strings
// 	if (!map->identifier)
// 	{
// 		free_str(&trmd_line);
// 		exit_cleanup(map, ERR_PERR, ERR_MAP_ID_MSG);
// 	}
// 	valid_identifier(map, trmd_line);
// 	free_arr(&map->identifier);
// 	free_str(&trmd_line);
// 	return ;
// }
