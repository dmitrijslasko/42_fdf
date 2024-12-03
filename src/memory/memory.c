/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 21:02:00 by dmlasko           #+#    #+#             */
/*   Updated: 2024/12/03 17:48:54 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	*protected_malloc(size_t size, t_data *dt)
{
	void	*ptr;

	if (size == 0)
		return (NULL);
	ptr = malloc(size);
	if (!ptr)
	{
		perror("Failed to allocate memory.");
		if (dt)
			free_data(dt);
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

void	free_data(t_data *dt)
{
	if (!dt)
		return ;
	if (dt->img->mlx_img)
		mlx_destroy_image(dt->mlx_ptr, dt->img->mlx_img);
	if (dt->welcome_img)
		mlx_destroy_image(dt->mlx_ptr, dt->welcome_img);
	mlx_destroy_display(dt->mlx_ptr);
	if (dt->mlx_ptr)
		safe_free(dt->mlx_ptr);
	if (dt->win_ptr)
		safe_free(dt->win_ptr);
	if (dt->img)
		safe_free(dt->img);
	if (dt->view)
		safe_free(dt->view);
	if (dt->mouse)
		safe_free(dt->mouse);
	if (dt->map)
		free_map(dt->map, dt->map->height);
	if (dt)
		safe_free(dt);
}
