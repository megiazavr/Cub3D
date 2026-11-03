/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ne <ncruz-ne@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 18:04:50 by megi              #+#    #+#             */
/*   Updated: 2026/11/02 22:47:07 by ncruz-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3D.h"

int	main(int ac, char **av)
{
	t_map	map;
	int		len;

	if (ac != 2)
		exit_cleanup(&map, ERR_ARGS, ERR_NR_ARGS);
	map.file = ft_strtrim(av[1], " \f\n\r\t\v");
	len = ft_strlen(map.file);
	if (len < 4 || ft_strcmp(map.file + len - 4, ".cub") != 0)
		exit_cleanup(&map, ERR_ARGS, ERR_ARGS_FILE_MSG);
	monitor(&map);
	exit_cleanup(&map, VALID, NULL);
}
