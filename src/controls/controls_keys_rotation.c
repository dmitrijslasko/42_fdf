/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_keys_rotation.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 10:53:52 by dmlasko           #+#    #+#             */
/*   Updated: 2024/11/29 10:57:53 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	keypress_rotation(int key, t_data *data)
{
	if (key == XK_q)
		data->view->rot_x -= DEF_ROTATE_STEP;
	if (key == XK_w)
		data->view->rot_x += DEF_ROTATE_STEP;
	if (key == XK_a)
		data->view->rot_y -= DEF_ROTATE_STEP;
	if (key == XK_s)
		data->view->rot_y += DEF_ROTATE_STEP;
	if (key == XK_z)
		data->view->rot_z -= DEF_ROTATE_STEP;
	if (key == XK_x)
		data->view->rot_z += DEF_ROTATE_STEP;
	reset_all_angle_degrees(data);
	return (0);
}
