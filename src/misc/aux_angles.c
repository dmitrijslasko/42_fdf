/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_angles.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:52:32 by dmlasko           #+#    #+#             */
/*   Updated: 2024/12/03 17:12:13 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	reset_angle_degrees(double *angle)
{
	*angle = fmax(*angle, *angle + 360);
	*angle = fmod(*angle, 360);
}

void	reset_all_angle_degrees_data(t_data *data)
{
	reset_angle_degrees(&data->view->rot_x);
	reset_angle_degrees(&data->view->rot_y);
	reset_angle_degrees(&data->view->rot_z);
}

double	deg_to_radians(double angle)
{
	return (angle * (3.14 / 180.0));
}

void	reset_rotation(t_data *data)
{
	data->view->rot_x = DEF_ISO_ROT_X;
	data->view->rot_y = DEF_ISO_ROT_Y;
	data->view->rot_z = DEF_ISO_ROT_Z;
}
