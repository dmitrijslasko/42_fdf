/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_keys.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 10:54:08 by dmlasko           #+#    #+#             */
/*   Updated: 2024/12/02 18:33:35 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "controls.h"

static int	keypress_exit(int key, t_data *data)
{
	if (key == ESC_BUTTON)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
	}
	return (0);
}

static int	keypress_welcome_screen(int key, t_data *data)
{
	if (key == XK_space)
	{
		if (data->view->show_welcome)
			data->view->show_welcome = FALSE;
	}
	return (0);
}

static int	keypress_presetup_views(int key, t_data *data)
{
	reset_angle(data);
	if (key == XK_i)
		data->view->projection = ISO;
	if (key == XK_p)
		data->view->projection = PARALLEL;
	return (0);
}

static int	keypress_show_admin(int key, t_data *data)
{
	if (key == XK_slash)
	{
		if (data->view->show_admin)
			data->view->show_admin = FALSE;
		else
			data->view->show_admin = TRUE;
	}
	if (key == XK_n)
	{
		if (data->view->show_nodes)
			data->view->show_nodes = FALSE;
		else
			data->view->show_nodes = TRUE;
		data->view->node_size += 1;
	}
	if (key == XK_l)
	{
		if (data->view->lang == EN)
			data->view->lang = DE;
		else
			data->view->lang = EN;
	}
	return (0);
}

int	handle_keypress(int key, t_data *data)
{
	if (key == ESC_BUTTON)
		keypress_exit(key, data);
	if (key == XK_space)
		keypress_welcome_screen(key, data);
	if (data->view->show_welcome)
		return (1);
	if (key == XK_minus || key == XK_equal)
		keypress_zoom(key, data);
	if (key == XK_bracketright || key == XK_bracketleft)
		keypress_z_dist(key, data);
	if (key == XK_Up || key == XK_Down || key == XK_Left || key == XK_Right)
		keypress_set_offs(key, data);
	if (key == XK_q || key == XK_w || key == XK_a || key == XK_s || \
		key == XK_z || key == XK_x)
		keypress_rotation(key, data);
	if (key == XK_i || key == XK_p)
		keypress_presetup_views(key, data);
	if (key == XK_slash || key == XK_n || key == XK_l)
		keypress_show_admin(key, data);
	if (key == XK_r)
		keypress_reset_offs(key, data);
	if (key == XK_1 || key == XK_2 || key == XK_3)
		keypress_switch_clrs(key, data);
	return (0);
}

// int	handle_keyrelease(int key, void *data)
// {
// 	printf("Keyrelease: %d\n", key);
// 	return (0);
// }
