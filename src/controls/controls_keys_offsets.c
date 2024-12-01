/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_keys_offs.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 10:53:46 by dmlasko           #+#    #+#             */
/*   Updated: 2024/11/29 10:56:50 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	keypress_set_offs(int key, t_data *data)
{
	if (key == XK_Up)
		data->view->y_off += DEF_KEY_OFFSET;
	if (key == XK_Down)
		data->view->y_off -= DEF_KEY_OFFSET;
	if (key == XK_Left)
		data->view->x_off += DEF_KEY_OFFSET;
	if (key == XK_Right)
		data->view->x_off -= DEF_KEY_OFFSET;
	return (0);
}

int	keypress_reset_offs(int key, t_data *data)
{
	if (key == XK_r)
	{
		data->view->x_off = 0;
		data->view->y_off = 0;
		reset_angle(data);
	}
	return (0);
}
