/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 19:36:44 by abrabant          #+#    #+#             */
/*   Updated: 2024/12/02 22:13:38 by dmlasko          ###   ########.fr       */
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
	if (dt->win_ptr == NULL)
		return (1);
	if (dt->view->show_welcome)
	{
		show_welcome_img(dt);
		return (1);
	}
	update_iso_coors(dt, dt->map, dt->view);
	render_background(dt->img, dt->view->bg_clr);
	if (dt->view->show_admin)
		show_admin(dt);
	draw_map(dt);
	mlx_put_image_to_window(dt->mlx_ptr, dt->win_ptr, dt->img->mlx_img, 0, 0);
	update_bounding_box(dt);
	add_ui(dt);
	return (0);
}

int	init_data(t_data *dt)
{
	int	x;
	int	y;

	dt->mlx_ptr = mlx_init();
	if (dt->mlx_ptr == NULL)
	{
		free_data(dt);
		return (MLX_ERROR);
	}
	dt->win_ptr = mlx_new_window(dt->mlx_ptr, WINDOW_W, WINDOW_H, WINDOW_NAME);
	if (dt->win_ptr == NULL)
	{
		free_data(dt);
		return (MLX_ERROR);
	}
	if (SHOW_WELCOME_IMAGE)
		dt->welcome_img = mlx_xpm_file_to_image(dt->mlx_ptr, WELCOME_IMAGE, \
												 &x, &y);
	dt->view = protected_malloc(sizeof(t_view), dt);
	dt->mouse = protected_malloc(sizeof(t_mouse), dt);
	dt->img = protected_malloc(sizeof(t_img), dt);
	init_view(dt->view);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	*dt;

	if (check_arguments(argc, argv) == -1)
		exit (1);
	dt = protected_malloc(sizeof(t_data), NULL);
	init_data(dt);
	if (PARSE_MAP)
		dt->map = parse_map(dt, argv[1]);
	else
		dt->map = init_map(dt, TEST_MAP_X, TEST_MAP_Y, TEST_MAP_Z);
	setup_view(dt);
	dt->img->mlx_img = mlx_new_image(dt->mlx_ptr, WINDOW_W, WINDOW_H);
	dt->img->addr = mlx_get_data_addr(dt->img->mlx_img, &dt->img->bpp,
			&dt->img->line_len, &dt->img->endian);
	setup_hooks(dt);
	setup_mouse(dt->mouse);
	mlx_loop_hook(dt->mlx_ptr, &render, dt);
	mlx_loop(dt->mlx_ptr);
	free_data(dt);
	return (0);
}
