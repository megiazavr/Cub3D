/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megi <megi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 16:46:10 by megi              #+#    #+#             */
/*   Updated: 2026/08/30 19:17:52 by megi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3D.h"

int parseconfig(t_map *map, char *line) {
	t_results 	res;

	res = valid_identifier(map, line);
	if (res == COLOR)
		res = valid_color(map, line);
	if (res == ERROR)
		exit(1);
	return (0);
}

static void caller(t_map *map, char *line)
{
	if (map->mode == CONFIG) {
		map->parsing.identifier = ft_split(line, ' ');
		if (map->parsing.identifier[0] && (ft_strcmp(map->parsing.identifier[0], "NO") == 0
			|| ft_strcmp(map->parsing.identifier[0], "SO") == 0
			|| ft_strcmp(map->parsing.identifier[0], "WE") == 0
			|| ft_strcmp(map->parsing.identifier[0], "EA") == 0
			|| ft_strcmp(map->parsing.identifier[0], "F") == 0
			|| ft_strcmp(map->parsing.identifier[0], "C") == 0))
			parseconfig(map, line);
		else {
			map->mode = MAP;
			map->player.one_gamer_per_map = readthemap(map, line);
		}
	}
	else if (map->mode == MAP)
		map->player.one_gamer_per_map = readthemap(map, line);
}

static void build_grid(t_map *map)
{
	t_line_node	*node;
	t_line_node	*next;
	int			i;

	map->grid = malloc(sizeof(char *) * (map->rows + 1));
	if (!map->grid)
		return ;
	node = map->lines_head;
	i = 0;
	while (node)
	{
		map->grid[i] = node->line;
		next = node->next;
		free(node);
		i++;
		node = next;
	}
	map->grid[map->rows] = NULL;
}

t_monitor monitor(t_map *map, char *file) {
	char		*line;
	int 		fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (perror("OOPS "), 0);
	map->player.one_gamer_per_map = 0;
	map->rows = 0;
	map->lines_head = NULL;
	map->lines_tail = NULL;
	map->mode = CONFIG;
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (empty_flag(line)) {
			line = get_next_line(fd);
			continue ;
		}
		caller(map, line);
		line = get_next_line(fd);
	}
	build_grid(map);
	if (map->player.one_gamer_per_map == 0)
		map_errors(ERR_PLAYER);
	check_walls(map);
	return (MAP);
}

static int scan_map_char(t_map *map, char *l, int j)
{
	if (l[j] == '0' || l[j] == '1')
		map->space = 0;
	else if (l[j] == ' ') {
		map->space++;
		if (map->space > 2)
			map_errors(ERR_MAP_SPACE);
	}
	else if (l[j] == 'N' || l[j] == 'S' || l[j] == 'W' || l[j] == 'E') {
		map->space = 0;
		map->player.one_gamer_per_map += 1;
		if (map->player.one_gamer_per_map == 1)
		{
			map->player.dir = l[j];
			map->player.gamer_x = j;
			map->player.gamer_y = map->rows;
		}
		if (map->player.one_gamer_per_map > 1)
			map_errors(ERR_PLAYER);
	}
	else
		map_errors(ERR_PLAYER);
	return (j + 1);
}

static void list_append(t_map *map, char *line)
{
	t_line_node	*node;

	node = malloc(sizeof(t_line_node));
	if (!node)
		return ;
	node->line = line;
	node->next = NULL;
	if (!map->lines_head)
	{
		map->lines_head = node;
		map->lines_tail = node;
	}
	else
	{
		map->lines_tail->next = node;
		map->lines_tail = node;
	}
}

int readthemap(t_map *map, char *l) {
	int	j;

	j = 0;
	map->space = 0;
	while (l[j])
		j = scan_map_char(map, l, j);
	list_append(map, l);
	map->rows++;
	return (map->player.one_gamer_per_map);
}
