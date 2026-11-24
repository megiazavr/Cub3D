/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megi <megi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 16:47:08 by megi              #+#    #+#             */
/*   Updated: 2026/11/17 17:50:25 by megi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "../libs/libft/libft.h"
# include "../libs/minilibx-linux/mlx.h"
#include <stdbool.h>
# include "cub3D_err.h"

# define WIN_W 1280
# define WIN_H 960
# define TILE_W 64
# define TILE_H 32

typedef enum e_monitor
{
	CONFIG,
	MAP
}	t_monitor;

typedef enum e_player
{
	N,
	S,
	W,
	E
}	t_player;

typedef enum e_map_ids
{
	NO,
	SO,
	WE,
	EA,
	F,
	C
}	t_map_ids;

typedef enum e_id_res
{
	DONE,
	PENDING,
	ERROR,
	TEXTURE,
	COLOR
}	t_id_res;

typedef struct s_map
{
	char 			**matrix;
	struct s_point	**iso_grid;
	int				rows_until_map;
	int				rows;
	char 			*column_line;
	int				columns;
	int				column_x;
	int				row_y;
	char			player_dir;
	int				one_player_per_map;
	char			*identifier[2];
	char			*n_s_w_e_paths[4];
	int				fd[4];
	int				rgb_f_c[2];
	char			*file;
	int				file_fd;
	int				space;
	char			*read_line;
	int				next_identifier;
}	t_map;

/* Window structures */
typedef struct s_img
{
	void	*img_ptr;
	char	*img_pxls_ptr;
	int		bits_per_pxl;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_point
{
	long	x;
	long	y;
	long	z;
	double	c_x;
	double	c_y;
	double	iso_x;
	double	iso_y;
	long	screen_x;
	long	screen_y;
	int		colour;
}	t_point;

typedef struct s_win
{
	double	min_x;
	double	max_x;
	double	min_y;
	double	max_y;
	double	map_w;
	double	map_h;
	double	scale_x;
	double	scale_y;
	double	scale;
	double	offset_x;
	double	offset_y;
}	t_win;

// Parsing
t_monitor	monitor(t_map *map);

void 		matrix(t_map *map);
void		parse_map_config(t_map *map);
void		valid_color(t_map *map, t_map_ids id);
int			read_map(t_map *map, int y, int x);
void		flood_fill(t_map *map, int y, int x);
void		print_matrix(t_map *map);
void		results(t_map *map, t_id_res res, bool *first_open);
void		parse_map(t_map *map, int i);
void		count_map_rows(t_map *map);
void		count_map_columns(t_map *map);
void		reopen(t_map *map);
char		*column_line(t_map *map);
bool		empty_flag(char *l);
void		free_str(char **str);
void		free_arr(char ***arr);
void		exit_cleanup(t_map *map, t_err_type err, char *err_msg);
bool	space(t_map *map, char c);

void		win_init(t_map *map, t_win *win);

// DELETE TESTER:
// void		rgb_print(t_map *map, t_map_ids id);

#endif