/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gradients.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 11:37:01 by dmlasko           #+#    #+#             */
/*   Updated: 2024/12/03 10:34:02 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	get_clr_value(int clr, int bit_shift)
{
	return ((clr >> bit_shift) & 0xFF);
}

static int	get_clr_dist(int start_clr, int end_clr, int bit_shift)
{
	int	start_clr_value;
	int	end_clr_value;

	start_clr_value = get_clr_value(start_clr, bit_shift);
	end_clr_value = get_clr_value(end_clr, bit_shift);
	return (end_clr_value - start_clr_value);
}

unsigned int	pack_rgb(int red, int green, int blue)
{
	red = fmax(fmin(red, 255), 0);
	green = fmax(fmin(green, 255), 0);
	blue = fmax(fmin(blue, 255), 0);
	return ((red << 16) | (green << 8) | blue);
}

int	get_clr_bween_clrs(double dist, int start_clr, int end_clr)
{
	t_rgb	s_start_clr;
	t_rgb	resulting_clr;
	t_rgb	color_difference;

	s_start_clr.r = get_clr_value(start_clr, 16);
	s_start_clr.g = get_clr_value(start_clr, 8);
	s_start_clr.b = get_clr_value(start_clr, 0);

	color_difference.r = get_clr_dist(start_clr, end_clr, 16);
	color_difference.g = get_clr_dist(start_clr, end_clr, 8);
	color_difference.b = get_clr_dist(start_clr, end_clr, 0);
	
	resulting_clr.rgb = pack_rgb(s_start_clr.r + (dist * color_difference.r), \
									s_start_clr.g + (dist * color_difference.g), \
									s_start_clr.b + (dist * color_difference.b));
	return (resulting_clr.rgb);
}

int	get_z_depth_between_nodes(t_data *dt, t_coor pt_1, t_coor pt_2, double dist)
{
	int		pixel_clr;
	t_view	*v;

	v = dt->view;
	if (v->use_custom_clrs)
		pixel_clr = get_clr_bween_clrs(dist, pt_1.z_clr_custom, \
							pt_2.z_clr_custom);
	else
		pixel_clr = get_clr_bween_clrs(dist, pt_1.z_clr, pt_2.z_clr);
	return (pixel_clr);
}

int	get_color_between_nodes(t_data *dt, t_coor pt_1, t_coor pt_2, double dist)
{
	int		pixel_clr;
	t_view	*v;

	v = dt->view;
	if (v->use_custom_clrs)
		pixel_clr = get_clr_bween_clrs(dist, pt_1.z_clr_custom, \
							pt_2.z_clr_custom);
	else
		pixel_clr = get_clr_bween_clrs(dist, pt_1.z_clr, pt_2.z_clr);
	return (pixel_clr);
}
