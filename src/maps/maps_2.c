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

t_map	*create_map(int fd, t_data *dt)
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
	return (init_map(dt, rows, cols, 0));
}

t_map	*parse_map(t_data *dt, char *filepath)
{
	int		fd;
	t_map	*map;

	fd = open(filepath, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Can't read file. Check the filename, try again.\n", 1);
		return (NULL);
	}
	map = create_map(fd, dt);
	fill_in_map(dt, filepath);
	
	close(fd);
	ft_printf("Map parsed. Rows: %d, Columns: %d\n", dt->map->height, \
				dt->map->width);
	return (map);
}

char	*trim_newline(char *s)
{
	int	i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i])
		i++;
	if (i > 0 && (s[i - 1] == '\n' || s[i - 1] == '\r'))
		s[i - 1] = '\0';
	return (s);
}


static int	process_row(t_data *dt, int row, char **values)
{
	int		col;
	int		i;
	char	**coor;

	col = 0;
	i = 0;
	while (values[i])
	{
		dt->map->nodes[row][col].z = ft_atoi(values[i]);
		if (ft_count_str(values[i], ',') == 2)
		{
			coor = ft_split(values[i], ',');
			// printf("DEBUG color token: '%s'\n", coor[1]);
			dt->map->nodes[row][col].z_color = hex_to_int(trim_newline(coor[1]));
			// printf("COLOR: %s\n", coor[1]);
			free_values(coor);
			dt->map->has_color_info = 1;
		}
		else
			dt->map->nodes[row][col].z_color = DEF_LINE_COLOR;
			
		dt->map->z_max = fmax(dt->map->z_max, ft_atoi(values[i]));
		dt->map->z_min = fmin(dt->map->z_min, ft_atoi(values[i]));
		++col;
		++i;
	}
	return (0);
}

void	fill_in_map(t_data *dt, char *filepath)
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
		process_row(dt, row, values);
		free_values(values);
		free(result);
		result = get_next_line(fd);
		++row;
	}
	update_all_iso_coordinates(dt, dt->map, dt->view);
	update_z_relative(dt);
	close(fd);
}
