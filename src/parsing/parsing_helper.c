/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ne <ncruz-ne@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 14:40:27 by megi              #+#    #+#             */
/*   Updated: 2026/11/01 20:06:08 by ncruz-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3D.h"

bool	empty_flag(char *l)
{
	int		i;
	bool	empty_l;

	i = 0;
	empty_l = true;
	while (l[i] && l[i] != '\n')
	{
		if (ft_strchr(" \f\t\v", l[i]))
			i++;
		else
		{
			empty_l = false;
			break ;
		}
	}
	return (empty_l);
}

// int	empty_flag(char *l)
// {
// 	int		i;
// 	bool	empty_l;
//
// 	i = 0;
// 	empty_l = 1;
// 	while (l[i])
// 	{
// 		if (!(ft_strchr(" \t", l[i])))
// 			empty_l = 0;
// 		i++;
// 	}
// 	if (i > 0 && l[i - 1] == '\n')
// 		l[i - 1] = '\0';
// 	// TODO: Milena, I don't understand, can you explain why you change this char?
// 	return (empty_l);
// }
