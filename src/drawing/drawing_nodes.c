/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_nodes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 11:07:47 by dmlasko           #+#    #+#             */
/*   Updated: 2024/12/01 23:03:33 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_node(t_data *data, int x, int y, int clr)
{
	int	curr_x;
	int	curr_y;

	img_pix_put(data->img, x, y, clr);
	curr_x = x - data->view->node_size / 2;
	while (curr_x <= x + data->view->node_size / 2)
	{
		curr_y = y - data->view->node_size / 2;
		while (curr_y <= y + data->view->node_size / 2)
		{
			if (pixel_is_in_window(curr_x, curr_y))
				img_pix_put(data->img, curr_x, curr_y, clr);
			++curr_y;
		}
		++curr_x;
	}
}
