/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_keys_scale.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 10:53:57 by dmlasko           #+#    #+#             */
/*   Updated: 2024/12/03 10:51:30 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	keypress_zoom(int key, t_data *data)
{
	if (key == XK_equal)
	{
		data->view->zoom *= (1 + KEYBOARD_ZOOM);
		data->view->zoom = fmin(data->view->zoom, MAX_ZOOM);
	}
	if (key == XK_minus)
	{
		data->view->zoom /= (1 + KEYBOARD_ZOOM);
		data->view->zoom = fmax(data->view->zoom, MIN_ZOOM);
	}
	return (0);
}

int	keypress_z_dist(int key, t_data *data)
{
	if (key == XK_bracketright)
		data->view->z_dist += DEF_Z_STEP;
	if (key == XK_bracketleft)
		data->view->z_dist = fmax(0, data->view->z_dist - DEF_Z_STEP);
	return (0);
}
