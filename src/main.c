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

	if (check_arguments(argc, argv) == -1)
		return (1);
		
	init_data(&dt);
	if (validate_file_content(WELCOME_IMAGE) != 1)
		dt.view->show_welcome = 0;
	if (PARSE_MAP)
		dt.map = parse_map(&dt, argv[1]);
	else
		dt.map = init_map(&dt, TEST_MAP_X, TEST_MAP_Y, TEST_MAP_Z);
	if (!dt.map)
		return (1);
	setup_mlx_and_win(&dt);

	dt.z_buffer = protected_malloc(sizeof(float *) * WINDOW_H);
	for (int y = 0; y < WINDOW_H; y++)
		dt.z_buffer[y] = protected_malloc(sizeof(float) * WINDOW_W);

	setup_view(&dt);
	setup_img(&dt);
	setup_hooks(&dt);
	setup_mouse(dt.mouse);
	mlx_loop_hook(dt.mlx_ptr, render, &dt);
	mlx_loop(dt.mlx_ptr);
	return (0);
}
