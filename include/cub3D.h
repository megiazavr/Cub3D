/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ne <ncruz-ne@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 16:47:08 by megi              #+#    #+#             */
/*   Updated: 2026/11/12 00:50:59 by ncruz-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define _XOPEN_SOURCE

# include <math.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "../libs/libft/libft.h"
# include "../libs/minilibx-linux/mlx.h"
# include "cub3D_err.h"

# define WIN_W 1280
# define WIN_H 960

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

// typedef enum e_id_res
// {
// 	TEXTURE,
// 	COLOR,
// 	ERROR
// }	t_id_res;

typedef enum e_id_res
{
	DONE,
	PENDING,
	ERROR,
	TEXTURE,
	COLOR
}	t_id_res;

// typedef struct s_line_node
// {
// 	char				*line;
// 	struct s_line_node	*next;
// }	t_line_node;

// typedef struct s_lines
// {
// 	t_line_node	*head;
// 	t_line_node	*tail;
// }	t_lines;

typedef struct s_map
{
	char			**matrix;
	int				rows_until_map;
	int				rows;
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
	//t_lines			lines;
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

t_monitor	monitor(t_map *map);

void		free_arr(char ***arr);
bool		empty_flag(char *l);
void		free_str(char **str);
void		parse_map_config(t_map *map);
void		valid_color(t_map *map, t_map_ids id);
int			read_map(t_map *map, char *l);
void		exit_cleanup(t_map *map, t_err_type err, char *err_msg);

void		win_init(t_map *map, t_win *win);

// DELETE TESTER:
void		rgb_print(t_map *map, t_map_ids id);

#endif