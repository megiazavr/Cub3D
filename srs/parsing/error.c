/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megi <megi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 23:08:05 by megi              #+#    #+#             */
/*   Updated: 2026/08/24 14:44:41 by megi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3D.h"

int texture_errors(int error_type)
{
    if (error_type == ERR_IDENTIFIER)
    {
        write(2, "Error\n", 6);
        write(2, "Use one of this identifiers: NO, SO, WE, EA with path && F, C", 49);
        return (0);
    }
    else if (error_type == ERR_RGB_AV)
    {
        write(2, "Error\n", 6);
        write(2, "It should be three rgb arguments!\n", 34);
        return (0);
    }
	else if (error_type == ERR_RGB_AV2)
    {
        write(2, "Error\n", 6);
        write(2, "RGB args should be inside [0, 255] diaposon!\n", 45);
        return (0);
    }
    return (0);
}
