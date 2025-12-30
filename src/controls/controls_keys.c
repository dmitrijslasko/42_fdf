/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_keys.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 10:54:08 by dmlasko           #+#    #+#             */
/*   Updated: 2024/12/03 11:15:09 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "controls.h"

static int	keypress_exit(int key, t_data *dt)
{
	if (key == ESC_BUTTON)
	{
		ft_printf("ESC button pressed, closing the window...\n");
		mlx_destroy_window(dt->mlx_ptr, dt->win_ptr);
		dt->win_ptr = NULL;
	}
	return (0);
}

static int	keypress_welcome_screen(int key, t_data *dt)
{
	if (key == XK_space)
	{
		if (dt->view->show_welcome_img)
			dt->view->show_welcome_img = FALSE;
	}
	return (0);
}

static int	keypress_presetup_views(int key, t_data *dt)
{
	// reset_rotation(dt);
	if (key == XK_i)
		dt->view->projection_type = ISOMETRIC;
	if (key == XK_p)
		dt->view->projection_type = PARALLEL;
	return (0);
}

static int	keypress_show_admin(int key, t_data *dt)
{
	if (key == XK_slash)
	{
		if (dt->view->show_admin)
			dt->view->show_admin = FALSE;
		else
			dt->view->show_admin = TRUE;
	}
	if (key == XK_k)
	{
		dt->view->auto_rotate = dt->view->auto_rotate == 0;
		printf("Auto rotation ON/OFF: %d\n", dt->view->auto_rotate);
	}
	if (key == XK_m && dt->view->auto_rotate)
	{
		dt->view->auto_rotate_axis += 1;
		dt->view->auto_rotate_axis %= 3;
		dt->view->auto_rotate_axis += 1;
		// printf("Auto rotation: %d\n", dt->view->auto_rotate_axis);
	}
	if (key == XK_c)
		dt->view->show_controls = !dt->view->show_controls;
	if (key == XK_n)
	{
		dt->view->show_nodes = !dt->view->show_nodes;
		printf("Node mode: %d\n", dt->view->show_nodes);
	}
	if (key == XK_l)
	{
		if (dt->view->ui_language == ENGLISH)
			dt->view->ui_language = DEUTSCH;
		else
			dt->view->ui_language = ENGLISH;
	}
	return (0);
}

int	handle_keypress(int key, t_data *dt)
{
	if (key == ESC_BUTTON)
		keypress_exit(key, dt);
	if (key == XK_space)
		keypress_welcome_screen(key, dt);
	if (dt->view->show_welcome_img)
		return (1);
	if (key == XK_minus || key == XK_equal)
		keypress_zoom(key, dt);
	if (key == XK_bracketright || key == XK_bracketleft)
		keypress_z_dist(key, dt);
	if (key == XK_Up || key == XK_Down || key == XK_Left || key == XK_Right)
		keypress_set_offs(key, dt);
	if (key == XK_q || key == XK_w || key == XK_a || key == XK_s || \
		key == XK_z || key == XK_x)
		keypress_rotation(key, dt);
	if (key == XK_i || key == XK_p)
		keypress_presetup_views(key, dt);
	if (key == XK_slash || key == XK_n || key == XK_k || key == XK_m || key == XK_l || key == XK_c)
		keypress_show_admin(key, dt);
	if (key == XK_r)
		keypress_reset_offs(key, dt);
	if (key == XK_1 || key == XK_2 || key == XK_3 || key == XK_4 || key == XK_5)
		keypress_switch_clrs(key, dt);
	return (0);
}

// int	handle_keyrelease(int key, void *dt)
// {
// 	printf("Keyrelease: %d\n", key);
// 	return (0);
// }
