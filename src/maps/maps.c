/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 11:36:52 by dmlasko           #+#    #+#             */
/*   Updated: 2024/12/01 20:49:05 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_values(char **values)
{
	int	i;

	if (!values)
		return ;
	i = 0;
	while (values[i])
	{
		free(values[i]);
		values[i] = NULL;
		++i;
	}
	free(values);
	values = NULL;
}

t_map	*parse_map(t_data *data, char *filepath)
{
	int		fd;
	char	*result;
	int		rows;
	int		cols;
	t_map	*map;

	fd = open(filepath, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Cannot read the file. Check the filename and try again.\n", 1);
		exit (1);
	}
	result = get_next_line(fd);
	cols = ft_count_strings(result, ' ');
	rows = 0;
	free(result);
	while (result)
	{
		result = get_next_line(fd);
		free(result);
		++rows;
	}
	map = init_map(data, cols, rows, 0);
	fill_in_map(data, filepath);
	close(fd);
	return (map);
}

void	fill_in_map(t_data *data, char *filepath)
{
	int		fd;
	char	*result;
	int		row;
	int		col;
	char	**values;
	char	**coor;
	int		i;

	fd = open(filepath, O_RDONLY);
	result = get_next_line(fd);
	row = 0;
	while (result)
	{
		values = ft_split(result, ' ');
		col = 0;
		i = 0;
		while (values[i])
		{
			data->map->coor[row][col].z = ft_atoi(values[i]);
			if (ft_count_strings(values[i], ',') == 2)
			{
				coor = ft_split(values[i], ',');
				data->map->coor[row][col].z_clr = hex_to_int(coor[1]);
				free_values(coor);
				data->map->has_clr_info = 1;
			}
			else
				data->map->coor[row][col].z_clr = DEF_LINE_COLOR;
			data->map->z_max = fmax(data->map->z_max, ft_atoi(values[i]));
			data->map->z_min = fmin(data->map->z_min, ft_atoi(values[i]));
			++col;
			++i;
		}
		free_values(values);
		free(result);
		result = get_next_line(fd);
		++row;
	}
	update_iso_coors(data, data->map, data->view);
	update_z_rel(data);
	close(fd);
}

void	update_z_rel(t_data *data)
{
	int		row;
	int		col;
	t_coor	*coor;

	row = 0;
	while (row < data->map->height)
	{
		col = 0;
		while (col < data->map->width)
		{
			coor = &data->map->coor[row][col];
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
			ft_putnbr_fd(map->coor[row][col].z, 1);
			ft_putchar_fd('\t', 1);
			++col;
		}
		ft_putchar_fd('\n', 1);
		++row;
	}
}
