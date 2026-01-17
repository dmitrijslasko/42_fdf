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

int	keypress_set_offs(int key, t_data *dt)
{
	if (key == XK_Up)
		dt->view->y_off += DEF_KEY_OFFSET;
	if (key == XK_Down)
		dt->view->y_off -= DEF_KEY_OFFSET;
	if (key == XK_Left)
		dt->view->x_off += DEF_KEY_OFFSET;
	if (key == XK_Right)
		dt->view->x_off -= DEF_KEY_OFFSET;
	return (0);
}

int	keypress_reset_offs(int key, t_data *dt)
{
	if (key == XK_r)
	{
		dt->view->x_off = 0;
		dt->view->y_off = 0;
		reset_rotation(dt);
	}
	return (0);
}
