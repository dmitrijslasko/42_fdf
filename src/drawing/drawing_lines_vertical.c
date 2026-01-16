/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_lines_vert.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 11:07:34 by dmlasko           #+#    #+#             */
/*   Updated: 2024/11/29 11:30:15 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_vertical_line(t_data *dt, t_node pt_1, t_node pt_2)
{
	int		curr_y;
	int		pixel_clr;
	double	distance;
	int 	color1;
	int 	color2;

	if (pt_1.y_iso > pt_2.y_iso)
		swap(&pt_1, &pt_2, sizeof(t_node));
	curr_y = pt_1.y_iso;
	while (curr_y < pt_2.y_iso)
	{
		distance = ((double)curr_y - pt_1.y_iso) / (pt_2.y_iso - pt_1.y_iso);
		color1 = pt_1.z_color;
		color2 = pt_2.z_color;
		if (dt->view->use_custom_colors)
		{
			color1 = pt_1.z_clr_custom;
			color2 = pt_2.z_clr_custom;
		}
		pixel_clr = get_color_between_colors(distance, color1, color2);
		// img_pix_put(dt->img, pt_1.x_iso, curr_y, pixel_clr);
		img_pix_put_buffer(dt, dt->img, pt_1.x_iso, curr_y, pt_1.z_depth, pixel_clr);
		++curr_y;
	}
}

void	draw_single_color_vertical_line(t_img *img, t_line line)
{
	int	curr_y;
	int	temp;

	int start_y;

	if (line.y1 > line.y2)
	{
		temp = line.y1;
		line.y1 = line.y2;
		line.y2 = temp;
	}
	curr_y = line.y1;
	while (curr_y < line.y2)
	{
		img_pix_put(img, line.x1, curr_y, line.color);
		++curr_y;
	}
}
