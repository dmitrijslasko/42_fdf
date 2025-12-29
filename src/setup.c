/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 19:36:44 by abrabant          #+#    #+#             */
/*   Updated: 2025/01/19 14:15:21 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	setup_hooks(t_data *dt)
{
	ft_printf("Setting up hooks...\n");
	mlx_hook(dt->win_ptr, KeyPress, KeyPressMask, handle_keypress, dt);
	mlx_hook(dt->win_ptr, 17, 0, close_window, dt);
	mlx_hook(dt->win_ptr, 4, 1L << 2, mouse_press, dt);
	mlx_hook(dt->win_ptr, 5, 1L << 3, mouse_release, dt);
	mlx_hook(dt->win_ptr, 6, 1L << 6, mouse_move, dt);
	dt->mouse->lmb_is_pressed = FALSE;
	dt->mouse->rmb_is_pressed = FALSE;
	ft_printf("Setting up hooks complete!\n");
}

int	show_welcome_img(t_data *dt)
{
	if (dt->win_ptr == NULL)
		return (1);
	mlx_put_image_to_window(dt->mlx_ptr, dt->win_ptr, dt->welcome_img, 0, 0);
	return (0);
}

void	setup_mouse(t_mouse *mouse)
{
	ft_printf("Mouse setup...\n");

	ft_printf("Mouse setup complete!\n");
}
