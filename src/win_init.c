/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ne <ncruz-ne@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 23:16:53 by ncruz-ne          #+#    #+#             */
/*   Updated: 2026/11/24 00:00:00 by megi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

static void	build_iso_grid(t_map *map)
{
	int		y;
	int		x;
	t_point	*point;

	map->iso_grid = malloc(sizeof(t_point *) * map->rows);
	if (!map->iso_grid)
		exit_cleanup(map, ERR_PERR, ERR_MEM_MATRIX_MSG);
	y = 0;
	while (y < map->rows)
	{
		map->iso_grid[y] = malloc(sizeof(t_point) * map->columns);
		if (!map->iso_grid[y])
			exit_cleanup(map, ERR_PERR, ERR_MEM_MATRIX_MSG);
		x = 0;
		while (x < map->columns)
		{
			point = &map->iso_grid[y][x];
			point->x = x;
			point->y = y;
			point->iso_x = (double)(x - y) * (TILE_W / 2.0);
			point->iso_y = (double)(x + y) * (TILE_H / 2.0);
			point->colour = (map->matrix[y][x] == '1');
			x++;
		}
		y++;
	}
}

static void	calc_screen_xy_pxls(t_map *map, t_win *win)
{
	int		x;
	int		y;
	t_point	*point;
	double	scale;

	scale = win->scale;
	y = 0;
	while (y < map->rows)
	{
		x = 0;
		while (x < map->columns)
		{
			point = &map->iso_grid[y][x];
			point->screen_x = (long)((point->iso_x - win->min_x) * scale
					+ win->offset_x);
			point->screen_y = (long)((point->iso_y - win->min_y) * scale
					+ win->offset_y);
			x++;
		}
		y++;
	}
}

static void	find_iso_xy_limits(t_map *map, t_win *win)
{
	int	x;
	int	y;

	win->min_x = map->iso_grid[0][0].iso_x;
	win->max_x = map->iso_grid[0][0].iso_x;
	win->min_y = map->iso_grid[0][0].iso_y;
	win->max_y = map->iso_grid[0][0].iso_y;
	y = 0;
	while (y < map->rows)
	{
		x = 0;
		while (x < map->columns)
		{
			if (map->iso_grid[y][x].iso_x < win->min_x)
				win->min_x = map->iso_grid[y][x].iso_x;
			if (map->iso_grid[y][x].iso_x > win->max_x)
				win->max_x = map->iso_grid[y][x].iso_x;
			if (map->iso_grid[y][x].iso_y < win->min_y)
				win->min_y = map->iso_grid[y][x].iso_y;
			if (map->iso_grid[y][x].iso_y > win->max_y)
				win->max_y = map->iso_grid[y][x].iso_y;
			x++;
		}
		y++;
	}
}

void	win_init(t_map *map, t_win *win)
{
	double	margin;

	build_iso_grid(map);
	find_iso_xy_limits(map, win);
	win->map_w = win->max_x - win->min_x;
	win->map_h = win->max_y - win->min_y;
	margin = 0.9;
	win->scale_x = (double)(WIN_W * margin) / win->map_w;
	win->scale_y = (double)(WIN_H * margin) / win->map_h;
	win->scale = fmin(win->scale_x, win->scale_y);
	win->offset_x = (WIN_W - (win->map_w * win->scale)) / 2.0;
	win->offset_y = (WIN_H - (win->map_h * win->scale)) / 2.0;
	calc_screen_xy_pxls(map, win);
}
