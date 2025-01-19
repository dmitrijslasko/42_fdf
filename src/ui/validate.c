/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 14:12:46 by dmlasko           #+#    #+#             */
/*   Updated: 2025/01/19 14:24:52 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// Function to validate the file content
int	validate_file_content(const char *filename)
{
	char	buffer[512];
	int		fd;
	ssize_t	bytes_read;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error: Could not open welcome image file\n.");
		return (0);
	}
	bytes_read = read(fd, buffer, sizeof(buffer) - 1);
	close(fd);
	if (bytes_read < 0)
	{
		ft_printf("Error: Could not read file.\n");
		return (0);
	}
	if (bytes_read == 0)
		return (0);
	buffer[bytes_read] = '\0';
	if (strstr(buffer, "404") != NULL)
	{
		ft_printf("Error: File contains 404: \n");
	}
	return (1);
}
