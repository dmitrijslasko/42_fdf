/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gradients.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 11:37:01 by dmlasko           #+#    #+#             */
/*   Updated: 2024/12/02 12:30:01 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	get_clr_value(int clr, int bit_shift)
{
	return ((clr >> bit_shift) & 0xFF);
}

static int	get_clr_distance(int start_clr, int end_clr, int bit_shift)
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

int	get_clr_bween_clrs(double distance, int start_clr, int end_clr)
{
	t_rgb	s_start_clr;
	t_rgb	resulting_clr;
	t_rgb	clr_diff;

	s_start_clr.r = get_clr_value(start_clr, 16);
	s_start_clr.g = get_clr_value(start_clr, 8);
	s_start_clr.b = get_clr_value(start_clr, 0);
	clr_diff.r = get_clr_distance(start_clr, end_clr, 16);
	clr_diff.g = get_clr_distance(start_clr, end_clr, 8);
	clr_diff.b = get_clr_distance(start_clr, end_clr, 0);
	resulting_clr.rgb = pack_rgb(s_start_clr.r + (distance * clr_diff.r), \
									s_start_clr.g + (distance * clr_diff.g), \
									s_start_clr.b + (distance * clr_diff.b));
	return (resulting_clr.rgb);
}

int	get_clr_bween_points(t_data *dt, t_coor pt_1, t_coor pt_2, double dist)
{
	int		pixel_clr;

	if (dt->view->use_custom_clrs)
		pixel_clr = get_clr_bween_clrs(dist, pt_1.z_clr_custom, pt_2.z_clr_custom);
	else
		pixel_clr = get_clr_bween_clrs(dist, pt_1.z_clr, pt_2.z_clr);
	return (pixel_clr);
}

int	update_colors(t_data *data, t_map *map)
{
	int row;
	int col;
	t_view *v;
	t_coor coor;

	v = data->view;
	row = 0;
	while (row < map->height)
	{
		col = 0;
		while (col < map->width)
		{
			coor = map->coor[row][col];
			coor.z_clr_custom = get_clr_bween_clrs(coor.z_rel, v->lo_clr, v->hi_clr);
			map->coor[row][col] = coor;
			++col;
		}
		++row;
	}
	return (0);
}
