/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_colors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megi <megi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 14:38:25 by megi              #+#    #+#             */
/*   Updated: 2026/08/24 18:28:05 by megi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3D.h"

static t_results parse_c(t_map *map, char **rgb)
{
    int r;
    int g;
    int b;

    if (rgb[3] != NULL)
        return (texture_errors(ERR_RGB_AV), ERROR);
    if (rgb[0] == NULL || rgb[1] == NULL || rgb[2] == NULL)
        return (texture_errors(ERR_RGB_AV), ERROR);
    r = ft_atoi(rgb[0]);
    g = ft_atoi(rgb[1]);
    b = ft_atoi(rgb[2]);
    if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
        return (texture_errors(ERR_RGB_AV2), ERROR);
    map->rgb_av[C] = (r << 16) | (g << 8) | b;
    return (COLOR);
}

static t_results parse_f(t_map *map, char **rgb)
{
    int r;
    int g;
    int b;

    if (rgb[3] != NULL)
        return (texture_errors(ERR_RGB_AV), ERROR);
    if (rgb[0] == NULL || rgb[1] == NULL || rgb[2] == NULL)
        return (texture_errors(ERR_RGB_AV), ERROR);
    r = ft_atoi(rgb[0]);
    g = ft_atoi(rgb[1]);
    b = ft_atoi(rgb[2]);
    if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
        return (texture_errors(ERR_RGB_AV2), ERROR);
    map->rgb_av[F] = (r << 16) | (g << 8) | b;
    return (COLOR);
}

t_results valid_color(t_map *map, char *str)
{
    char **rgb;
    
    map->identifier= ft_split(str, ' ');
    if (map->identifier[0] == NULL || map->identifier[1] == NULL)
        return (texture_errors(ERR_IDENTIFIER), ERROR);
    rgb = ft_split(map->identifier[1], ',');
    if (ft_strcmp(map->identifier[0], "C") == 0)
        return (parse_c(map, rgb));
    else if (ft_strcmp(map->identifier[0], "F") == 0)
        return (parse_f(map, rgb));
    return (texture_errors(ERR_IDENTIFIER), ERROR);
}
