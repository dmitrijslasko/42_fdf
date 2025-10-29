/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_lines.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 11:07:34 by dmlasko           #+#    #+#             */
/*   Updated: 2025/01/19 14:23:39 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_horizontal_line(t_img *img, t_line line)
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

static void	draw_line(t_data *dt, t_coor curr, t_coor next)
{
	if (abs(curr.y_iso - next.y_iso) >= 1)
	{
		draw_vertical_line(dt, curr, next);
		int i = 1;
	}
	else
	{
		img_pix_put(dt->img, curr.x_iso, curr.y_iso, curr.z_clr);
		img_pix_put_buffer(dt, dt->img, curr.x_iso, curr.y_iso, curr.z_depth, RED);
	}
}

void	draw_sloped_line(t_data *dt, t_coor pt_1, t_coor pt_2)
{
	double	slope;
	double	dist;
	t_coor	curr;
	t_coor	next;

	curr = pt_1;
	next = curr;

	while (curr.x_iso < pt_2.x_iso)
	{
		if (curr.x_iso <= -1000 || curr.x_iso >= WINDOW_W + 100)
			return ;
			
		slope = (double)(pt_2.y_iso - pt_1.y_iso) / (pt_2.x_iso - pt_1.x_iso);

		curr.y_iso = pt_1.y_iso + (curr.x_iso - pt_1.x_iso) * slope;

		dist = ((double)curr.x_iso - pt_1.x_iso) / (pt_2.x_iso - pt_1.x_iso);
		curr.z_depth = pt_1.z_depth - (pt_2.z_depth - pt_1.z_depth) * dist;

		curr.z_clr = get_color_between_nodes(dt, pt_1, pt_2, dist);
		curr.z_clr_custom = curr.z_clr;

		next.x_iso = curr.x_iso + 1;
		next.y_iso = pt_1.y_iso + (next.x_iso - pt_1.x_iso) * slope;

		if (slope < 0 && slope > -1)
			next.y_iso += 1;

		dist = ((double)next.x_iso - curr.x_iso) / (pt_2.x_iso - curr.x_iso);

		next.z_depth = curr.z_depth - (pt_2.z_depth - curr.z_depth) * dist;
		printf("DEPTH: %d\n", next.z_depth);
		next.z_clr = get_color_between_nodes(dt, curr, pt_2, dist);
		next.z_clr_custom = next.z_clr;

		draw_line(dt, curr, next);
		++curr.x_iso;
	}

}

void	connect_two_nodes(t_data *dt, t_coor *coor_1, t_coor *coor_2)
{
	// perfectly vertical line
	if (coor_1->x_iso == coor_2->x_iso)
	{
		draw_vertical_line(dt, *coor_1, *coor_2);
		return ;
	}
	
	// sloped line
	if (coor_1->x_iso < coor_2->x_iso)
		draw_sloped_line(dt, *coor_1, *coor_2);
	else
		draw_sloped_line(dt, *coor_2, *coor_1);
}
