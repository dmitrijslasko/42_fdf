/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 11:36:09 by dmlasko           #+#    #+#             */
/*   Updated: 2024/12/02 21:13:06 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	get_iso_coor(int *x_iso, int *y_iso, int *z, t_view *view)
{
	float depth;

	scale_coor(x_iso, y_iso, z, view);

	rotate_x(z, y_iso, view->rot_x);
	rotate_y(x_iso, z, view->rot_y);
	rotate_z(x_iso, y_iso, view->rot_z);
	
	if (view->projection_type == ISOMETRIC)
		apply_isometric_projection(x_iso, y_iso, z);

	depth = *x_iso + *y_iso;
	depth = *z;
	
	return depth;
}

// Update ISO coordinates
void	update_all_iso_coordinates(t_data *dt, t_map *map, t_view *view)
{
	int	row;
	int	col;
	
	int z_value = 0;
	int	x_iso;
	int	y_iso;

	row = 0;
	update_origin_coor(dt);
	// t_node *node;
	// node = map->nodes;
	// while (node)
	// {
	// 	node++;
	// }
	while (row < map->height)
	{
		col = 0;
		while (col < map->width)
		{
			// start with the map values
			x_iso = col;
			y_iso = row;
			z_value = map->nodes[row][col].z;

			// calculate isometric coordinates
			float z_depth = get_iso_coor(&x_iso, &y_iso, &z_value, view);

			map->nodes[row][col].z_depth = z_depth;

			map->nodes[row][col].x_iso = x_iso + (X_CENTER - view->origin_x_iso) + view->x_off;
			map->nodes[row][col].y_iso = y_iso + (Y_CENTER - view->origin_y_iso) + view->y_off;
			map->nodes[row][col].z_depth = map->nodes[row][col].y_iso;

			++col;
		}
		++row;
	}
}
