/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ne <ncruz-ne@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 16:47:08 by megi              #+#    #+#             */
/*   Updated: 2026/09/03 20:37:24 by ncruz-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "../libs/libft/libft.h"

typedef enum e_monitor {
	CONFIG,
	MAP
}	t_monitor;

typedef enum e_player {
	N,
	S,
	W,
	E
}	t_player;

typedef enum e_maps_data {
	NO,
	SO,
	WE,
	EA,
	C,
	F	
}	t_identifiers;

typedef enum e_ident_results {
	TEXTURE,
	COLOR,
	ERROR
}	t_results;

typedef enum e_errors {
	ERR_IDENTIFIER,
	ERR_RGB_AV,
	ERR_RGB_AV2,
	ERR_PLAYER,
	ERR_MAP_SPACE
}	t_error_type;

typedef struct s_map {
    char	*path[4];
    int		rgb_av[6];
	char	**identifier;
	int		one_player_per_map;
	char	player;
}	t_map;

t_monitor	monitor(t_map *map, char *file);

t_results	valid_identifier(t_map *map, char *str);
t_results	valid_color(t_map *map, char *str);

int			parseconfig(t_map *map, char *line);
int			readthemap(t_map *map, char *line);
int			texture_errors(int error_type);
int			empty_flag(char *l);
int			map_errors(int error_type);


#endif