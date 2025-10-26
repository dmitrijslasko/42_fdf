/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 11:07:41 by dmlasko           #+#    #+#             */
/*   Updated: 2024/12/02 00:34:37 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	connect_all_neighbors(t_data *dt, int row, int col)
{
	t_coor	*coor;
	t_coor	*neighbor;
	int		node_clr;

	coor = &dt->map->coor[row][col];

	// horizontal lines
	neighbor = &dt->map->coor[row][col + 1];
	if (col < dt->map->width - 1 && DRAW_LINES && DRAW_HORIZONTAL_LINES)
		connect_two_nodes(dt, coor, neighbor);
	
	// vertical lines
	neighbor = &dt->map->coor[row + 1][col];
	if (row < dt->map->height - 1 && DRAW_LINES && DRAW_VERTICAL_LINES)
		connect_two_nodes(dt, coor, neighbor);
	
	if (dt->view->show_nodes)
	{
		if (!pixel_is_in_window(coor->x_iso, coor->y_iso))
			return ;
		if (dt->view->use_custom_clrs)
			node_clr = coor->z_clr_custom;
		else
			node_clr = coor->z_clr;
		// if (row == 0 && col == 2)
		// 	node_clr = LIME;
		draw_node(dt, coor->x_iso, coor->y_iso, node_clr);
	}
}

int	render_map(t_data *dt)
{
	int		row;
	int		col;

	row = 0;
	while (row < dt->map->height)
	{
		col = 0;
		while (col < dt->map->width)
		{
			connect_all_neighbors(dt, row, col);
			// printf("[%d][%d] Depth: %f\n", row, col, data->map->coor[row][col].z_depth);
			++col;
		}
		++row;
	}
	// printf("----------------------------------------\n");
	return (0);
}
