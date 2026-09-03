/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ne <ncruz-ne@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 18:04:50 by megi              #+#    #+#             */
/*   Updated: 2026/09/03 20:37:12 by ncruz-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3D.h"

int	main(int ac, char **av)
{
    char	*file;
    t_map	map;
    int		len;

    // TODO: can we give more than 1 arg? If not, should be if (ac != 2)
    if (ac <= 1) {
        write(2, "Error\nGive me arguments!", 24);
		// TODO: when we have an error, shouldn't we return EXIT_FAILURE = 1?
        return (0);
    }
    file = av[1];
    len = ft_strlen(file);
	// TODO: we can use ft_strnstr() instead to simplify
    if (len < 4 || ft_strcmp(file + len - 4, ".cub") != 0)
        return (write(2, "Error\nFile must have only .cub extension", 40), 1);
    monitor(&map, file);
    return (EXIT_SUCCESS);
}