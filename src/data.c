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

#define STARTING_DEPTH	-99999999.0f

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
void render_axes(t_data *dt)
{
	// draw_single_color_line
	draw_sloped_line(dt, (t_node){0,0}, (t_node){100, 200}); 

}
int	render_frame(t_data *dt)
{
	// obsolete check it seems
	// if (dt->win_ptr == NULL)
	// 	return (1);
	const float _max_zoom = 0.6;
	const float _min_zoom = 0.5;
	const float _zoom_speed = 0.0005;
	
	if (dt->view->auto_rotate)
	{
		double *axis_value;
		if (dt->view->auto_rotate_axis == 1)
			axis_value = &dt->view->rot_x;
		else if (dt->view->auto_rotate_axis == 2)
			axis_value = &dt->view->rot_y;
		else if (dt->view->auto_rotate_axis == 3)
			axis_value = &dt->view->rot_z;

		*axis_value += AUTO_ROTATION_SPEED;
		if (ENABLE_ROTATION_ZOOM) 
		{
			if (dt->view->zoom > _max_zoom || dt->view->zoom < _min_zoom)
				dt->view->auto_rotate_zoom_dir *= -1;
			dt->view->zoom += dt->view->auto_rotate_zoom_dir * _zoom_speed;
		}
	}
	
	// z buffer reset
	for (int y = 0; y < WINDOW_H; y++)
		for (int x = 0; x < WINDOW_W; x++)
        	dt->z_buffer_map[y][x] = STARTING_DEPTH; // “no depth yet”
	
	// welcome image toggle
	if (dt->view->show_welcome_img)
	{
		show_welcome_img(dt);
		return (2);
	}
	
	render_background(dt->img, dt->view->bg_clr);

	render_axes(dt);

	update_all_iso_coordinates(dt, dt->map, dt->view);

	render_map(dt);

	mlx_put_image_to_window(dt->mlx_ptr, dt->win_ptr, dt->img->mlx_img, 0, 0);

	if (dt->view->show_admin)
		show_admin(dt);

	if (dt->view->show_controls)
		add_ui(dt);
	
	return (EXIT_SUCCESS);
}

int	setup_mlx_and_win(t_data *dt)
{
	dt->mlx_ptr = mlx_init();
	if (dt->mlx_ptr == NULL)
		return (MLX_ERROR);
	dt->win_ptr = mlx_new_window(dt->mlx_ptr, WINDOW_W, WINDOW_H, WINDOW_NAME);
	if (dt->win_ptr == NULL)
		return (MLX_ERROR);
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
