/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megi <megi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/24 14:40:27 by megi              #+#    #+#             */
/*   Updated: 2026/11/17 17:59:54 by megi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

bool	empty_flag(char *l)
{
	bool	empty;

	empty = true;
	while (*l)
	{
		if (*l == '\n')
		{
			*l = '\0';
			break ;
		}
		if (*l != ' ' && *l != '\t' && *l != '\r')
			empty = false;
		l++;
	}
	return (empty);
}

void	results(t_map *map, t_id_res res, bool *first_open)
{
	if (res == PENDING)
		parse_map_config(map);
	else if (res == ERROR)
		exit_cleanup(map, ERR_TEXTURE, ERR_IDENTIFIER_MSG);
	else if (res == DONE)
	{
		if (*first_open == true)
		{
			free_str(&map->read_line);
			count_map_rows(map);
			count_map_columns(map);
			if (map->rows > 200 || map->columns > 200)
				exit_cleanup(map, ERR_MAP, ERR_MAP_TOO_BIG_MSG);
			close(map->file_fd);
			*first_open = false;
		}
		if (*first_open == false)
			parse_map(map, 0);
	}
	free_str(&map->read_line);
	map->read_line = get_next_line(map->file_fd);
	if (res != DONE)
		map->rows_until_map++;
}

void	reopen(t_map *map)
{
	if (map->file_fd >= 0)
		close(map->file_fd);
	map->file_fd = open(map->file, O_RDONLY);
	if (map->file_fd < 0)
		exit_cleanup(map, ERR_PERR, ERR_OPEN_MSG);
	gnl_reset(map->file_fd);
}

char	*column_line(t_map *map)
{
	int		i;

	i = 0;
	map->column_line = malloc(sizeof(char) * (map->columns + 1));
	if (!map->column_line)
		return (NULL);
	while (map->read_line[i])
	{
		if (map->read_line[i] == ' ' || map->read_line[i] == '\t')
			map->column_line[i] = ' ';
		else
			map->column_line[i] = map->read_line[i];
		i++;
	}
	while (i < map->columns)
		map->column_line[i++] = ' ';
	map->column_line[map->columns] = '\0';
	return (map->column_line);
}

bool	space(t_map *map, char c)
{
	(void)map;
	if (c == '0' || c == '1')
		return (true);
	if (c == ' ' || c == '\t')
		return (true);
	return (false);
}

