/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ne <ncruz-ne@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 14:40:27 by megi              #+#    #+#             */
/*   Updated: 2026/11/07 15:23:37 by ncruz-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3D.h"

bool	empty_flag(char *l)
{
	bool	empty;

	empty = true;
	while (*l)
	{
		if (*l == '\n')
		{
			*l = '\0';
			break ;
		}
		if (*l != ' ' && *l != '\t' && *l != '\r')
			empty = false;
		l++;
	}
	return (empty);
}
