/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ne <ncruz-ne@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 18:04:50 by megi              #+#    #+#             */
/*   Updated: 2026/09/20 19:01:00 by ncruz-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3D.h"

int	main(int ac, char **av)
{
    char	*file;
    t_map	map;
    int		len;

    if (ac != 2)
    {
        ft_putendl_fd("Error: Invalid number of arguments", STDERR_FILENO);
        return (EXIT_FAILURE);
    }
    file = ft_strtrim(av[1], " \f\n\r\t\v");
    len = ft_strlen(file);
    if (len < 4 || ft_strcmp(file + len - 4, ".cub") != 0)
    {
        ft_putendl_fd("Error: File doesn't have .cub extension", STDERR_FILENO);
        free(file); // TODO: create exit cleanup routine
        return (EXIT_FAILURE);
    }
    monitor(&map, file);
    free(file); // TODO: create exit cleanup routine
    return (EXIT_SUCCESS);
}
