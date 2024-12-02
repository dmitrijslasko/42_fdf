/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 11:37:21 by dmlasko           #+#    #+#             */
/*   Updated: 2024/12/02 22:50:39 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map	*init_map(t_data *dt, int width, int height, int z)
{
	t_map	*map;
	int		current_row;
	int		current_col;

	map = protected_malloc(sizeof(t_map), dt);
	dt->map = map;
	map->width = width;
	map->height = height;
	map->has_clr_info = 0;
	map->coor = protected_malloc(height * sizeof(t_coor), dt);
	current_row = 0;
	while (current_row < height)
	{
		map->coor[current_row] = malloc(width * sizeof(t_coor));
		if (!map->coor[current_row])
		{
			perror("Error allocating memory: map->coor[current_row]");
			free_map(map, current_row);
			return (NULL);
		}
		current_col = 0;
		while (current_col < width)
		{
			map->coor[current_row][current_col].z = z;
			map->coor[current_row][current_col].z_clr = DEF_LINE_COLOR;
			++current_col;
		}
		++current_row;
	}
	update_iso_coors(dt, dt->map, dt->view);
	return (map);
}

void	free_map(t_map *map, int allocated_rows)
{
	int	row;

	if (map)
	{
		if (map->coor)
		{
			row = 0;
			while (row < allocated_rows)
			{
				free(map->coor[row]);
				++row;
			}
			free(map->coor);
		}
		free(map);
	}
}
