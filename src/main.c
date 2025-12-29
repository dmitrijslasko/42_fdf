/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 19:36:44 by abrabant          #+#    #+#             */
/*   Updated: 2025/01/19 14:23:05 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_data	dt;

	if (check_cl_arguments(argc, argv) == -1)
		return (EXIT_FAILURE);
		
	init_data(&dt);

	if (validate_welcome_img(WELCOME_IMAGE) != 1)
		dt.view->show_welcome_img = 0;
		
	if (USE_TEST_MAP)
		dt.map = init_map(&dt, TEST_MAP_X, TEST_MAP_Y, TEST_MAP_Z);
	else
		dt.map = parse_map(&dt, argv[1]);
	
	if (!dt.map) return (EXIT_FAILURE);

	setup_mlx_and_win(&dt);

	if (SHOW_WELCOME_IMAGE)
	dt.welcome_img = mlx_xpm_file_to_image(dt.mlx_ptr, WELCOME_IMAGE, NULL, NULL);

	// init z buffer for each window pixel
	dt.z_buffer_map = protected_malloc(sizeof(float *) * WINDOW_H);
	for (int y = 0; y < WINDOW_H; y++)
		dt.z_buffer_map[y] = protected_malloc(sizeof(float) * WINDOW_W);

	setup_view(&dt);
	setup_img(&dt);
	setup_hooks(&dt);

	mlx_loop_hook(dt.mlx_ptr, render_frame, &dt);
	mlx_loop(dt.mlx_ptr);

	return (EXIT_SUCCESS);
}
