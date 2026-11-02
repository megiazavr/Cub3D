/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ne <ncruz-ne@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 23:08:05 by megi              #+#    #+#             */
/*   Updated: 2026/11/02 22:31:11 by ncruz-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3D.h"

static void	err_msg(t_err_type err, char *perr_msg)
{
	ft_putendl_fd("Error", STDOUT_FILENO);
	ft_putendl_fd("Error", STDERR_FILENO);
	if (err == ERR_TEXTURE)
	{
		ft_putstr_fd(ERR_TEXTURE_MSG, STDOUT_FILENO);
		ft_putstr_fd(ERR_TEXTURE_MSG, STDERR_FILENO);
	}
	else if (err == ERR_MAP)
	{
		ft_putstr_fd(ERR_MAP_MSG, STDOUT_FILENO);
		ft_putstr_fd(ERR_MAP_MSG, STDERR_FILENO);
	}
	ft_putstr_fd(perr_msg, STDOUT_FILENO);
	ft_putstr_fd(perr_msg, STDERR_FILENO);
	return ;
}
/* TODO: confirm if we need error msgs in stdout and stdin, and perror() */

void	exit_cleanup(t_map *map, t_err_type err, char *perr_msg)
{
	if (err != VALID)
		err_msg(err, perr_msg);
	if (map->file)
		free(map->file);
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