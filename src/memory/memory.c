/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 21:02:00 by dmlasko           #+#    #+#             */
/*   Updated: 2025/01/18 16:28:09 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	*protected_malloc(size_t size)
{
	void	*ptr;

	if (size == 0)
		return (NULL);
	ptr = malloc(size);
	if (!ptr)
	{
		perror("Failed to allocate memory.");
		exit (1);
	}
	memset(ptr, 0, size);
	return (ptr);
}

int	safe_free(void *ptr)
{
	free(ptr);
	ptr = NULL;
	return (0);
}
