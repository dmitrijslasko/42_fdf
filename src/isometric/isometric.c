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
