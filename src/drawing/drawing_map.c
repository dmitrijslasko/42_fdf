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

static void	connect_all_neighbors(t_data *data, int row, int col)
{
	t_coor	*coor;
	t_coor	*neighbor;
	int		node_clr;

	coor = &data->map->coor[row][col];
	neighbor = &data->map->coor[row][col + 1];
	if (col < data->map->width - 1 && DRAW_LINES && DRAW_HORIZONTAL_LINES)
		connect_two_nodes(data, coor, neighbor);
	neighbor = &data->map->coor[row + 1][col];
	if (row < data->map->height - 1 && DRAW_LINES && DRAW_VERTICAL_LINES)
		connect_two_nodes(data, coor, neighbor);
	
	if (data->view->show_nodes)
	{
		if (data->view->use_custom_clrs)
			node_clr = coor->z_clr_custom;
		else
			node_clr = coor->z_clr;
		draw_node(data, coor->x_iso, coor->y_iso, node_clr);
	}
}

int	draw_map(t_data *data)
{
	int		row;
	int		col;

	row = 0;
	while (row < data->map->height)
	{
		col = 0;
		while (col < data->map->width)
		{
			connect_all_neighbors(data, row, col);
			// printf("[%d][%d] Depth: %f\n", col, row, data->map->coor[col][row].z_depth);
			++col;
		}
		++row;
	}
	return (0);
}
