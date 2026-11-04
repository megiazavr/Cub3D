/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megi <megi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 14:40:27 by megi              #+#    #+#             */
/*   Updated: 2026/11/04 18:35:10 by megi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3D.h"

void free_split(char **arr)
{
	int	i;
	if (!arr)
		return ;
	i = -1;
	while (arr[++i])
		free(arr[i]);
	free(arr);
}

bool empty_flag(char *l)
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
