/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_mouse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 10:54:14 by dmlasko           #+#    #+#             */
/*   Updated: 2024/11/29 11:06:30 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// Handle mouse scroll - zoom
static int	mouse_zoom(int key, t_data *data)
{
	if (key == MOUSE_SCROLL_UP)
	{
		data->view->zoom *= (1 + MOUSE_SENS_SCROLL);
		data->view->zoom = fmin(data->view->zoom, MAX_ZOOM);
	}
	if (key == MOUSE_SCROLL_DOWN)
	{
		data->view->zoom /= (1 + MOUSE_SENS_SCROLL);
		data->view->zoom = fmax(data->view->zoom, MIN_ZOOM);
	}
	return (0);
}

// Handle mouse press
int	mouse_press(int button, int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	if (data->view->show_welcome)
		return (1);
	if (button == MOUSE_SCROLL_UP || button == MOUSE_SCROLL_DOWN)
		mouse_zoom(button, data);
	if (button == MOUSE_LEFT_BUTTON)
		data->mouse->lmb_is_pressed = TRUE;
	if (button == MOUSE_THIRD_BUTTON)
		data->mouse->rmb_is_pressed = TRUE;
	return (0);
}

// Handle mouse release
int	mouse_release(int button, int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	(void)button;
	if (data->view->show_welcome)
		return (1);
	if (button == MOUSE_LEFT_BUTTON)
		data->mouse->lmb_is_pressed = FALSE;
	if (button == MOUSE_THIRD_BUTTON)
		data->mouse->rmb_is_pressed = FALSE;
	return (0);
}

static void	set_offs(t_data *data, int x, int y)
{
	t_view	*view;

	view = data->view;
	data->view->x_off += (x - data->mouse->previous_x) * MOUSE_SENS_DRAG;
	if (data->view->x_off > 0)
		data->view->x_off = fmin(view->x_off, DEF_DRAG_LIM * view->zoom);
	else
		view->x_off = fmax(view->x_off, -DEF_DRAG_LIM * view->zoom);
	view->y_off += (y - data->mouse->previous_y) * MOUSE_SENS_DRAG;
	if (view->y_off > 0)
		view->y_off = fmin(view->y_off, DEF_DRAG_LIM * view->zoom);
	else
		view->y_off = fmax(view->y_off, -DEF_DRAG_LIM * view->zoom);
}

// Handle mouse move
int	mouse_move(int x, int y, t_data *data)
{
	t_view	*view;

	view = data->view;
	data->mouse->previous_x = data->mouse->x;
	data->mouse->previous_y = data->mouse->y;
	data->mouse->x = x;
	data->mouse->y = y;
	if (view->show_welcome)
		return (1);
	if (data->mouse->rmb_is_pressed)
	{
		if (y > view->c_y)
			view->rot_z += (data->mouse->previous_x - x) * MOUSE_SENS_ROTATE;
		else
			view->rot_z -= (data->mouse->previous_x - x) * MOUSE_SENS_ROTATE;
		reset_all_angle_degrees(data);
	}
	if (data->mouse->lmb_is_pressed)
		set_offs(data, x, y);
	return (0);
}
