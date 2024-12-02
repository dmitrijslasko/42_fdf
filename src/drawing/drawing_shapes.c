/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_shapes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 11:07:54 by dmlasko           #+#    #+#             */
/*   Updated: 2024/12/02 16:53:35 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	draw_rectangle(t_img *img, t_coor *point_1, t_coor *point_2, int clr)
{
	int	current_x;
	int	current_y;

	current_x = point_1->x;
	while (current_x < point_2->x)
	{
		current_y = point_1->y;
		while (current_y < point_2->y)
			img_pix_put(img, current_y++, current_x, clr);
		++current_x;
	}
	return (0);
}
