/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncruz-ne <ncruz-ne@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/19 16:47:08 by megi              #+#    #+#             */
/*   Updated: 2026/11/08 22:49:21 by ncruz-ne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libs/libft/libft.h"
# include "cub3D_err.h"

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

typedef struct s_line_node
{
	char				*line;
	struct s_line_node	*next;
}	t_line_node;

// typedef struct s_lines
// {
// 	t_line_node	*head;
// 	t_line_node	*tail;
// }	t_lines;

typedef struct s_map
{
	char			*file;
	int				file_fd;
	//char            **grid;
	//int		        rows;
	int				space;
	//t_lines			lines;
	char			*read_line;
	char			player_dir;
	int				player_x;
	int				player_y;
	int				one_player_per_map;
	char			*identifier[2];
	char			*n_s_w_e_paths[4];
	int				fd[4];
	int				rgb_f_c[2];
	int				next_identifier;
}	t_map;

t_monitor	monitor(t_map *map);

void		free_arr(char ***arr);
bool		empty_flag(char *l);
void		free_str(char **str);
void		parse_map_config(t_map *map);
void		valid_color(t_map *map, t_map_ids id);
int			read_map(t_map *map, char *l);
void		exit_cleanup(t_map *map, t_err_type err, char *err_msg);

// DELETE TESTER:
void		rgb_print(t_map *map, t_map_ids id);

#endif