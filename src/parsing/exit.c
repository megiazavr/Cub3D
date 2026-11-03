/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megi <megi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 23:08:05 by megi              #+#    #+#             */
/*   Updated: 2026/11/03 14:35:15 by megi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3D.h"

static char *category_msg(t_err_type type)
{
    if (type == ERR_ARGS)
        return (ERR_ARGS_MSG);
    if (type == ERR_TEXTURE)
        return (ERR_TEXTURE_MSG);
    if (type == ERR_MAP)
        return (ERR_MAP_MSG);
    return ("");
}

void exit_cleanup(t_map *map, t_err_type type, char *detail_msg)
{
    char *header;

    if (type == ERR_PERR)
    {
        write(2, "Error\n", 6);
        perror(detail_msg);
    }
    else if (type != VALID)
    {
        header = category_msg(type);
        write(2, "Error\n", 6);
        write(2, header, ft_strlen(header));
        write(2, detail_msg, ft_strlen(detail_msg));
        write(2, "\n", 1);
    }
    free_split(map->identifier);
    map->identifier = NULL;
    if (type == VALID)
        exit (0);
    exit (1);
}