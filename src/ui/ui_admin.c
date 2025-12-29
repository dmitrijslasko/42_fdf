/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_admin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 11:07:27 by dmlasko           #+#    #+#             */
/*   Updated: 2024/12/03 17:27:14 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	draw_crosshair(t_data *dt, int x, int y, int clr)
{
	t_line	line;

	line.x1 = x;
	line.y1 = y - CENTER_LINE_PX;
	line.y2 = y - CL_MARGIN;
	
	line.color = clr;
	draw_single_color_vertical_line(dt->img, line);

	line.y1 = y + CENTER_LINE_PX;
	line.y2 = y + CL_MARGIN;
	draw_single_color_vertical_line(dt->img, line);

	line.x1 = x - CENTER_LINE_PX;
	line.x2 = x - CL_MARGIN;
	line.y1 = y;
	draw_horizontal_line(dt->img, line);

	line.x1 = CENTER_LINE_PX + x;
	line.x2 = CL_MARGIN + x;
	draw_horizontal_line(dt->img, line);

	draw_node(dt, x, y, clr);
}

static void	draw_bounding_box(t_data *dt)
{
	t_line	line;

	line.x1 = dt->view->bounding_box_min_x;
	line.x2 = dt->view->bounding_box_max_x;
	line.y1 = dt->view->bounding_box_min_y;
	line.color = BBOX_COLOR;
	draw_horizontal_line(dt->img, line);

	line.y1 = dt->view->bounding_box_max_y;
	draw_horizontal_line(dt->img, line);

	line.y2 = dt->view->bounding_box_max_y;
	line.x2 = dt->view->bounding_box_min_x;
	draw_single_color_vertical_line(dt->img, line);
	
	line.x1 = dt->view->bounding_box_max_x;
	line.x2 = dt->view->bounding_box_max_x;
	draw_single_color_vertical_line(dt->img, line);
}

void	show_admin(t_data *dt)
{
	draw_crosshair(dt, dt->view->origin_x_iso, dt->view->origin_y_iso, RED);
	draw_crosshair(dt, X_CENTER, Y_CENTER, GREEN);
	draw_crosshair(dt, dt->view->bounding_box_center_x, dt->view->bounding_box_center_y, YELLOW);
	update_bounding_box(dt);
	draw_bounding_box(dt);
}
