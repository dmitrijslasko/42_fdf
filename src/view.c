/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 11:36:37 by dmlasko           #+#    #+#             */
/*   Updated: 2024/12/01 21:51:40 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_view(t_view *v)
{
	v->show_welcome = SHOW_WELCOME_IMAGE;
	v->show_admin = FALSE;
	v->show_nodes = DRAW_NODES;
	v->node_size = NODE_SIZE;
	v->use_custom_clrs = TRUE;
	v->hi_clr = SCHEME_1_HI;
	v->lo_clr = SCHEME_1_LO;
	v->bg_clr = DEF_BG_COLOR;
	v->xy_distance = XY_DISTANCE;
	v->projection = DEF_PROJECTION;
	v->x_off = DEF_OFFSET_X;
	v->y_off = DEF_OFFSET_Y;
	v->zoom = DEF_STARTING_ZOOM;
	v->rot_x = DEF_ISO_ROT_X;
	v->rot_y = DEF_ISO_ROT_Y;
	v->rot_z = DEF_ISO_ROT_Z;
}

void	setup_view(t_data *data)
{
	t_view *v;
	t_map *m;

	v = data->view;
	m = data->map;
	v->xy_distance = WINDOW_W / m->width;
	v->z_distance = v->xy_distance / 2;
	if (m->has_clr_info)
		v->use_custom_clrs = 0;
}
void	reset_bounding_box(t_data *data)
{
	data->view->x_max = INT_MIN;
	data->view->x_min = INT_MAX;
	data->view->y_max = INT_MIN;
	data->view->y_min = INT_MAX;
}

void	update_bounding_box(t_data *data)
{
	int		row;
	int		col;
	t_view	*v;

	v = data->view;
	reset_bounding_box(data);
	row = 0;
	while (row < data->map->height)
	{
		col = 0;
		while (col < data->map->width)
		{
			data->view->x_max = fmax(v->x_max, data->map->coor[col][row].x_iso);
			v->x_min = fmin(v->x_min, data->map->coor[col][row].x_iso);
			v->y_max = fmax(v->y_max, data->map->coor[col][row].y_iso);
			v->y_min = fmin(v->y_min, data->map->coor[col][row].y_iso);
			++col;
		}
		++row;
	}
	v->c_x = (v->x_max + v->x_min) / 2;
	v->c_y = (v->y_max + v->y_min) / 2;
}

t_coor	update_origin_coor(t_data *data)
{
	t_map	*map;
	t_view	*view;
	t_coor	origin;
	int		z;

	map = data->map;
	view = data->view;
	origin.x = ((double)map->width - 1) / 2;
	origin.y = ((double)map->height - 1) / 2;
	z = 0;
	get_iso_coor(&origin.x, &origin.y, &z, view);
	view->origin_x = origin.x;
	view->origin_y = origin.y;
	return (origin);
}
