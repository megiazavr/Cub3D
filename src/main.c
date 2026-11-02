/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ne <ncruz-ne@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 18:04:50 by megi              #+#    #+#             */
/*   Updated: 2026/11/02 01:29:07 by ncruz-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3D.h"

void    exit_cleanup(t_map *map, t_err_type err, int status)
{
    // depending on err_type, call appropriate err function
    // TODO: revise functions that have a perr_msg and move it to cub3D_err.h
    // if (perr_msg)
    //     perror(perr_msg);
    if (map->file)
        free(map->file);
    exit(status);
}

int	main(int ac, char **av)
{
    t_map	map;
    int		len;

    if (ac != 2)
    {
        ft_putendl_fd("Error: Invalid number of arguments", STDERR_FILENO);
        return (EXIT_FAILURE);
    }
    map.file = ft_strtrim(av[1], " \f\n\r\t\v");
    len = ft_strlen(map.file);
    if (len < 4 || ft_strcmp(map.file + len - 4, ".cub") != 0)
    {
        ft_putendl_fd("Error: File missing .cub extension", STDERR_FILENO);
        exit_cleanup(&map, NULL, EXIT_FAILURE);
    }
    monitor(&map);
    exit_cleanup(&map, NULL, EXIT_SUCCESS);
}
