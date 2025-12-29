/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 11:36:52 by dmlasko           #+#    #+#             */
/*   Updated: 2024/12/03 00:17:23 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	update_z_rel(t_data *data)
{
	int		row;
	int		col;
	t_node	*coor;

	row = 0;
	while (row < data->map->height)
	{
		col = 0;
		while (col < data->map->width)
		{
			coor = &data->map->nodes[row][col];
			if (data->map->z_min == data->map->z_max)
				coor->z_rel = 0;
			else
				coor->z_rel = (double)coor->z / data->map->z_max;
			++col;
		}
		++row;
	}
}

void	print_map(t_map *map)
{
	int	row;
	int	col;

	row = 0;
	while (row < map->height)
	{
		col = 0;
		while (col < map->width)
		{
			ft_putnbr_fd(map->nodes[row][col].z, 1);
			ft_putchar_fd('\t', 1);
			++col;
		}
		ft_putchar_fd('\n', 1);
		++row;
	}
}
