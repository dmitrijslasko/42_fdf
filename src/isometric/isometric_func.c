/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric_func.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 21:04:46 by dmlasko           #+#    #+#             */
/*   Updated: 2024/12/03 10:43:29 by dmlasko          ###   ########.fr       */
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
void	scale_coor(int *x, int *y, int *z, t_view *view)
{
	*x = *x * view->xy_dist * view->zoom;
	*y = *y * view->xy_dist * view->zoom;
	*z = *z * view->z_dist * view->zoom;
}

// Rotate around X axis
void	rotate_x(int *y, int *z, double rot_x)
{
	int		previous_y;
	double	angle_rad;

	angle_rad = deg_to_radians(rot_x);
	previous_y = *y;
	*y = previous_y * cos(angle_rad) + *z * sin(angle_rad);
	*z = -previous_y * sin(angle_rad) + *z * cos(angle_rad);
}

// Rotate around Y axis
void	rotate_y(int *x, int *z, double rot_y)
{
	int		previous_x;
	double	angle_rad;

	angle_rad = deg_to_radians(rot_y);
	previous_x = *x;
	*x = previous_x * cos(angle_rad) + *z * sin(angle_rad);
	*z = -previous_x * sin(angle_rad) + *z * cos(angle_rad);
}

// Rotate around Z axis
void	rotate_z(int *x, int *y, double rot_z)
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
void	project(int *x, int *y, int *z)
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
