/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 11:36:37 by dmlasko           #+#    #+#             */
/*   Updated: 2024/12/03 18:41:49 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_view(t_view *v)
{
	v->show_welcome_img = SHOW_WELCOME_IMAGE;
	v->show_admin = FALSE;
	v->show_lines = SHOW_LINES;
	v->show_nodes = SHOW_NODES;
	v->ui_language = ENGLISH;
	v->node_size = NODE_SIZE;
	v->use_custom_colors = FALSE;
	v->hi_clr = SCHEME_1_HI;
	v->lo_clr = SCHEME_1_LO;
	v->bg_clr = DEF_BG_COLOR;
	v->xy_dist = XY_DIST;
	v->z_dist = Z_DIST;
	v->projection_type = DEF_PROJECTION;
	v->x_off = DEF_OFFSET_X;
	v->y_off = DEF_OFFSET_Y;
	v->zoom = DEF_STARTING_ZOOM;
	v->rot_x = DEF_ISO_ROT_X;
	v->rot_y = DEF_ISO_ROT_Y;
	v->rot_z = DEF_ISO_ROT_Z;
}

void	setup_view(t_data *dt)
{
	t_view	*v;
	t_map	*m;

	v = dt->view;
	m = dt->map;
	v->xy_dist = WINDOW_W / m->width;
	v->z_dist = (int)v->xy_dist / 5;
	
	if (m->has_color_info)
		v->use_custom_colors = 0;
	
	dt->view->auto_rotate = 0;
	dt->view->auto_rotate_axis = 1;
	dt->view->auto_rotate_zoom_dir = 1;
	dt->view->show_controls = 1;
}

static void	reset_bounding_box(t_data *dt)
{
	dt->view->bounding_box_max_x = INT_MIN;
	dt->view->bounding_box_min_x = INT_MAX;
	dt->view->bounding_box_min_y = INT_MIN;
	dt->view->bounding_box_max_y = INT_MAX;
}

void	update_bounding_box(t_data *dt)
{
	int		row;
	int		col;
	t_view	*v;

	v = dt->view;
	reset_bounding_box(dt);

	row = 0;
	while (row < dt->map->height)
	{
		col = 0;
		while (col < dt->map->width)
		{
			dt->view->bounding_box_max_x = fmax(v->bounding_box_max_x, dt->map->nodes[row][col].x_iso);
			v->bounding_box_min_x = fmin(v->bounding_box_min_x, dt->map->nodes[row][col].x_iso);
			v->bounding_box_min_y = fmin(v->bounding_box_min_y, dt->map->nodes[row][col].y_iso);
			v->bounding_box_max_y = fmax(v->bounding_box_max_y, dt->map->nodes[row][col].y_iso);
			++col;
		}
		++row;
	}

	// center
	v->bounding_box_center_x = (v->bounding_box_max_x + v->bounding_box_min_x) / 2;
	v->bounding_box_center_y = (v->bounding_box_max_y + v->bounding_box_min_y) / 2;
}

void	update_origin_coor(t_data *dt)
{
	int x;
	int y;
	int z;

	x = ((double)dt->map->width - 1) / 2;
	y = ((double)dt->map->height - 1) / 2;
	z = 0;

	get_iso_coor(&x, &y, &z, dt->view);

	dt->view->origin_x_iso = x;
	dt->view->origin_y_iso = y;
}
