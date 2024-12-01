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

void	draw_vert_line(t_data *data, t_coor pt_1, t_coor pt_2)
{
	int		curr_y;
	int		pixel_clr;
	double	distance;

	if (pt_1.y_iso > pt_2.y_iso)
		swap(&pt_1, &pt_2, sizeof(t_coor));
	curr_y = pt_1.y_iso;
	while (curr_y < pt_2.y_iso)
	{
		distance = ((double)curr_y - pt_1.y_iso) / (pt_2.y_iso - pt_1.y_iso);
		pixel_clr = get_clr_between_points(data, pt_1, pt_2, distance);
		img_pix_put(data->img, pt_1.x_iso, curr_y, pixel_clr);
		++curr_y;
	}
}

void	draw_vert_line2(t_img *img, int x, int y1, int y2, int clr, int clr2)
{
	int		curr_y;
	int		pixel_clr;
	double	distance;

	if (y1 > y2)
		swap(&y1, &y2, sizeof(int));
	curr_y = y1;
	while (curr_y < y2)
	{
		distance = ((double)curr_y - y1) / (y2 - y1);
		pixel_clr = get_clr_between_clrs(distance, clr, clr2);
		img_pix_put(img, x, curr_y, pixel_clr);
		++curr_y;
	}
}

void	draw_vert_line3(t_img *img, t_line line)
{
	int	curr_y;
	int	temp;

	if (line.y1 > line.y2)
	{
		temp = line.y1;
		line.y1 = line.y2;
		line.y2 = temp;
	}
	curr_y = line.y1;
	while (curr_y < line.y2)
	{
		img_pix_put(img, line.x1, curr_y, line.clr);
		++curr_y;
	}
}
