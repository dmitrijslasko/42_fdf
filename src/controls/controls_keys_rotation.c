/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_keys_rotation.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 10:53:52 by dmlasko           #+#    #+#             */
/*   Updated: 2024/12/03 11:14:46 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	keypress_rotation(int key, t_data *dt)
{
	if (key == XK_q)
		dt->view->rot_x -= DEF_ROTATE_STEP;
	if (key == XK_w)
		dt->view->rot_x += DEF_ROTATE_STEP;
	if (key == XK_a)
		dt->view->rot_y -= DEF_ROTATE_STEP;
	if (key == XK_s)
		dt->view->rot_y += DEF_ROTATE_STEP;
	if (key == XK_z)
		dt->view->rot_z -= DEF_ROTATE_STEP;
	if (key == XK_x)
		dt->view->rot_z += DEF_ROTATE_STEP;
	return (0);
}
