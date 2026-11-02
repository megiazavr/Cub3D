/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D_err.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ne <ncruz-ne@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 20:16:05 by ncruz-ne          #+#    #+#             */
/*   Updated: 2026/11/02 22:33:32 by ncruz-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_ERR_H
# define CUB3D_ERR_H

typedef enum e_err_type
{
	VALID,
	ERR_TEXTURE,
	ERR_MAP,
}	t_err_type;

/* Texture parsing error messages */
# define ERR_TEXTURE_MSG	"Texture parsing error: "
# define ERR_IDENTIFIER_MSG	"Use only these identifiers: NO, SO, WE, EA with \
path && F, C"
# define ERR_RGB_AV_MSG		"Colors must be strictly formatted as 'R,G,B'. \
E.g: 0,100,255"
# define ERR_RGB_AV2_MSG	"R,G,B colors must be in range [0, 255]"

/* Map parsing error messages */
# define ERR_MAP_MSG		"Map parsing error: "
# define ERR_PLAYER_MSG		"Use 'N', 'S', 'W', or 'E' to set orientation \
player faces"
# define ERR_MAP_SPACE_MSG	"Can't have 2 or more consecutive spaces"

#endif