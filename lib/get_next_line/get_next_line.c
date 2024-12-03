/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 16:35:39 by dmlasko           #+#    #+#             */
/*   Updated: 2024/08/13 18:55:57 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#define LINE_BREAK_CHAR 10

static char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

static char	*add_buffer_to_line(char *next_line, char *buffer)
{
	char	*processed_line;

	processed_line = ft_strjoin(next_line, buffer);
	if (!processed_line)
		return (NULL);
	free(next_line);
	return (processed_line);
}

static void	update_buffer(char *buffer)
{
	size_t	chars_to_line_break;
	char	*ptr;

	chars_to_line_break = ft_strchr(buffer, LINE_BREAK_CHAR) - buffer;
	ptr = ft_substr(buffer, chars_to_line_break + 1, \
		ft_strlen(buffer) - chars_to_line_break);
	ft_strlcpy(buffer, ptr, ft_strlen(buffer));
	free(ptr);
}

static char	*extract_next_line(char **next_line, char **buffer)
{
	char	*processed_line;
	size_t	chars_to_extract;
	size_t	chars_to_remove;

	if (ft_strlen(*next_line) == 0)
	{
		free(*buffer);
		*buffer = NULL;
		free(*next_line);
		return (NULL);
	}
	update_buffer(*buffer);
	if (ft_strchr(*next_line, LINE_BREAK_CHAR) == NULL)
		chars_to_remove = 0;
	else
		chars_to_remove = ft_strlen(ft_strchr(*next_line, LINE_BREAK_CHAR));
	chars_to_extract = ft_strlen(*next_line) - chars_to_remove + 1;
	processed_line = ft_substr(*next_line, 0, chars_to_extract);
	if (!processed_line)
		return (NULL);
	free(*next_line);
	return (processed_line);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*next_line;
	size_t		read_bytes_len;

	if (buffer == NULL)
		buffer = (char *)func(buffer, 1, BUFFER_SIZE + 1, sizeof(char));
	next_line = (char *)malloc(sizeof(char));
	if (!next_line || !buffer || BUFFER_SIZE <= 0)
		return (NULL);
	next_line[0] = '\0';
	next_line = add_buffer_to_line(next_line, buffer);
	read_bytes_len = BUFFER_SIZE;
	while (!ft_strchr(buffer, LINE_BREAK_CHAR) && read_bytes_len == BUFFER_SIZE)
	{
		func(buffer, 0, BUFFER_SIZE + 1, 0);
		read_bytes_len = read(fd, buffer, BUFFER_SIZE);
		if ((int) read_bytes_len == -1)
		{
			next_line[0] = '\0';
			break ;
		}
		next_line = add_buffer_to_line(next_line, buffer);
		buffer[read_bytes_len] = '\0';
	}
	return (extract_next_line(&next_line, &buffer));
}

//#include <stdio.h>
//#include <fcntl.h>
//int	main(void)
//{
//	int fd;
//	fd = open("test", O_RDONLY);
//	char *result = get_next_line(fd);
//	printf(">>> GET NEXT LINE: %s\n", result);
//	free (result);
//	result = get_next_line(fd);
//	printf(">>> GET NEXT LINE: %s\n", result);
//	free (result);
//	result = get_next_line(fd);
//	printf(">>> GET NEXT LINE: %s\n", result);
//	free (result);
//	result = get_next_line(fd);
//	printf(">>> GET NEXT LINE: %s\n", result);
//	free (result);
//	result = get_next_line(fd);
//	printf(">>> GET NEXT LINE: %s\n", result);
//	free (result);
//	result = get_next_line(fd);
//	printf(">>> GET NEXT LINE: %s\n", result);
//	free (result);
//	result = get_next_line(fd);
//	printf(">>> GET NEXT LINE: %s\n", result);
//	free (result);
//	result = get_next_line(fd);
//	printf(">>> GET NEXT LINE: %s\n", result);
//	free (result);
//	result = get_next_line(fd);
//	printf(">>> GET NEXT LINE: %s\n", result);
//	free (result);
//}
