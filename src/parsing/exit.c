/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ne <ncruz-ne@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 23:08:05 by megi              #+#    #+#             */
/*   Updated: 2026/11/07 15:24:02 by ncruz-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3D.h"

void	free_and_null(char **str)
{
	if (str && *str)
	{
		free(*str);
		*str = NULL;
	}
}

void	free_arr(char ***arr)
{
	int	i;

	if (!arr || !*arr)
		return ;
	i = 0;
	while ((*arr)[i])
		free_and_null(&(*arr)[i++]);
	free(*arr);
	*arr = NULL;
}

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

static void	close_fds(t_map *map)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (map->fd[i] >= 0)
			close(map->fd[i]);
		i++;
	}
	if (map->file_fd >= 0)
		close(map->file_fd);
}

void	exit_cleanup(t_map *map, t_err_type err, char *err_msg)
{
	int	i;

	if (err != VALID)
		print_err_msg(err, err_msg);
	free_and_null(&map->read_line);
	free_and_null(&map->file);
	free_arr(&map->identifier);
	i = 0;
	while (i < 4)
		free_and_null(&map->n_s_w_e_paths[i++]);
	close_fds(map);
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
