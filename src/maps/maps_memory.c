/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 11:37:21 by dmlasko           #+#    #+#             */
/*   Updated: 2025/01/18 16:29:33 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	int	init_row(t_data *dt, int height, int width, int z)
{
	int	current_row;
	int	current_col;

	current_row = 0;
	while (current_row < height)
	{
		dt->map->nodes[current_row] = calloc(width, sizeof(t_node));
		if (!dt->map->nodes[current_row])
		{
			perror("Error allocating memory: map->coor[current_row]");
			free_map(dt->map, current_row);
			exit (1);
		}
		current_col = 0;
		while (current_col < width)
		{
			dt->map->nodes[current_row][current_col].z = z;
			dt->map->nodes[current_row][current_col].z_color = DEF_LINE_COLOR;
			dt->map->nodes[current_row][current_col].z_clr_custom = WHITE;
			++current_col;
		}
		++current_row;
	}
	return (0);
}

t_map	*init_map(t_data *dt, int height, int width, int z)
{
	t_map	*map;

	map = protected_malloc(sizeof(t_map));
	dt->map = map;
	map->width = width;
	map->height = height;
	map->has_color_info = 0;
	map->nodes = protected_malloc(width * height * sizeof(t_node));
	init_row(dt, height, width, z);
	update_all_iso_coordinates(dt, dt->map, dt->view);
	return (map);
}

void	free_map(t_map *map, int allocated_rows)
{
	int	row;

	if (map)
	{
		if (map->nodes)
		{
			row = 0;
			while (row < allocated_rows)
			{
				free(map->nodes[row]);
				++row;
			}
			free(map->nodes);
		}
		free(map);
	}
}
