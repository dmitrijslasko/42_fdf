/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 19:36:44 by abrabant          #+#    #+#             */
/*   Updated: 2024/12/02 01:17:46 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <X11/Xlib.h> // For X11 functions


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

void setup_hooks(t_data *data)
{
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, handle_keypress, data);
	mlx_hook(data->win_ptr, 17, 0, close_window, data);
	mlx_hook(data->win_ptr, 4, 1L << 2, mouse_press, data);
	mlx_hook(data->win_ptr, 5, 1L << 3, mouse_release, data);
	mlx_hook(data->win_ptr, 6, 1L << 6, mouse_move, data);
}
int	show_welcome_img(t_data *data)
{
	if (data->win_ptr == NULL)
		return (1);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->welcome_img, 0, 0);
	return (0);
}

int	render(t_data *data)
{
	if (data->win_ptr == NULL)
		return (1);
	if (data->view->show_welcome)
	{
		show_welcome_img(data);
		return (1);
	}
	update_iso_coors(data, data->map, data->view);
	update_bounding_box(data);
	render_background(data->img, data->view->bg_clr);
	if (data->view->show_admin)
		show_admin(data);
	draw_map(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img->mlx_img, 0, 0);
	add_ui(data);
	return (0);
}

void setup_mouse(t_mouse *mouse)
{
	mouse->lmb_is_pressed = FALSE;
	mouse->rmb_is_pressed = FALSE;
}

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
	return (ptr);

}

int init_data(t_data *data)
{
	int	x;
	int y;

	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
	{
		free_data(data);
		return (MLX_ERROR);
	}
	data->win_ptr = mlx_new_window(data->mlx_ptr, WINDOW_W, WINDOW_H, WINDOW_NAME);
	if (data->win_ptr == NULL)
	{
		free_data(data);
		return (MLX_ERROR);
	}
	data->welcome_img = mlx_xpm_file_to_image(data->mlx_ptr, WELCOME_IMAGE, &x, &y);
	if (!data->welcome_img)
		free_data(data);
	data->view = protected_malloc(sizeof(t_view));
	data->mouse = protected_malloc(sizeof(t_mouse));
	data->img = protected_malloc(sizeof(t_img));
	init_view(data->view);

	return (0);
}

int	main(int argc, char **argv)
{
	t_data *data;
	if (check_arguments(argc, argv) == -1)
		exit (1);

	data = protected_malloc(sizeof(t_data));
	init_data(data);
	if (PARSE_MAP)
		data->map = parse_map(data, argv[1]);
	else
		data->map = init_map(data, 10, 10, 2);
	setup_view(data);
	data->img->mlx_img = mlx_new_image(data->mlx_ptr, WINDOW_W, WINDOW_H);
	data->img->addr = mlx_get_data_addr(data->img->mlx_img, &data->img->bpp,
			&data->img->line_len, &data->img->endian);
	setup_hooks(data);
	setup_mouse(data->mouse);
	mlx_loop_hook(data->mlx_ptr, &render, data);
	mlx_loop(data->mlx_ptr);
	free_data(data);
	return (0);
}
