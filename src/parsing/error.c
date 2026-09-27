/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ne <ncruz-ne@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 23:08:05 by megi              #+#    #+#             */
/*   Updated: 2026/09/27 16:48:44 by ncruz-ne         ###   ########.fr       */
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
		err_msg = "Colours must be strictly formatted as 'R,G,B'. E.g: 0,100,255";
	else if (error_type == ERR_RGB_AV2)
		err_msg = "R,G,B colours must be in range [0, 255]";
	ft_putendl_fd(err_msg, STDERR_FILENO);
	return (0);
}

int	map_errors(int error_type)
{
	char	*err_msg;

	ft_putendl_fd("Error: ", STDERR_FILENO);
	if (error_type == ERR_PLAYER)
	{
		err_msg = "Use 'N', 'S', 'W', or 'E' to define orientation player faces";
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
