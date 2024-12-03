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
		if (dt->view->show_welcome)
			dt->view->show_welcome = FALSE;
	}
	return (0);
}

static int	keypress_presetup_views(int key, t_data *dt)
{
	reset_angle(dt);
	if (key == XK_i)
		dt->view->projection = ISO;
	if (key == XK_p)
		dt->view->projection = PARALLEL;
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
	if (key == XK_n)
	{
		if (dt->view->show_nodes)
			dt->view->show_nodes = FALSE;
		else
			dt->view->show_nodes = TRUE;
		dt->view->node_size += 1;
	}
	if (key == XK_l)
	{
		if (dt->view->lang == EN)
			dt->view->lang = DE;
		else
			dt->view->lang = EN;
	}
	return (0);
}

int	handle_keypress(int key, t_data *dt)
{
	if (key == ESC_BUTTON)
		keypress_exit(key, dt);
	if (key == XK_space)
		keypress_welcome_screen(key, dt);
	if (dt->view->show_welcome)
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
	if (key == XK_slash || key == XK_n || key == XK_l)
		keypress_show_admin(key, dt);
	if (key == XK_r)
		keypress_reset_offs(key, dt);
	if (key == XK_1 || key == XK_2 || key == XK_3)
		keypress_switch_clrs(key, dt);
	return (0);
}

// int	handle_keyrelease(int key, void *dt)
// {
// 	printf("Keyrelease: %d\n", key);
// 	return (0);
// }
