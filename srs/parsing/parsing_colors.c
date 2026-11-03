/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_colors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megi <megi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 14:38:25 by megi              #+#    #+#             */
/*   Updated: 2026/11/02 18:12:46 by megi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3D.h"

static char *only_digits(char *str)
{
    int     i;

    i = 0;
    while (str[i] == ' ' || str[i] == '\t')
        i++;
    while (str[i] != '\0')
    {
        if (str[i] >= '0' && str[i] <= '9')
            i++;
        else if (str[i] == ' ' || str[i] == '\t')
        {
            while (str[i] == ' ' || str[i] == '\t')
                i++;
            if (str[i] != '\0')
                return (NULL);
        }
        else
            return (NULL);
    }
    return (str); // so it means that i have only digits here and all spaces are skipped and i return str with rgb color
}

static char *skip_to_rgb(char *str)
{
    while (*str == ' ' || *str == '\t')
        str++;
    while (*str && *str != ' ' && *str != '\t')
        str++;
    while (*str == ' ' || *str == '\t')
        str++;
    return (str);
}

static t_id_res parse_c(t_map *map, char **rgb)
{
    int r;
    int g;
    int b;

    if (rgb[0] == NULL || rgb[1] == NULL || rgb[2] == NULL || rgb[3] != NULL)
        exit_cleanup(map, ERR_TEXTURE, ERR_RGB_AV_MSG);
    if (!only_digits(rgb[0]) || !only_digits(rgb[1]) || !only_digits(rgb[2]))
        exit_cleanup(map, ERR_TEXTURE, ERR_RGB_AV2_MSG);
    r = ft_atoi(rgb[0]);
    g = ft_atoi(rgb[1]);
    b = ft_atoi(rgb[2]);
    if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
        exit_cleanup(map, ERR_TEXTURE, ERR_RGB_AV2_MSG);
    map->rgb_c_f[C] = (r << 16) | (g << 8) | b;
    free_split(rgb);
    return (COLOR);
}

static t_id_res parse_f(t_map *map, char **rgb)
{
    int r;
    int g;
    int b;

    if (rgb[0] == NULL || rgb[1] == NULL || rgb[2] == NULL || rgb[3] != NULL)
        exit_cleanup(map, ERR_TEXTURE, ERR_RGB_AV_MSG);
    if (!only_digits(rgb[0]) || !only_digits(rgb[1]) || !only_digits(rgb[2]))
        exit_cleanup(map, ERR_TEXTURE, ERR_RGB_AV2_MSG);
    r = ft_atoi(rgb[0]);
    g = ft_atoi(rgb[1]);
    b = ft_atoi(rgb[2]);
    if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
        exit_cleanup(map, ERR_TEXTURE, ERR_RGB_AV2_MSG);
    map->rgb_c_f[F] = (r << 16) | (g << 8) | b;
    free_split(rgb);
    return (COLOR);
}

t_id_res valid_color(t_map *map, char *str)
{
    char **rgb;
    char *rgb_str;

    rgb_str = skip_to_rgb(str);
    if (*rgb_str == '\0')
        exit_cleanup(map, ERR_TEXTURE, ERR_IDENTIFIER_MSG);
    rgb = ft_split(rgb_str, ',');
    if (ft_strcmp(map->identifier[0], "C") == 0)
        return (parse_c(map, rgb));
    else if (ft_strcmp(map->identifier[0], "F") == 0)
        return (parse_f(map, rgb));
    exit_cleanup(map, ERR_TEXTURE, ERR_IDENTIFIER_MSG);
    return (ERROR);
}
