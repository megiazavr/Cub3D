/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ne <ncruz-ne@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 16:46:10 by megi              #+#    #+#             */
/*   Updated: 2026/11/07 14:38:50 by ncruz-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3D.h" // bring in t_map, t_id_res, prototypes, error enums

static t_id_res identifiers_done(t_map *map)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (map->n_s_w_e_paths[i] == NULL)
			break ;
		i++;
	}
	if (i > 4)
		return (ERROR);
	else if (i < 4)
		return (PENDING);
	i = 0;
	while (i < 2)
	{
		if (map->rgb_f_c[i] == -1)
			break ;
		i++;
	}
	if (i > 2)
		return (ERROR);
	else if (i < 2)
		return (PENDING);
	return (DONE);
}

// static t_id_res	identifiers_done(t_map *map)
// {
// 	int	i;
//
// 	i = 0;
// 	while (i < 4)
// 	{
// 		if (map->n_s_e_w_paths[i] == NULL)
// 			break ;
// 		i++;
// 	}
// 	if (i > 4) // TODO: Can it reach here? 
// 		return (ERROR);
// 	else if (i < 4)
// 		return (PENDING);
// 	if (map->rgb_c_f[C - 4] == -1 || map->rgb_c_f[F - 4] == -1)
// 		return (PENDING);
// 	return (DONE);
// }

// static t_id_res	identifiers_done(t_map *map)
// {
// 	int	i;
//
// 	i = 0;
// 	while (i < 4)
// 	{
// 		if (map->n_s_e_w_paths[i] == NULL)
// 			break ;
// 		i++;
// 	}
// 	if (i > 4)
// 		return (ERROR);
// 	else if (i < 4)
// 		return (PENDING);
// 	i = 0;
// 	while (i < 6)
// 	{
// 		if (map->rgb_c_f[i] == -1)
// 			break ;
// 		i++;
// 	}
// 	if (i > 6)
// 		return (ERROR);
// 	else if (i < 6)
// 		return (PENDING);
// 	return (DONE);
// }

static void	monitor_loop(t_map *map, int in_map)
{
	// char		*line;
	t_id_res	res;

	map->read_line = get_next_line(map->file_fd);
	while (map->read_line != NULL)
	{
		if (empty_flag(map->read_line) == true)
		{
			free_and_null(&map->read_line);
			map->read_line = get_next_line(map->file_fd);
			continue ;
		}
		res = identifiers_done(map);
		if (res == PENDING)
			parse_map_identifiers(map);
		// if (res == COLOR)
		// 	parseconfig(map, line);
		else if (res == ERROR) // TODO: do we reach here? 
			exit_cleanup(map, ERR_TEXTURE, ERR_IDENTIFIER_MSG);
		else if (res == DONE)
		{
			if (in_map == 1)
			{
				map->one_player_per_map = read_map(map, map->read_line);
				free_and_null(&map->read_line);
				map->read_line = get_next_line(map->file_fd);
				continue ;
			}
			else
			{
				in_map = 1;
				map->one_player_per_map = read_map(map, map->read_line);
				// free_and_null(&map->read_line);
			}
		}
		free_and_null(&map->read_line);
		map->read_line = get_next_line(map->file_fd);
	}
	free_and_null(&map->read_line);
}

/* TODO: don't forget to free(line) before any exit_cleanup()
t_monitor monitor(t_map *map)
{
	int fd;
	int	in_map;
	int	i;

	fd = open(map->file, O_RDONLY);
	if (fd < 0)
		exit_cleanup(map, ERR_PERR, ERR_OPEN_MSG);
	map->one_player_per_map = 0;
	in_map = 0;
	i = 0;
	while (i < 4)
		map->n_s_e_w_paths[i++] = NULL;
	i = 0;
	while (i < 6)
		map->rgb_c_f[i++] = -1;
	monitor_loop(map, fd, in_map);
	return (MAP);
}
*/

void	rgb_print(t_map *map, t_map_ids id)
{
	int		i;
	char	c;

	if (id == C || id == F)
	{
		if (id == C)
			c = 'C';
		else if (id == F)
			c = 'F';
		ft_printf(">> Results after parse_rgb() for identifier %c:\n", c);
	}
	i = 0;
	while (i < 2)
	{
		// if (i % 2 == 0)
		// 	ft_putstr_fd("Floor color: ", STDOUT_FILENO);
		// else
		// 	ft_putstr_fd("Ceiling color: ", STDOUT_FILENO);
		// if (i < 2)
		// 	ft_putstr_fd("Red: ", STDOUT_FILENO);
		// else if (i > 1 && i < 4)
		// 	ft_putstr_fd("Green: ", STDOUT_FILENO);
		// else if (i > 3 && i < 6)
		// 	ft_putstr_fd("Blue: ", STDOUT_FILENO);
		// print_bits(map->rgb_c_f[i] + '0');
		// ft_putchar_fd('\n', STDOUT_FILENO);
		if (i == F - 4)
			c = 'F';
		else if (i == C - 4)
			c = 'C';
		printf("array index is %d for ID %c, color is %d)\n",
			i, c, map->rgb_f_c[i]);
		i++;
	}
	printf("\n");
}

t_monitor	monitor(t_map *map)
{
	// char	*line; // TODO: delete if norm adjustments are good
	int	in_map;

	map->file_fd = open(map->file, O_RDONLY);
	if (map->file_fd < 0)
		exit_cleanup(map, ERR_PERR, ERR_OPEN_MSG);
	// map->one_player_per_map = 0;
	// map->next_identifier = 0;
	in_map = 0;
	// map->rgb_f_c[0] = -1;
	// map->rgb_f_c[1] = -1;
	rgb_print(map, 0);
	monitor_loop(map, in_map);
	// if (map->one_player_per_map == 0)
	// 	exit_cleanup(map, ERR_MAP, ERR_PLAYER_MSG);
	return (MAP);
}
