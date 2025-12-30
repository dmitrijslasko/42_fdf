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

float get_iso_coor(int *x, int *y, int *z, t_view *view)
{
    scale_coor(x, y, z, view);

    rotate_x(z, y, view->rot_x);
    rotate_y(x, z, view->rot_y);
    rotate_z(x, y, view->rot_z);

    if (view->projection_type == ISOMETRIC)
        apply_isometric_projection(x, y, z);
	else 
		rotate_z(x, y, 45);
    return (float)(*x + *y); // camera-space depth
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
	// update_origin_coor(dt);
	while (row < map->height)
	{
		col = 0;
		while (col < map->width)
		{
			// start with the map values
			x_iso = col - map->width / 2;
			y_iso = row - map->height / 2;
			z_value = map->nodes[row][col].z;

			// calculate isometric coordinates
			float z_depth = get_iso_coor(&x_iso, &y_iso, &z_value, view);

			// SCREEN SPACE
			map->nodes[row][col].x_iso = x_iso + X_CENTER + view->x_off;
			map->nodes[row][col].y_iso = y_iso + Y_CENTER + view->y_off;
			map->nodes[row][col].z_depth = z_depth;

			++col;
		}
		++row;
	}
}
