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
	line.clr = clr;
	draw_single_clr_line(dt->img, line);

	line.y1 = y + CENTER_LINE_PX;
	line.y2 = y + CL_MARGIN;
	draw_single_clr_line(dt->img, line);

	line.x1 = x - CENTER_LINE_PX;
	line.x2 = x - CL_MARGIN;
	line.y1 = y;
	draw_hor_line(dt->img, line);

	line.x1 = CENTER_LINE_PX + x;
	line.x2 = CL_MARGIN + x;
	draw_hor_line(dt->img, line);

	draw_node(dt, x, y, clr);
}

static void	draw_bounding_box(t_data *data)
{
	t_line	line;

	line.x1 = data->view->x_min;
	line.x2 = data->view->x_max;
	line.y1 = data->view->y_min;
	line.clr = BBOX_COLOR;
	draw_hor_line(data->img, line);

	line.y1 = data->view->y_max;
	draw_hor_line(data->img, line);

	line.y2 = data->view->y_min;
	line.x2 = data->view->x_min;
	draw_single_clr_line(data->img, line);
	
	line.x1 = data->view->x_max;
	line.x2 = data->view->x_max;
	draw_single_clr_line(data->img, line);
}

void	show_admin(t_data *data)
{
	draw_crosshair(data, data->view->origin_x, data->view->origin_y, RED);
	draw_crosshair(data, X_CENTER, Y_CENTER, GREEN);
	draw_crosshair(data, data->view->c_x, data->view->c_y, YELLOW);
	draw_bounding_box(data);
}
