/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ne <ncruz-ne@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 18:04:50 by megi              #+#    #+#             */
/*   Updated: 2026/11/07 14:51:35 by ncruz-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3D.h"

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
	exit_cleanup(&map, VALID, NULL);
}
