/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: megi <megi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 15:38:25 by ncruz-ne          #+#    #+#             */
/*   Updated: 2026/11/09 16:47:51 by megi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

static t_id_res	rgb_validator(char **rgb)
{
	int	i;
	int	j;
	int	digits;

	i = 0;
	while (rgb[i] != NULL)
	{
		j = 0;
		digits = 0;
		while (rgb[i][j] == ' ' || rgb[i][j] == '\t')
			j++;
		while (rgb[i][j + digits] >= '0' && rgb[i][j + digits] <= '9')
			digits++;
		j = j + digits;
		while (rgb[i][j] == ' ' || rgb[i][j] == '\t')
			j++;
		if (rgb[i][j] != '\0' || (rgb[i][j] == '\0' && digits < 1))
			return (ERROR);
		i++;
	}
	return (COLOR);
}

static void	parse_rgb(t_map *map, char **rgb, t_map_ids c_or_f)
{
	int	r;
	int	g;
	int	b;

	r = ft_atoi(rgb[0]);
	g = ft_atoi(rgb[1]);
	b = ft_atoi(rgb[2]);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
	{
		free_arr(&rgb);
		exit_cleanup(map, ERR_TEXTURE, ERR_RGB_AV2_MSG);
	}
	free_arr(&rgb);
	if (map->rgb_f_c[c_or_f - 4] != -1)
		exit_cleanup(map, ERR_TEXTURE, ERR_RGB_AV_MSG);
	map->rgb_f_c[c_or_f - 4] = (r << 16) | (g << 8) | b;
	rgb_print(map, c_or_f);
	return ;
}

void	valid_color(t_map *map, t_map_ids id)
{
	char	*rgb_str;
	char	**rgb;

	if ((int)id != map->next_identifier)
		exit_cleanup(map, ERR_TEXTURE, ERR_ORDER_MSG);
	map->next_identifier++;
	rgb_str = ft_strtrim(map->identifier[1], " \t");
	rgb = ft_split(rgb_str, ',');
	free_str(&rgb_str);
	if (rgb_validator(rgb) != COLOR || rgb[3] != NULL)
	{
		free_arr(&rgb);
		exit_cleanup(map, ERR_TEXTURE, ERR_RGB_AV_MSG);
	}
	parse_rgb(map, rgb, id);
	return ;
}

// TODO: delete tester
void	rgb_print(t_map *map, t_map_ids id)
{
	int		i;
	char	c;

	c = 0;
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
