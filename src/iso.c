/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 11:36:09 by dmlasko           #+#    #+#             */
/*   Updated: 2024/12/01 20:53:39 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// Add convexity
// static void add_convex(int *x, int *y, int *z, t_view *view)
// {
// 	(void)view;
//    	*z = *y * *x / 20;
// }

// Scale / zoom
static void	scale_coor(int *x, int *y, int *z, t_view *view)
{
	*x = *x * view->xy_distance * view->zoom;
	*y = *y * view->xy_distance * view->zoom;
	*z = *z * view->z_distance * view->zoom;
}

// Rotate around X axis
static void	rotate_x(int *y, int *z, double rot_x)
{
	int		previous_y;
	double	angle_rad;

	angle_rad = deg_to_radians(rot_x);
	previous_y = *y;
	*y = previous_y * cos(angle_rad) + *z * sin(angle_rad);
	*z = -previous_y * sin(angle_rad) + *z * cos(angle_rad);
}

// Rotate around Y axis
static void	rotate_y(int *x, int *z, double rot_y)
{
	int		previous_x;
	double	angle_rad;

	angle_rad = deg_to_radians(rot_y);
	previous_x = *x;
	*x = previous_x * cos(angle_rad) + *z * sin(angle_rad);
	*z = -previous_x * sin(angle_rad) + *z * cos(angle_rad);
}

// Rotate around Z axis
static void	rotate_z(int *x, int *y, double rot_z)
{
	int		previous_x;
	int		previous_y;
	double	angle_rad;

	angle_rad = deg_to_radians(rot_z);
	previous_x = *x;
	previous_y = *y;
	*x = previous_x * cos(angle_rad) - previous_y * sin(angle_rad);
	*y = previous_x * sin(angle_rad) + previous_y * cos(angle_rad);
}

// Project to ISO projection
static void	project(int *x, int *y, int *z)
{
	int		incoming_x;
	int		incoming_y;
	double	angle_rad;

	incoming_x = *x;
	incoming_y = *y;
	angle_rad = deg_to_radians(DEF_ISO_ANGLE);
	*x = (incoming_x - incoming_y) * cos(angle_rad);
	*y = (incoming_x + incoming_y) * sin(angle_rad) - *z;
}

void	get_iso_coor(int *x, int *y, int *z, t_view *view)
{
	scale_coor(x, y, z, view);
	rotate_x(z, y, view->rot_x);
	rotate_y(x, z, view->rot_y);
	rotate_z(x, y, view->rot_z);
	if (view->projection == ISO)
		project(x, y, z);
}

// Update ISO coordinates
void	update_iso_coors(t_data *data, t_map *m, t_view *v)
{
	int	r;
	int	c;
	int	z_value;
	int	x_iso;
	int	y_iso;

	r = 0;
	while (r < m->height)
	{
		c = 0;
		while (c < m->width)
		{
			update_origin_coor(data);
			x_iso = c;
			y_iso = r;
			z_value = m->coor[r][c].z;
			get_iso_coor(&x_iso, &y_iso, &z_value, v);
			m->coor[r][c].x_iso = x_iso + (X_CENTER - v->origin_x + v->x_off);
			m->coor[r][c].y_iso = y_iso + (Y_CENTER - v->origin_y + v->y_off);
			++c;
		}
		++r;
	}
}
