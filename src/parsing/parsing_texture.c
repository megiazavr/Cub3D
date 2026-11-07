/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ne <ncruz-ne@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 14:40:59 by megi              #+#    #+#             */
/*   Updated: 2026/11/07 15:02:19 by ncruz-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3D.h" // bring in t_map, t_map_ids, prototypes, error enums

static t_id_res	rgb_validator(char **rgb)
{
	int	i;
	int	j;

	i = 0;
	while (rgb[i] != NULL)
	{
		j = 0;
		while (rgb[i][j] >= '0' && rgb[i][j] <= '9')
			j++;
		if (rgb[i][j] != '\0' || (rgb[i][j] == '\0' && j < 1))
			return (ERROR);
		i++;
	}
	return (COLOR);
}

// TODO: do we need this function? we can just use ft_strtrim()
// static char	*skip_to_rgb(char *str)
// {
// 	while (*str && *str != ' ' && *str != '\t')
// 		str++;
// 	while (*str == ' ' || *str == '\t')
// 		str++;
// 	return (str);
// }

// static void parse_rgb(t_map *map, char **rgb, t_map_ids c_or_f)
// {
// 	int r;
// 	int g;
// 	int b;
// 	r = ft_atoi(rgb[0]);
// 	g = ft_atoi(rgb[1]);
// 	b = ft_atoi(rgb[2]);
// 	free_split(rgb);
// 	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
// 		exit_cleanup(map, ERR_TEXTURE, ERR_RGB_AV2_MSG);
// 	if (map->rgb_c_f[c_or_f] == -1 && map->rgb_c_f[c_or_f - 2] == -1
// 		&& map->rgb_c_f[c_or_f - 4] == -1)
// 		map->rgb_c_f[c_or_f] = (r << 16) | (g << 8) | b;
// 	else
// 		exit_cleanup(map, ERR_TEXTURE, ERR_RGB_AV_MSG);
// 	char	c_or_f_char;
// 	if (c_or_f == C)
// 		c_or_f_char = 'C';
// 	else if (c_or_f == F)
// 		c_or_f_char = 'F';
// 	printf(">> Results after parse_rgb() for identifier %c:\n", c_or_f_char);
// 	rgb_print(map);
// 	return ;
// }

static void	parse_rgb(t_map *map, char **rgb, t_map_ids c_or_f, char *trmd_line)
{
	int	r;
	int	g;
	int	b;

	if (rgb_validator(rgb) != COLOR || rgb[3] != NULL)
	{
		free_arr(rgb);
		free_and_null(&trmd_line);
		exit_cleanup(map, ERR_TEXTURE, ERR_RGB_AV_MSG);
	}
	r = ft_atoi(rgb[0]);
	g = ft_atoi(rgb[1]);
	b = ft_atoi(rgb[2]);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
	{
		free_arr(rgb);
		free_and_null(&trmd_line);
		exit_cleanup(map, ERR_TEXTURE, ERR_RGB_AV2_MSG);
	}
	free_arr(rgb);
	if (map->rgb_f_c[c_or_f - 4] != -1)
	{
		free_and_null(&trmd_line);
		exit_cleanup(map, ERR_TEXTURE, ERR_RGB_AV_MSG);
	}
	map->rgb_f_c[c_or_f - 4] = (r << 16) | (g << 8) | b;
	rgb_print(map, c_or_f);
	return ;
}

// static void valid_color(t_map *map, t_map_ids id)
// {
// 	char **rgb;
//
// 	rgb = ft_split(map->identifier[1], ',');
// 	if (rgb && rgb[3] == NULL && rgb[0] && rgb[1] && rgb[2])
// 		parse_rgb(map, rgb, id);
// 	else
// 	{
// 		free_split(rgb);
// 		exit_cleanup(map, ERR_TEXTURE, ERR_RGB_AV_MSG);
// 	}
// 	return ;
// }

static void	valid_color(t_map *map, t_map_ids id, char *trmd_line)
{
	char	*rgb_str;
	char	**rgb;

	if ((int)id != map->next_identifier)
	{
		free_and_null(&trmd_line);
		exit_cleanup(map, ERR_TEXTURE, ERR_ORDER_MSG);
	}
	map->next_identifier++;
	// rgb = ft_split(skip_to_rgb(trmd_line), ',');
	rgb_str = ft_strtrim(map->identifier[1], " \t");
	rgb = ft_split(rgb_str, ',');
	free_and_null(&rgb_str);
	parse_rgb(map, rgb, id, trmd_line);
	return ;
}

static void	valid_texture_path(t_map *map, t_map_ids id, char *trmd_line)
{
	if ((int)id != map->next_identifier)
	{
		free_and_null(&trmd_line);
		exit_cleanup(map, ERR_TEXTURE, ERR_ORDER_MSG);
	}
	map->next_identifier++;
	if (map->identifier[1] && map->n_s_w_e_paths[id] == NULL)
	{
		map->n_s_w_e_paths[id] = ft_strdup(map->identifier[1]);
		if (!map->n_s_w_e_paths[id])
		{
			free_and_null(&trmd_line);
			exit_cleanup(map, ERR_PERR, ERR_MEM_PATH_MSG);
		}
	}
	else
	{
		free_and_null(&trmd_line);
		exit_cleanup(map, ERR_TEXTURE, ERR_DUPE_PATH_MSG);
	}
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
		free_and_null(&trmd_line);
		exit_cleanup(map, ERR_TEXTURE, ERR_MISS_ID_MSG);
	}
	if (ft_strcmp(map->identifier[0], "NO") == 0)
		valid_texture_path(map, NO, trmd_line);
	else if (ft_strcmp(map->identifier[0], "SO") == 0)
		valid_texture_path(map, SO, trmd_line);
	else if (ft_strcmp(map->identifier[0], "WE") == 0)
		valid_texture_path(map, WE, trmd_line);
	else if (ft_strcmp(map->identifier[0], "EA") == 0)
		valid_texture_path(map, EA, trmd_line);
	else if (ft_strcmp(map->identifier[0], "F") == 0)
		valid_color(map, F, trmd_line);
	else if (ft_strcmp(map->identifier[0], "C") == 0)
		valid_color(map, C, trmd_line);
	else
	{
		free_and_null(&trmd_line);
		exit_cleanup(map, ERR_TEXTURE, ERR_MISS_ID_MSG);
	}
	return ;
}

void	parse_map_identifiers(t_map *map)
{
	char	*trmd_line;

	trmd_line = ft_strtrim(map->read_line, " \n\t\v");
	free_and_null(&map->read_line);
	map->identifier = ft_split(trmd_line, ' ');
	// TODO: if we want to accept file paths with spaces we'll have to split only in 2
	// i.e. we wonly consider first sequence of spaces to divide in 2 strings
	if (!map->identifier)
	{
		free_and_null(&trmd_line);
		exit_cleanup(map, ERR_PERR, ERR_MAP_ID_MSG);
	}
	valid_identifier(map, trmd_line);
	free_arr(map->identifier);
	map->identifier = NULL;
	free_and_null(&trmd_line);
	return ;
}
