/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D_err.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megi <megi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 20:16:05 by ncruz-ne          #+#    #+#             */
/*   Updated: 2026/11/12 15:53:08 by megi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_ERR_H
# define CUB3D_ERR_H

typedef enum e_err_type
{
	VALID,
	ERR_ARGS,
	ERR_TEXTURE,
	ERR_MAP,
	ERR_PERR
}	t_err_type;

// TODO: Review error msgs that aren't used to delete from header
/* Arguments parsing error messages */
# define ERR_ARGS_MSG		"Arguments parsing:"
# define ERR_NR_ARGS		"Invalid number of arguments"
# define ERR_ARGS_FILE_MSG	"File missing .cub extension"

/* Texture parsing error messages */
# define ERR_TEXTURE_MSG	"Texture parsing:"
# define ERR_IDENTIFIER_MSG	"Use only these identifiers: NO, SO, WE, EA with \
file path and F, C with R,G,B colors"
# define ERR_RGB_AV_MSG		"Colors for F and C must be defined only once and \
must be strictly formatted as 'R,G,B' e.g: 0,100,255"
# define ERR_RGB_AV2_MSG	"R,G,B colors must be in range [0, 255]"
# define ERR_MISS_ID_MSG	"Map file must include identifiers at beginning of line \
(not counting spaces): NO, SO, WE, EA, F, C"
# define ERR_MISS_PATH_MSG	"Each map texture identifiers must be followed by \
its file path"
# define ERR_DUPE_PATH_MSG	"Each map texture identifier must appear only once, \
be followed by its file path and there can only be spaces between them"
# define ERR_ORDER_MSG		"Identifiers must appear in this exact order: \
NO, SO, WE, EA, F, C"

/* Map parsing error messages */
# define ERR_MAP_MSG		"Map parsing:"
# define ERR_PLAYER_MSG		"Use 'N', 'S', 'W', or 'E' to set orientation \
player faces"
# define ERR_MAP_SPACE_MSG	"Can't have 2 or more consecutive spaces"
# define ERR_MAP_NOT_CLOSED_MSG	"The map must be closed/surrounded by walls"
# define ERR_MAP_IS_EMPTY "The map is empty. Add '1' for walls, '0' for spaces \
and one of: N, S, W, E for the player direction."
# define ERR_MAP_TOO_BIG_MSG	"Map is too large (max 200 rows / 200 columns)"

/* Errors messages with perror() */
# define ERR_OPEN_MSG		"Opening .cub file failed"
# define ERR_MAP_ID_MSG		"map->identifier is NULL"
# define ERR_MEM_PATH_MSG	"malloc() for map->n_s_w_e_paths[id] failed"
# define ERR_MEM_MATRIX_MSG	"malloc() for map->matrix failed"

#endif