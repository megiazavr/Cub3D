/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megi <megi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 00:00:00 by megi              ##    #+#             */
/*   Updated: 2026/11/03 00:00:00 by megi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3D.h"

void build_grid(t_map *map)
{
	t_line_node	*node;
	t_line_node	*next;
	int			i;

	map->grid = malloc(sizeof(char *) * (map->rows + 1));
	if (!map->grid)
		return ;
	node = map->lines.head;
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

static int scan_map_char(t_map *map, char *l, int j)
{
	if (l[j] == '0' || l[j] == '1')
		map->space = 0;
	else if (l[j] == ' ') {
		map->space++;
		if (map->space > 2)
			exit_cleanup(map, ERR_MAP, ERR_MAP_SPACE_MSG);
	}
	else if (l[j] == 'N' || l[j] == 'S' || l[j] == 'W' || l[j] == 'E') {
		map->space = 0;
		map->one_player_per_map += 1;
		if (map->one_player_per_map == 1)
		{
			map->player_dir = l[j];
			map->player_x = j;
			map->player_y = map->rows;
		}
		if (map->one_player_per_map > 1)
			exit_cleanup(map, ERR_MAP, ERR_PLAYER_MSG);
	}
	else
		exit_cleanup(map, ERR_MAP, ERR_PLAYER_MSG);
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
	if (!map->lines.head)
	{
		map->lines.head = node;
		map->lines.tail = node;
	}
	else
	{
		map->lines.tail->next = node;
		map->lines.tail = node;
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
	return (map->one_player_per_map);
}
