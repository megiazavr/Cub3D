/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ne <ncruz-ne@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 16:47:08 by megi              #+#    #+#             */
/*   Updated: 2026/11/03 22:24:06 by ncruz-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stdbool.h>
# include "../libs/libft/libft.h"
# include "cub3D_err.h"

typedef enum e_monitor
{
	CONFIG,
	MAP
}	t_monitor;

typedef enum e_player
{
	N,
	S,
	W,
	E
}	t_player;

typedef enum e_map_ids
{
	NO,
	SO,
	EA,
	WE,
	C,
	F	
}	t_map_ids;

typedef enum e_id_res
{
	TEXTURE,
	COLOR,
	ERROR
}	t_id_res;

// typedef enum e_err_type
// {
// 	VALID,
// 	ERR_IDENTIFIER,
// 	ERR_RGB_AV,
// 	ERR_RGB_AV2,
// 	ERR_MAP_,
// 	ERR_PLAYER,
// 	ERR_MAP_SPACE
// }	t_err_type;

typedef struct s_map
{
	char	*file;
	char	*n_s_e_w_paths[4];
	int		rgb_c_f[6];
	char	**identifier; // TODO: move to another struct for temp validations?
	int		one_player_per_map;
	char	player;
}	t_map;

t_monitor	monitor(t_map *map);

t_id_res	parse_map_identifiers(t_map *map, char *line);
// t_id_res	valid_color(t_map *map, char *str);

int			parseconfig(t_map *map, char *line);
int			readthemap(t_map *map, char *line);
void 		free_split(char **arr);
bool		empty_flag(char *l);

void		exit_cleanup(t_map *map, t_err_type err, char *err_msg);

#endif