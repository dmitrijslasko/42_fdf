/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_mouse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 10:54:14 by dmlasko           #+#    #+#             */
/*   Updated: 2024/12/03 11:15:27 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// Handle mouse scroll - zoom
static int	mouse_zoom(int key, t_data *dt)
{
	if (key == MOUSE_SCROLL_UP)
	{
		dt->view->zoom *= (1 + MOUSE_SENS_SCROLL);
		dt->view->zoom = fmin(dt->view->zoom, MAX_ZOOM);
	}
	if (key == MOUSE_SCROLL_DOWN)
	{
		dt->view->zoom /= (1 + MOUSE_SENS_SCROLL);
		dt->view->zoom = fmax(dt->view->zoom, MIN_ZOOM);
	}
	return (0);
}

// Handle mouse press
int	mouse_press(int button, int x, int y, t_data *dt)
{
	(void)x;
	(void)y;
	if (dt->view->show_welcome_img)
		return (1);
	if (button == MOUSE_SCROLL_UP || button == MOUSE_SCROLL_DOWN)
		mouse_zoom(button, dt);
	if (button == MOUSE_LEFT_BUTTON)
		dt->mouse->lmb_is_pressed = TRUE;
	if (button == MOUSE_THIRD_BUTTON)
		dt->mouse->rmb_is_pressed = TRUE;
	return (0);
}

// Handle mouse release
int	mouse_release(int button, int x, int y, t_data *dt)
{
	(void)x;
	(void)y;
	(void)button;
	if (dt->view->show_welcome_img)
		return (1);
	if (button == MOUSE_LEFT_BUTTON)
		dt->mouse->lmb_is_pressed = FALSE;
	if (button == MOUSE_THIRD_BUTTON)
		dt->mouse->rmb_is_pressed = FALSE;
	return (0);
}

static void	set_offs(t_data *dt, int x, int y)
{
	t_view	*view;

	view = dt->view;
	dt->view->x_off += (x - dt->mouse->previous_x) * MOUSE_SENS_DRAG;
	if (dt->view->x_off > 0)
		dt->view->x_off = fmin(view->x_off, DEF_DRAG_LIM * view->zoom);
	else
		view->x_off = fmax(view->x_off, -DEF_DRAG_LIM * view->zoom);
	view->y_off += (y - dt->mouse->previous_y) * MOUSE_SENS_DRAG;
	if (view->y_off > 0)
		view->y_off = fmin(view->y_off, DEF_DRAG_LIM * view->zoom);
	else
		view->y_off = fmax(view->y_off, -DEF_DRAG_LIM * view->zoom);
}

// Handle mouse move
int	mouse_move(int x, int y, t_data *dt)
{
	t_view	*view;

	view = dt->view;
	dt->mouse->previous_x = dt->mouse->x;
	dt->mouse->previous_y = dt->mouse->y;
	dt->mouse->x = x;
	dt->mouse->y = y;
	if (view->show_welcome_img)
		return (1);
	if (dt->mouse->rmb_is_pressed)
	{
		if (y > view->bounding_box_center_y)
			view->rot_z += (dt->mouse->previous_x - x) * MOUSE_SENS_ROTATE;
		else
			view->rot_z -= (dt->mouse->previous_x - x) * MOUSE_SENS_ROTATE;
		reset_all_angle_degrees_data(dt);
	}
	if (dt->mouse->lmb_is_pressed)
		set_offs(dt, x, y);
	return (0);
}
