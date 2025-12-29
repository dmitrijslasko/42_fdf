/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 11:36:52 by dmlasko           #+#    #+#             */
/*   Updated: 2024/12/03 18:31:26 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
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

t_map	*create_map(int fd, t_data *data)
{
	char	*result;
	int		rows;
	int		cols;

	result = get_next_line(fd);
	cols = ft_count_str(result, ' ');
	if (cols == 0)
		exit (1);
	rows = 0;
	free(result);
	while (result)
	{
		result = get_next_line(fd);
		free(result);
		++rows;
	}
	return (init_map(data, rows, cols, 0));
}

t_map	*parse_map(t_data *data, char *filepath)
{
	int		fd;
	t_map	*map;

	fd = open(filepath, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Can't read file. Check the filename, try again.\n", 1);
		return (NULL);
	}
	map = create_map(fd, data);
	fill_in_map(data, filepath);
	
	close(fd);
	ft_printf("Map parsed. Rows: %d, Columns: %d\n", data->map->height, \
				data->map->width);
	return (map);
}

static int	process_row(t_data *data, int row, char **values)
{
	int		col;
	int		i;
	char	**coor;

	col = 0;
	i = 0;
	while (values[i])
	{
		data->map->nodes[row][col].z = ft_atoi(values[i]);
		if (ft_count_str(values[i], ',') == 2)
		{
			coor = ft_split(values[i], ',');
			data->map->nodes[row][col].z_color = hex_to_int(coor[1]);
			free_values(coor);
			data->map->has_color_info = 1;
		}
		else
			data->map->nodes[row][col].z_color = DEF_LINE_COLOR;
		data->map->z_max = fmax(data->map->z_max, ft_atoi(values[i]));
		data->map->z_min = fmin(data->map->z_min, ft_atoi(values[i]));
		++col;
		++i;
	}
	return (0);
}

void	fill_in_map(t_data *data, char *filepath)
{
	int		fd;
	char	*result;
	char	**values;
	int		row;

	fd = open(filepath, O_RDONLY);
	result = get_next_line(fd);
	row = 0;
	while (result)
	{
		values = ft_split(result, ' ');
		process_row(data, row, values);
		free_values(values);
		free(result);
		result = get_next_line(fd);
		++row;
	}
	update_all_iso_coordinates(data, data->map, data->view);
	update_z_rel(data);
	close(fd);
}
