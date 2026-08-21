/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megi <megi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 16:47:08 by megi              #+#    #+#             */
/*   Updated: 2026/08/21 23:12:46 by megi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include <stdio.h>
#include <unistd.h>
#include "../library/libft/libft.h"

typedef enum e_maps_data {
    NO,
    SO,
    WE,
    EA,
    C,
    F
}   t_identifiers;

typedef enum e_ident_results {
    TEXTURE,
    COLOR,
    ERROR
}   t_results;

typedef enum e_errors {
    ERR_IDENTIFIER,
    ERR_RGB_AV,
    ERR_RGB_AV2
}   t_error_type;

typedef struct s_map {
    char    *path[4];
    int     rgb_av[6];
}   t_map;

int readthemap(t_map *map, char *file);
t_results valid_identifier(t_map *map, char *str);
t_results valid_color(t_map *map, char *str);
int errors(int error_type);

#endif
