/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megi <megi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 18:04:50 by megi              #+#    #+#             */
/*   Updated: 2026/08/24 21:34:02 by megi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/cub3D.h"

int main(int ac, char **av) {
    char *file;
    t_map map;
    int len;

    if (ac <= 1) {
        write(2, "Error\nGive me arguments!", 24);
        return (0);
    }
    file = av[1];
    len = ft_strlen(file);
    if (len < 4 || ft_strcmp(file + len - 4, ".cub") != 0)
        return (write(2, "Error\nFile must have only .cub extension", 40), 1);
    monitor(&map, file);
    return (0);
}