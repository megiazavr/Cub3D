/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ne <ncruz-ne@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 14:40:59 by megi              #+#    #+#             */
/*   Updated: 2026/11/04 00:10:16 by ncruz-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3D.h"
#include <cstdlib>

// static t_id_res	valid_cardinal_pts(t_map *map)
// {
// 	if (ft_strcmp(map->identifier[0], "NO") == 0)
// 	{
// 		map->n_s_e_w_paths[NO] = map->identifier[1];
// 		return (TEXTURE);
// 	}
// 	else if (ft_strcmp(map->identifier[0], "SO") == 0)
// 	{
// 		map->n_s_e_w_paths[SO] = map->identifier[1];
// 		return (TEXTURE);
// 	}
// 	else if (ft_strcmp(map->identifier[0], "EA") == 0)
// 	{
// 		map->n_s_e_w_paths[EA] = map->identifier[1];
// 		return (TEXTURE);
// 	}
// 	else if (ft_strcmp(map->identifier[0], "WE") == 0)
// 	{
// 		map->n_s_e_w_paths[WE] = map->identifier[1];
// 		return (TEXTURE);
// 	}
// 	texture_errors(ERR_IDENTIFIER);
// 	return (ERROR);
// }

// static t_id_res	valid_cardinal_pts(t_map *map)
// {
// 	if (ft_strcmp(map->identifier[0], "NO") == 0)
// 	{
// 		map->n_s_e_w_paths[NO] = map->identifier[1];
// 		return (TEXTURE);
// 	}
// 	else if (ft_strcmp(map->identifier[0], "SO") == 0)
// 	{
// 		map->n_s_e_w_paths[SO] = map->identifier[1];
// 		return (TEXTURE);
// 	}
// 	else if (ft_strcmp(map->identifier[0], "EA") == 0)
// 	{
// 		map->n_s_e_w_paths[EA] = map->identifier[1];
// 		return (TEXTURE);
// 	}
// 	else if (ft_strcmp(map->identifier[0], "WE") == 0)
// 	{
// 		map->n_s_e_w_paths[WE] = map->identifier[1];
// 		return (TEXTURE);
// 	}
// 	texture_errors(ERR_IDENTIFIER);
// 	return (ERROR);
// }

// static t_id_res	valid_identifier(t_map *map, char *str)
// {
// 	// map->identifier = ft_split(str, ' ');
// 	// if (map->identifier[0] == NULL)
// 		// return (texture_errors(ERR_IDENTIFIER), ERROR);
// 	if (ft_strcmp(map->identifier[0], "C") == 0
// 		|| ft_strcmp(map->identifier[0], "F") == 0)
// 		return (COLOR);
// 	if (map->identifier[1] == NULL)
// 		return (texture_errors(ERR_IDENTIFIER), ERROR);
// 	return (valid_cardinal_pts(map));
// 	// TODO: delete commented code below if norm adjustments are good
// 	// if (ft_strcmp(map->identifier[0], "NO") == 0)
// 	// {
// 	// 	map->path[NO] = map->identifier[1];
// 	// 	return (TEXTURE);
// 	// }
// 	// else if (ft_strcmp(map->identifier[0], "SO") == 0)
// 	// {
// 	// 	map->path[SO] = map->identifier[1];
// 	// 	return (TEXTURE);
// 	// }
// 	// else if (ft_strcmp(map->identifier[0], "WE") == 0)
// 	// {
// 	// 	map->path[WE] = map->identifier[1];
// 	// 	return (TEXTURE);
// 	// }
// 	// else if (ft_strcmp(map->identifier[0], "EA") == 0)
// 	// {
// 	// 	map->path[EA] = map->identifier[1];
// 	// 	return (TEXTURE);
// 	// }
// 	// return (texture_errors(ERR_IDENTIFIER), ERROR);
// }

static void	parse_rgb(t_map *map, char **rgb, t_map_ids c_or_f)
{
	int	r;
	int	g;
	int	b;
	r = ft_atoi(rgb[0]);
	g = ft_atoi(rgb[1]);
	b = ft_atoi(rgb[2]);
	/* TODO: why create the vars above instead of just doing
	i = 0;
	while (i < 6) {
	map->rgb_c_f[c_or_f + i] = ft_atoi(rgb[i]) } ? */
	free_split(rgb);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		exit_cleanup(map, ERR_TEXTURE, ERR_RGB_AV2_MSG);
		// return (texture_errors(ERR_RGB_AV2), ERROR);
	if (map->rgb_c_f[c_or_f] == -1 && map->rgb_c_f[c_or_f - 2] == -1
		&& map->rgb_c_f[c_or_f - 4] == -1)
		map->rgb_c_f[c_or_f] = (r << 16) | (g << 8) | b;
	// TODO: should there be a validation step of the above?
	else
		exit_cleanup(map, ERR_TEXTURE, ERR_RGB_AV_MSG);
	// return (COLOR);
	return ;
}
/* TODO: improve on removing repeating code - free_split() + exit_cleanup() */
static void	valid_color(t_map *map, t_map_ids id)
{
	char	**rgb;

	rgb = ft_split(map->identifier[1], ',');
	if (rgb && rgb[3] == NULL && rgb[0] && rgb[1] && rgb[2])
		parse_rgb(map, rgb, id);
	else
	{
		free_split(rgb);
		exit_cleanup(map, ERR_TEXTURE, ERR_RGB_AV_MSG);
	}
		// return (texture_errors(ERR_RGB_AV), ERROR);
	return ;
}
static void	valid_texture_path(t_map *map, t_map_ids id)
{
	if (map->identifier[1] && map->n_s_e_w_paths[id] == NULL)
		map->n_s_e_w_paths[id] = map->identifier[1];
	else
		exit_cleanup(map, ERR_TEXTURE, ERR_MISS_DUPE_PATH);
	return ;
}
/* TODO: add verification of open() of file in path at earliest stage possible */

static void	valid_identifier(t_map *map)
{
	if (map->identifier[0] && map->identifier[1])
	{
		if (ft_strcmp(map->identifier[0], "NO") == 0)
			valid_texture_path(map, NO);
		else if (ft_strcmp(map->identifier[0], "SO") == 0)
			valid_texture_path(map, SO);
		else if (ft_strcmp(map->identifier[0], "EA") == 0)
			valid_texture_path(map, EA);
		else if (ft_strcmp(map->identifier[0], "WE") == 0)
			valid_texture_path(map, WE);
		else if (ft_strcmp(map->identifier[0], "C") == 0)
			valid_color(map, C);
		else if (ft_strcmp(map->identifier[0], "F") == 0)
			valid_color(map, F);
		else
			exit_cleanup(map, ERR_TEXTURE, ERR_MISSING_ID);
	}
	return ;
}

void	parse_map_identifiers(t_map *map, char *line)
{
	char	*trmd_line;

	trmd_line = ft_strtrim(line, " \n\t\v");
	map->identifier = ft_split(trmd_line, ' ');
	free(trmd_line);
	if (!map->identifier)
		exit_cleanup(map, ERR_PERR, ERR_MAP_ID);
	valid_identifier(map);
	// return (ERROR);
	return ;
}
