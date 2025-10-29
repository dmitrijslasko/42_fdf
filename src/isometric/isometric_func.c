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
	*x *= view->xy_dist * view->zoom;
	*y *= view->xy_dist * view->zoom;
	*z *= view->z_dist * view->zoom;
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
int	apply_isometric_projection(int *x, int *y, int *z, t_view *view)
{
	double  x0 = *x;
	double  y0 = *y;
	double  z0 = *z;
	double  angle_z = deg_to_radians(45.0);
	double  angle_x = deg_to_radians(35.264);

	double  cos_z = cos(angle_z);
	double  sin_z = sin(angle_z);
	double  cos_x = cos(angle_x);
	double  sin_x = sin(angle_x);

	// Rotate around Z-axis
	double x1 = x0 * cos_z - y0 * sin_z;
	double y1 = x0 * sin_z + y0 * cos_z;
	double z1 = z0;

	*x = (int)x1;
	*y = (int)y1;
	*z = (int)z1;  // not needed for drawing, but kept for consistency
	
	int ret = *y + (Y_CENTER - view->origin_y + view->y_off);

	if (view->projection == ISO)
	{
		// Rotate around X-axis
		double x2 = x1;
		double y2 = y1 * cos_x - z1 * sin_x;
		double z2 = y1 * sin_x + z1 * cos_x;

		*x = (int)x2;
		*y = (int)y2;
		*z = (int)z2;  // not needed for drawing, but kept for consistency
	}
	
	return ret;
}