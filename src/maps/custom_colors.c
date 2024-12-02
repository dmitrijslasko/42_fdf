/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom_colors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 21:15:37 by dmlasko           #+#    #+#             */
/*   Updated: 2024/12/02 21:21:16 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	update_colors(t_data *data, t_map *map)
{
	int		row;
	int		col;
	t_view	*v;
	t_coor	coor;

	v = data->view;
	row = 0;
	while (row < map->height)
	{
		col = 0;
		while (col < map->width)
		{
			coor = map->coor[row][col];
			coor.z_clr_custom = get_clr_bween_clrs(coor.z_rel, v->lo_clr, \
															v->hi_clr);
			map->coor[row][col] = coor;
			++col;
		}
		++row;
	}
	return (0);
}
