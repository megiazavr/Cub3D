/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megi <megi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 18:04:50 by megi              #+#    #+#             */
/*   Updated: 2026/11/09 18:31:57 by megi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

static t_map	init_map(void)
{
	t_map	map;
	int		i;

	i = 0;
	ft_bzero(&map, sizeof(map));
	map.file_fd = -1;
	while (i < 4)
	{
		map.fd[i] = -1;
		map.n_s_w_e_paths[i] = NULL;
		i++;
	}
	map.identifier[0] = NULL;
	map.identifier[1] = NULL;
	map.rgb_f_c[0] = -1;
	map.rgb_f_c[1] = -1;
	return (map);
}

int	main(int ac, char **av)
{
	t_map	map;
	int		len;

	map = init_map();
	if (ac != 2)
		exit_cleanup(&map, ERR_ARGS, ERR_NR_ARGS);
	map.file = ft_strtrim(av[1], " \f\n\r\t\v");
	len = ft_strlen(map.file);
	if (len < 4 || ft_strcmp(map.file + len - 4, ".cub") != 0)
		exit_cleanup(&map, ERR_ARGS, ERR_ARGS_FILE_MSG);
	monitor(&map);
	// if (map->rows == 0)
	// 	exit_cleanup(map, ERR_MAP, //TOFDO: add the err message if there is no map 
	exit_cleanup(&map, VALID, NULL);
}
