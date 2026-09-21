/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ne <ncruz-ne@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 23:08:05 by megi              #+#    #+#             */
/*   Updated: 2026/09/21 22:55:12 by ncruz-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3D.h"

int	texture_errors(int error_type)
{
	char	*err_msg;

	ft_putendl_fd("Error: ", STDERR_FILENO);
	if (error_type == ERR_IDENTIFIER)
		err_msg = "Use one of these identifiers: NO, SO, WE, EA with path && F, C";
	else if (error_type == ERR_RGB_AV)
		err_msg = "There should be 3 (three) RGB arguments!";
	else if (error_type == ERR_RGB_AV2)
		err_msg = "RGB args should be inside [0, 255] diaposon!";
	else
		return (0);
	ft_putendl_fd(err_msg, STDERR_FILENO);
	return (0);
}

int	map_errors(int error_type)
{
	char	*err_msg;

	ft_putendl_fd("Error: ", STDERR_FILENO);
	if (error_type == ERR_PLAYER)
	{
		err_msg = "Use one of those to identify the player 'N', 'S', 'W', 'E'";
		//exit (1);
	}
	if (error_type == ERR_MAP_SPACE)
	{
		err_msg = "Cannot have 2 or more consecutive spaces";
		//exit (1);
	}
	ft_putendl_fd(err_msg, STDERR_FILENO);
	return (0);
}
