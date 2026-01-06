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
	t_node	*node;
	t_node	*neighbor;
	int		node_clr;

	node = &dt->map->nodes[row][col];

	// horizontal lines
	
	if (col < dt->map->width - 1 && dt->view->show_lines && DRAW_HORIZONTAL_LINES)
	{
		neighbor = &dt->map->nodes[row][col + 1];
		if (pixel_is_in_window(node->x_iso, node->y_iso) || pixel_is_in_window(neighbor->x_iso, neighbor->y_iso))
			connect_two_nodes(dt, node, neighbor);
	}
	
	// vertical lines
	if (row < dt->map->height - 1 && dt->view->show_lines && DRAW_VERTICAL_LINES) 
	{
		neighbor = &dt->map->nodes[row + 1][col];
		if (pixel_is_in_window(node->x_iso, node->y_iso) || pixel_is_in_window(neighbor->x_iso, neighbor->y_iso))
			connect_two_nodes(dt, node, neighbor);
	}
	
	if (dt->view->show_nodes)
	{
		if (!pixel_is_in_window(node->x_iso, node->y_iso))
			return ;
		if (dt->view->use_custom_colors)
			node_clr = node->z_clr_custom;
		else
			node_clr = node->z_color;
		draw_node(dt, node, node_clr);
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
			++col;
		}
		++row;
	}
	// printf("----------------------------------------\n");
	return (0);
}
