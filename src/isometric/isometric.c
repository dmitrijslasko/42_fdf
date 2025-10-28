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

void	get_iso_coor(int *x, int *y, int *z, t_view *view)
{
	scale_coor(x, y, z, view);

	rotate_x(z, y, view->rot_x);
	rotate_y(x, z, view->rot_y);
	rotate_z(x, y, view->rot_z);

	if (view->projection == ISO)
		apply_isometric_projection(x, y, z);
	
	int topdown_x = (*x - *y) * 0.7071;
	int topdown_y = (*x + *y) * 0.7071;

	if (view->projection == TOPDOWN)
	{
		*x = topdown_x;
		*y = topdown_y;
	}
	// *z = topdown_y;
}

// Update ISO coordinates
void	update_iso_coors(t_data *dt, t_map *map, t_view *view)
{
	int	row;
	int	col;
	
	int	z_value;
	int	x_iso;
	int	y_iso;

	row = 0;
	while (row < map->height)
	{
		col = 0;
		while (col < map->width)
		{
			update_origin_coor(dt);

			// start with the map values
			x_iso = col;
			y_iso = row;
			z_value = map->coor[row][col].z;

			// calculate isometric coordinates
			get_iso_coor(&x_iso, &y_iso, &z_value, view);
			// get_z_depth(&map->coor[row][col].z_depth);
			map->coor[row][col].x_iso = x_iso + (X_CENTER - view->origin_x + view->x_off);
			map->coor[row][col].y_iso = y_iso + (Y_CENTER - view->origin_y + view->y_off);
			
			map->coor[row][col].z_depth = z_value;
			// if (row == 0 && col == 2)
			// 	printf("%d\n", map->coor[row][col].z_depth);
			++col;
		}
		++row;
	}
}
