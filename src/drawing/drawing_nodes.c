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

void	draw_node(t_data *dt, t_node *node, int clr)
{
	int	curr_x;
	int	curr_y;

	curr_x = node->x_iso - dt->view->node_size / 2;
	while (curr_x <= node->x_iso + dt->view->node_size / 2)
	{
		curr_y = node->y_iso - dt->view->node_size / 2;
		while (curr_y <= node->y_iso + dt->view->node_size / 2)
		{
			if (pixel_is_in_window(curr_x, curr_y) == 0)
				;
			else if (dt->z_buffer_map[curr_y][curr_x] < node->z_depth)
			{
				img_pix_put(dt->img, curr_x, curr_y, clr);
				dt->z_buffer_map[curr_y][curr_x] = node->z_depth;
			}
			++curr_y;
		}
		++curr_x;
	}
}
