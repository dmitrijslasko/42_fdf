/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 11:37:21 by dmlasko           #+#    #+#             */
/*   Updated: 2024/12/02 12:10:34 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map	*init_map(t_data *data, int width, int height, int z)
{
	t_map	*map;
	int		current_row;
	int		current_col;

	map = protected_malloc(sizeof(t_map));
	if (!map)
	{
		perror("Error allocating memory: map");
		return (NULL);
	}
	data->map = map;
	map->width = width;
	map->height = height;
	map->has_clr_info = 0;
	map->coor = malloc(height * sizeof(t_coor));
	if (!map->coor)
	{
		perror("Error allocating memory: map->coor");
		free(map);
		return (NULL);
	}
	current_row = 0;
	while (current_row < height)
	{
		map->coor[current_row] = malloc(width * sizeof(t_coor));
		if (!map->coor[current_row])
		{
			perror("Error allocating memory: map->coor[current_row]");
			free_map(map, current_row);
			return (NULL);
		}
		current_col = 0;
		while (current_col < width)
		{
			map->coor[current_row][current_col].z = z;
			map->coor[current_row][current_col].z_clr = DEF_LINE_COLOR;
			++current_col;
		}
		++current_row;
	}
	update_iso_coors(data, data->map, data->view);
	return (map);
}

void	free_map(t_map *map, int allocated_rows)
{
	int	row;

	if (map)
	{
		if (map->coor)
		{
			row = 0;
			while (row < allocated_rows)
			{
				free(map->coor[row]);
				++row;
			}
			free(map->coor);
		}
		free(map);
	}
}

int		safe_free(void *ptr)
{
	free(ptr);
	ptr = NULL;
	return (0);
}
void	free_data(t_data *data)
{
	if (!data)
		return ;
	if (data->img->mlx_img)
		mlx_destroy_image(data->mlx_ptr, data->img->mlx_img);
	if (data->welcome_img)
		mlx_destroy_image(data->mlx_ptr, data->welcome_img);
	mlx_destroy_display(data->mlx_ptr);
	if (data->mlx_ptr)
		safe_free(data->mlx_ptr);
	if (data->win_ptr)
		safe_free(data->win_ptr);
	if (data->img)
		safe_free(data->img);
	if (data->view)
		safe_free(data->view);
	if (data->mouse)
		safe_free(data->mouse);
	if (data->map)
		free_map(data->map, data->map->height);
	if (data)
		safe_free(data);
}
