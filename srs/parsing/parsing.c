/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megi <megi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 16:46:10 by megi              #+#    #+#             */
/*   Updated: 2026/08/21 23:10:11 by megi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3D.h"

//readthemeap is splitting and getting 1 massive of [identifier and the path]

int readthemap(t_map *map, char *file) {
	char *line;
	int fd;
	t_results res;
	fd = open(file, O_RDONLY);
	
	if (fd == -1)
		return (perror("OOPS: "), 0);
    line = get_next_line(fd);
    while (line != NULL) {
	    res = valid_identifier(map, line);
    	if (res == COLOR)
        	res = valid_color(map, line);
    	if (res == ERROR)
			return(errors(ERR_IDENTIFIER), 1);
		line = get_next_line(fd);
    }
	return (0);
}

t_results valid_identifier(t_map *map, char *str) {
    char **identifier = ft_split(str, ' ');
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
	else
		return (COLOR);
    return (ERROR);
}

static t_results parse_c(t_map *map, char **rgb)
{
    int r;
    int g;
    int b;

    if (rgb[3] != NULL)
        return (errors(ERR_RGB_AV), ERROR);
    if (rgb[0] == NULL || rgb[1] == NULL || rgb[2] == NULL)
        return (errors(ERR_RGB_AV2), ERROR);
    r = ft_atoi(rgb[0]);
    g = ft_atoi(rgb[1]);
    b = ft_atoi(rgb[2]);
    if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
        return (errors(ERR_RGB_AV2), ERROR);
    map->rgb_av[C] = (r << 16) | (g << 8) | b;
    return (COLOR);
}

static t_results parse_f(t_map *map, char **rgb)
{
    int r;
    int g;
    int b;

    if (rgb[3] != NULL)
        return (errors(ERR_RGB_AV), ERROR);
    if (rgb[0] == NULL || rgb[1] == NULL || rgb[2] == NULL)
        return (errors(ERR_RGB_AV2), ERROR);
    r = ft_atoi(rgb[0]);
    g = ft_atoi(rgb[1]);
    b = ft_atoi(rgb[2]);
    if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
        return (errors(ERR_RGB_AV2), ERROR);
    map->rgb_av[F] = (r << 16) | (g << 8) | b;
    return (COLOR);
}

t_results valid_color(t_map *map, char *str)
{
    char **identifier = ft_split(str, ' ');
    char **rgb = ft_split(identifier[1], ',');

    if (ft_strcmp(identifier[0], "C") == 0)
        return (parse_c(map, rgb));
    else if (ft_strcmp(identifier[0], "F") == 0)
        return (parse_f(map, rgb));
    return (ERROR);
}

