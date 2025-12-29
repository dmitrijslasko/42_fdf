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

void	draw_node(t_data *dt, int x, int y, int clr)
{
	int	curr_x;
	int	curr_y;

	curr_x = x - dt->view->node_size / 2;
	while (curr_x <= x + dt->view->node_size / 2)
	{
		curr_y = y - dt->view->node_size / 2;
		while (curr_y <= y + dt->view->node_size / 2)
		{
			img_pix_put(dt->img, curr_x, curr_y, clr);
			++curr_y;
		}
		++curr_x;
	}
}
