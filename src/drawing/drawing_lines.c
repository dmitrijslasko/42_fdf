/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_lines.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 11:07:34 by dmlasko           #+#    #+#             */
/*   Updated: 2024/12/01 20:20:38 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_hor_line(t_img *img, t_line line)
{
	int	curr_x;
	int	temp;

	if (line.x1 > line.x2)
	{
		temp = line.x1;
		line.x1 = line.x2;
		line.x2 = temp;
	}
	curr_x = line.x1;
	while (curr_x <= line.x2)
	{
		img_pix_put(img, curr_x, line.y1, line.clr);
		++curr_x;
	}
}

static void	draw_line(t_data *data, t_coor curr, t_coor next)
{
	if (abs(curr.y_iso - next.y_iso) > 1)
	{
		if (curr.y_iso < next.y_iso)
			draw_vert_line2(data->img, curr.x_iso, curr.y_iso, next.y_iso, curr.z_clr, next.z_clr);
		else
			draw_vert_line2(data->img, curr.x_iso, curr.y_iso, next.y_iso, next.z_clr, curr.z_clr);
	}
	else
		img_pix_put(data->img, curr.x_iso, curr.y_iso, curr.z_clr);
}

void	draw_sloped_line(t_data *data, t_coor pt_1, t_coor pt_2)
{
	double	slope;
	double	distance;
	t_coor	curr;
	t_coor	next;

	curr = pt_1;
	next = curr;
	while (curr.x_iso < pt_2.x_iso)
	{
		slope = (double)(pt_2.y_iso - pt_1.y_iso) / (pt_2.x_iso - pt_1.x_iso);
		curr.y_iso = pt_1.y_iso + (curr.x_iso - pt_1.x_iso) * slope;
		distance = ((double)curr.x_iso - pt_1.x_iso) / (pt_2.x_iso - pt_1.x_iso);
		curr.z_clr = get_clr_bween_points(data, pt_1, pt_2, distance);
		next.x_iso = curr.x_iso + 1;
		next.y_iso = pt_1.y_iso + (next.x_iso - pt_1.x_iso) * slope;
		distance = ((double)next.x_iso - curr.x_iso) / (pt_2.x_iso - curr.x_iso);
		next.z_clr = get_clr_bween_points(data, curr, pt_2, distance);
		draw_line(data, curr, next);
		++curr.x_iso;
	}
}

void	connect_two_nodes(t_data *data, t_coor *coor_1, t_coor *coor_2)
{
	if (coor_1->x_iso == coor_2->x_iso)
	{
		draw_vert_line(data, *coor_1, *coor_2);
		return ;
	}
	if (coor_1->x_iso < coor_2->x_iso)
		draw_sloped_line(data, *coor_1, *coor_2);
	else
		draw_sloped_line(data, *coor_2, *coor_1);
}
