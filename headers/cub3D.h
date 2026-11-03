/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megi <megi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 16:47:08 by megi              #+#    #+#             */
/*   Updated: 2026/11/03 17:37:53 by megi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include <stdio.h>
#include <unistd.h>
#include "../library/libft/libft.h"
#include "cub3D_err.h"
#include <stdbool.h>

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
	ERROR,
    TEXTURE,
    COLOR,
}   t_id_res;

typedef struct s_line_node
{
	char				*line;
	struct s_line_node	*next;
}	t_line_node;

typedef struct s_lines
{
	t_line_node	*head;
	t_line_node	*tail;
}	t_lines;

typedef struct s_map {
	char            *file;
	char            **grid;
	int		        rows;
	int		        space;
	t_lines			lines;
	char			player_dir;
	int				player_x;
	int				player_y;
	int				one_player_per_map;
	char			**identifier;
	char			*n_s_e_w_paths[4];
	int				rgb_c_f[6];
}   t_map;

t_monitor monitor(t_map *map);

t_id_res valid_identifier(t_map *map, char *str);
t_id_res valid_color(t_map *map, char *str);

int     parseconfig(t_map *map, char *line);
int     readthemap(t_map *map, char *line);
void    build_grid(t_map *map);
bool     empty_flag(char *l);
void    check_walls(t_map *map);
void    exit_cleanup(t_map *map, t_err_type type, char *detail_msg);
void    free_split(char **arr);

#endif