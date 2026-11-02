/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megi <megi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 16:47:08 by megi              #+#    #+#             */
/*   Updated: 2026/08/30 18:00:54 by megi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include <stdio.h>
#include <unistd.h>
#include "../library/libft/libft.h"

typedef enum e_monitor {
    CONFIG,
    MAP
}	t_monitor;

typedef enum e_player {
	N,
	S,
	W,
	E
} t_player;

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
    ERR_RGB_AV2,
	ERR_PLAYER,
	ERR_MAP_SPACE,
	ERR_MAP_NOT_CLOSED
}   t_error_type;

typedef struct s_line_node
{
	char				*line;
	struct s_line_node	*next;
}	t_line_node;

typedef struct s_player_data
{
	char	dir;
	int		gamer_x;
	int		gamer_y;
	int		one_gamer_per_map;
}	t_player_data;

typedef struct s_parsing
{
	char	*path[4];
	int		rgb_av[6];
	char	**identifier;
}	t_parsing;

typedef struct s_map {
	char            **grid;
	int		        rows;
	int		        space;
	t_monitor	    mode;
	t_line_node 	*lines_head;
	t_line_node 	*lines_tail;
	t_player_data	player;
	t_parsing	    parsing;
}   t_map;

t_monitor monitor(t_map *map, char *file);

t_results valid_identifier(t_map *map, char *str);
t_results valid_color(t_map *map, char *str);

int     parseconfig(t_map *map, char *line);
int     readthemap(t_map *map, char *line);
int     texture_errors(int error_type);
int     empty_flag(char *l);
int     map_errors(int error_type);
void    check_walls(t_map *map);

#endif
