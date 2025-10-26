/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_keys_scale.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 10:53:57 by dmlasko           #+#    #+#             */
/*   Updated: 2024/12/03 11:15:03 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	keypress_zoom(int key, t_data *dt)
{
	if (key == XK_equal)
	{
		dt->view->zoom *= (1 + KEYBOARD_ZOOM);
		dt->view->zoom = fmin(dt->view->zoom, MAX_ZOOM);
	}
	if (key == XK_minus)
	{
		dt->view->zoom /= (1 + KEYBOARD_ZOOM);
		dt->view->zoom = fmax(dt->view->zoom, MIN_ZOOM);
	}
	return (0);
}

int	keypress_z_dist(int key, t_data *dt)
{
	if (key == XK_bracketright)
	{
		dt->view->z_dist += DEF_Z_STEP;
	}

	if (key == XK_bracketleft)
		dt->view->z_dist = fmax(0, dt->view->z_dist - DEF_Z_STEP);
	return (0);
}
