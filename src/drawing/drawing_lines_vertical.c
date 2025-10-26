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

void	draw_vert_line(t_data *dt, t_coor pt_1, t_coor pt_2)
{
	int		curr_y;
	int		pixel_clr;
	double	dist;

	if (pt_1.y_iso > pt_2.y_iso)
		swap(&pt_1, &pt_2, sizeof(t_coor));
	curr_y = pt_1.y_iso;
	while (curr_y < pt_2.y_iso)
	{
		if (curr_y < 0 - 1000 || curr_y >= WINDOW_H)
			return ;
		dist = ((double)curr_y - pt_1.y_iso) / (pt_2.y_iso - pt_1.y_iso);
		if (dt->view->use_custom_clrs)
			pixel_clr = get_clr_bween_clrs(dist, pt_1.z_clr_custom, \
							pt_2.z_clr_custom);
		else
			pixel_clr = get_clr_bween_clrs(dist, pt_1.z_clr, pt_2.z_clr);
		img_pix_put(dt->img, pt_1.x_iso, curr_y, pixel_clr);
		// img_pix_put_buffer(dt, dt->img, pt_1.x_iso, curr_y, curr.z_depth, curr.z_clr);
		++curr_y;
	}
}

void	draw_single_clr_line(t_img *img, t_line line)
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
