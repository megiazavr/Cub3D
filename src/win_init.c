/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ne <ncruz-ne@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 23:16:53 by ncruz-ne          #+#    #+#             */
/*   Updated: 2026/11/12 00:43:00 by ncruz-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

static void	calc_screen_xy_pxls(t_map *map, t_win *win)
{
	size_t	x;
	size_t	y;
	t_point	*point;
	double	scale;

	scale = win->scale;
	y = 0;
	while (y < map->rows)
	{
		x = 0;
		while (x < map->cols)
		{
			point = &map->matrix[x][y];
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
	size_t	x;
	size_t	y;

	win->min_x = map->matrix[0][0].iso_x;
	win->max_x = map->matrix[0][0].iso_x;
	win->min_y = map->matrix[0][0].iso_y;
	win->max_y = map->matrix[0][0].iso_y;
	y = 0;
	while (y < map->rows)
	{
		x = 0;
		while (x < map->cols)
		{
			if (map->matrix[x][y].iso_x < win->min_x)
				win->min_x = map->matrix[x][y].iso_x;
			if (map->matrix[x][y].iso_x > win->max_x)
				win->max_x = map->matrix[x][y].iso_x;
			if (map->matrix[x][y].iso_y < win->min_y)
				win->min_y = map->matrix[x][y].iso_y;
			if (map->matrix[x][y].iso_y > win->max_y)
				win->max_y = map->matrix[x][y].iso_y;
			x++;
		}
		y++;
	}
}

void	win_init(t_map *map, t_win *win)
{
	double	margin;

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
