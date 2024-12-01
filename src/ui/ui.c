/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 11:36:44 by dmlasko           #+#    #+#             */
/*   Updated: 2024/12/01 20:49:36 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	add_controls_panel(t_data *data)
{
	int		y;
	void	*m;
	void	*w;
	int		r;

	y = 0;
	m = data->mlx_ptr;
	w = data->win_ptr;
	r = DEF_MENU_ROW_H;
	mlx_string_put(m, w, 15, y += r, UI_CLR_1, "CONTROLS");
	mlx_string_put(m, w, 15, y += r, UI_CLR_2, "Zoom: Scroll or [+] / [-]");
	mlx_string_put(m, w, 15, y += r, UI_CLR_2, "Move: Drag around or Arrows");
	mlx_string_put(m, w, 15, y += r, UI_CLR_2, "Flatten: [ / ]");
	mlx_string_put(m, w, 15, y += r, UI_CLR_2, "Rotate: Press RMB & Move");
	mlx_string_put(m, w, 35, y += r, UI_CLR_2, "or:");
	mlx_string_put(m, w, 57, y += r, UI_CLR_1, "X-Axis - Q/W");
	mlx_string_put(m, w, 57, y += r, UI_CLR_1, "Y-Axis - A/S");
	mlx_string_put(m, w, 57, y += r, UI_CLR_1, "Z-Axis - Z/W");
	mlx_string_put(m, w, 15, y += r, UI_CLR_2, "Projections");
	mlx_string_put(m, w, 57, y += r, UI_CLR_1, "ISO: [I]");
	mlx_string_put(m, w, 57, y += r, UI_CLR_1, "Parallel: [P]");
	mlx_string_put(m, w, 15, y += r, UI_CLR_2, "Show / hide nodes: [N]");
	mlx_string_put(m, w, 15, y += r, UI_CLR_2, "Reset offs: [R]");
	mlx_string_put(m, w, 15, y += r, UI_CLR_2, "Map colors: [1][2][3]");
	mlx_string_put(m, w, 15, y += r, CYAN, "Secret admin mode: [/]");
}

static void	add_zoom_info(t_data *data)
{
	int		y;
	void	*mlx;
	void	*win;
	t_view	*view;
	char	*str;

	y = WINDOW_H - 10;
	mlx = data->mlx_ptr;
	win = data->win_ptr;
	view = data->view;
	mlx_string_put(mlx, win, WINDOW_W - 69, y, UI_CLR_1, "Zoom: ");
	str = ft_itoa(floor(view->zoom * 10));
	mlx_string_put(mlx, win, WINDOW_W - 35, y, UI_CLR_2, str);
	free(str);
}

static void	add_coor_info(t_data *data)
{
	int		y;
	void	*mlx;
	void	*win;
	t_view	*view;
	char	*str;

	y = WINDOW_H - 40;
	mlx = data->mlx_ptr;
	win = data->win_ptr;
	view = data->view;
	mlx_string_put(mlx, win, WINDOW_W - 51, y, UI_CLR_1, "X: ");
	str = ft_itoa(floor(view->rot_x));
	mlx_string_put(mlx, win, WINDOW_W - 35, y, UI_CLR_2, str);
	free(str);
	mlx_string_put(mlx, win, WINDOW_W - 51, y += 10, UI_CLR_1, "Y: ");
	str = ft_itoa(floor(view->rot_y));
	mlx_string_put(mlx, win, WINDOW_W - 35, y, UI_CLR_2, str);
	free(str);
	mlx_string_put(mlx, win, WINDOW_W - 51, y += 10, UI_CLR_1, "Z: ");
	str = ft_itoa(floor(view->rot_z));
	mlx_string_put(mlx, win, WINDOW_W - 35, y, UI_CLR_2, str);
	free(str);
	add_zoom_info(data);
}

static void	add_license_info(t_data *data)
{
	void	*mlx;
	void	*win;

	mlx = data->mlx_ptr;
	win = data->win_ptr;
	mlx_string_put(mlx, win, WINDOW_W / 2 - 100, WINDOW_H - 10, GREY, \
			"fdf project - 42 Berlin - dmlasko, v1.0");
}

void	add_ui(t_data *data)
{
	add_controls_panel(data);
	add_coor_info(data);
	add_license_info(data);
}
