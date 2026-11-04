/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megi <megi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 23:08:05 by megi              #+#    #+#             */
/*   Updated: 2026/11/04 18:34:59 by megi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3D.h"


static void	print_err_msg(t_err_type err, char *err_msg)
{
	ft_putendl_fd("Error", STDERR_FILENO);
	if (err == ERR_TEXTURE)
		ft_putendl_fd(ERR_TEXTURE_MSG, STDERR_FILENO);
	else if (err == ERR_MAP)
		ft_putendl_fd(ERR_MAP_MSG, STDERR_FILENO);
	if (err == ERR_PERR)
		perror(err_msg);
	else
		ft_putendl_fd(err_msg, STDERR_FILENO);
	return ;
}


void	exit_cleanup(t_map *map, t_err_type err, char *err_msg)
{
	int	i;

	if (err != VALID)
		print_err_msg(err, err_msg);
	if (map->file)
		free(map->file);
	if (map->identifier)
	{
		i = 0;
		while (map->identifier[i])
		{
			free(map->identifier[i]);
			i++;
		}
		free(map->identifier);
	}
	if (err != VALID)
		exit(EXIT_FAILURE);
	exit(EXIT_SUCCESS);
}

/*
void	texture_errors(char *err_msg)
{
	ft_putstr_fd(ERR_TEXTURE_MSG, STDOUT_FILENO);
	ft_putendl_fd(err_msg, STDOUT_FILENO);
	// TODO: decide if we use perror() or not
	// if (perr_msg)
	//     perror(perr_msg);
	ft_putstr_fd(ERR_TEXTURE_MSG, STDERR_FILENO);
	ft_putendl_fd(err_msg, STDERR_FILENO);
	return ;
}

void	map_errors(char *err_msg) // TODO: why return is int? change to void?
{
	if (error_type == ERR_PLAYER)
	{
		err_msg = ERR_PLAYER_MSG;
		//exit (1);
	}
	if (error_type == ERR_MAP_SPACE)
	{
		err_msg = ERR_MAP_SPACE_MSG;
		//exit (1);
	}
	ft_putendl_fd(err_msg, STDERR_FILENO);
	// TODO: add t_map *map to functions args and uncomment exit_cleanup()
	// exit_cleanup(map, NULL, EXIT_FAILURE);
	return ;
}
 */
