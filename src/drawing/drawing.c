/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 11:08:00 by dmlasko           #+#    #+#             */
/*   Updated: 2024/11/29 11:31:53 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	img_pix_put(t_img *img, int x, int y, int clr)
{
	char	*pixel;
	int		i;

	if (pixel_is_in_window(x, y) == 0)
		return ;
	i = img->bpp - 8;
	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	while (i >= 0)
	{
		if (img->endian != 0)
			*pixel++ = (clr >> i) & 0xFF;
		else
			*pixel++ = (clr >> (img->bpp - 8 - i)) & 0xFF;
		i -= 8;
	}
}

void	img_pix_put_buffer(t_data *dt, t_img *img, int x, int y, float z, int clr)
{
	if (!pixel_is_in_window(x, y))
		return;

	if (z > dt->z_buffer[y][x]) // or z > ... depending on your projection
		return;

	// return ;

	char *pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)pixel = clr;

	dt->z_buffer[y][x] = z;
}


int	pixel_is_in_window(int x, int y)
{
	if (x >= 0 && x < WINDOW_W && y >= 0 && y < WINDOW_H)
		return (1);
	return (0);
}
