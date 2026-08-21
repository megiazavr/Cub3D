/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megi <megi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 18:04:50 by megi              #+#    #+#             */
/*   Updated: 2026/08/20 18:45:49 by megi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/cub3D.h"

int main(int ac, char **av) {
    char *file;
    t_map map;
    
    if (ac <= 1) {
        write(2, "Give me arguments!\n", 19);
        return (0);
    }
    file = av[1];
    readthemap(&map, file);
    return (0);
}