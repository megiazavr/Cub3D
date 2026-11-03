/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D_err.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ne <ncruz-ne@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 20:16:05 by ncruz-ne          #+#    #+#             */
/*   Updated: 2026/11/03 00:12:31 by ncruz-ne         ###   ########.fr       */
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

/* Arguments parsing error messages */
# define ERR_ARGS_MSG		"Arguments parsing:\n"
# define ERR_NR_ARGS		"Invalid number of arguments"
# define ERR_ARGS_FILE_MSG	"File missing .cub extension"

/* Texture parsing error messages */
# define ERR_TEXTURE_MSG	"Texture parsing:\n"
# define ERR_IDENTIFIER_MSG	"Use only these identifiers: NO, SO, WE, EA with \
file path and F, C with R,G,B colors"
# define ERR_RGB_AV_MSG		"Colors must be strictly formatted as 'R,G,B' \
e.g: 0,100,255"
# define ERR_RGB_AV2_MSG	"R,G,B colors must be in range [0, 255]"
# define ERR_MISSING_ID		"Map file must include identifiers at beginning of line \
(not counting spaces): NO, SO, WE, EA, F, C"
# define ERR_MISSING_PATH	"Each map texture identifiers must be followed by \
its file path"

/* Map parsing error messages */
# define ERR_MAP_MSG		"Map parsing:\n"
# define ERR_PLAYER_MSG		"Use 'N', 'S', 'W', or 'E' to set orientation \
player faces"
# define ERR_MAP_SPACE_MSG	"Can't have 2 or more consecutive spaces"

/* Errors messages with perror() */
# define ERR_OPEN_MSG		"Opening .cub file failed"
# define ERR_MAP_ID			"map->identifier is NULL"

#endif