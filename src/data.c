/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 18:35:49 by dmlasko           #+#    #+#             */
/*   Updated: 2025/01/19 14:17:34 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	render_background(t_img *img, int clr)
{
	int	current_x;
	int	current_y;

	current_y = 0;
	while (current_y < WINDOW_H)
	{
		current_x = 0;
		while (current_x < WINDOW_W)
		{
			img_pix_put(img, current_x, current_y, clr);
			++current_x;
		}
		++current_y;
	}
}

int	render(t_data *dt)
{
	for (int y = 0; y < WINDOW_H; y++)
		for (int x = 0; x < WINDOW_W; x++)
        	dt->z_buffer[y][x] = 100000000.0f; // “no depth yet”

	if (dt->win_ptr == NULL)
		return (1);
	{
		if (dt->view->show_welcome)
		{
			show_welcome_img(dt);
			return (1);
		}
	}
	update_iso_coors(dt, dt->map, dt->view);
	render_background(dt->img, dt->view->bg_clr);

	if (dt->view->show_admin)
		show_admin(dt);

	draw_map(dt);

	// printf("Depth: %f\n", dt->z_buffer[WINDOW_H/2-1][WINDOW_W/2-1]);
	// printf("Depth: %f\n", dt->map->coor[dt->map->height/2-1][dt->map->width/2-1].z_depth);

	mlx_put_image_to_window(dt->mlx_ptr, dt->win_ptr, dt->img->mlx_img, 0, 0);
	update_bounding_box(dt);
	add_ui(dt);
	return (EXIT_SUCCESS);
}

int	setup_mlx_and_win(t_data *dt)
{
	int	x;
	int	y;

	dt->mlx_ptr = mlx_init();
	if (dt->mlx_ptr == NULL)
		return (MLX_ERROR);
	dt->win_ptr = mlx_new_window(dt->mlx_ptr, WINDOW_W, WINDOW_H, WINDOW_NAME);
	if (dt->win_ptr == NULL)
		return (MLX_ERROR);
	if (SHOW_WELCOME_IMAGE)
		dt->welcome_img = mlx_xpm_file_to_image(dt->mlx_ptr, WELCOME_IMAGE, \
												&x, &y);
	return (0);
}

int	init_data(t_data *dt)
{
	dt->view = protected_malloc(sizeof(t_view));
	dt->mouse = protected_malloc(sizeof(t_mouse));
	dt->img = protected_malloc(sizeof(t_img));
	init_view(dt->view);
	return (0);
}

int	setup_img(t_data *dt)
{
	dt->img->mlx_img = mlx_new_image(dt->mlx_ptr, WINDOW_W, WINDOW_H);
	dt->img->addr = mlx_get_data_addr(dt->img->mlx_img, &dt->img->bpp,
			&dt->img->line_len, &dt->img->endian);
	return (0);
}
