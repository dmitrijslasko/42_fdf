/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_func.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 11:36:44 by dmlasko           #+#    #+#             */
/*   Updated: 2025/01/18 16:51:56 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	add_controls_panel_en(t_data *dt)
{
	int		y;
	void	*m;
	void	*w;
	int		r;

	y = 0;
	m = dt->mlx_ptr;
	w = dt->win_ptr;
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
	mlx_string_put(m, w, 15, y += r, CYAN, "Enable auto-rotation: [M]");
	mlx_string_put(m, w, 15, y += r, UI_CLR_2, "Projections");
	mlx_string_put(m, w, 57, y += r, UI_CLR_1, "ISO: [I]");
	mlx_string_put(m, w, 57, y += r, UI_CLR_1, "Parallel: [P]");
	mlx_string_put(m, w, 15, y += r, UI_CLR_2, "Show / hide nodes: [N]");
	mlx_string_put(m, w, 15, y += r, UI_CLR_2, "Reset offs: [R]");
	mlx_string_put(m, w, 15, y += r, UI_CLR_2, "Map colors: [1][2][3][4]");
	mlx_string_put(m, w, 15, y += r, CYAN, "Secret admin mode: [/]");
	// mlx_string_put(m, w, 15, y += r, LIME, "[0][2] Z-depth]: ");
}

void	add_controls_panel_de(t_data *dt)
{
	int		y;
	void	*m;
	void	*w;
	int		r;

	y = 0;
	m = dt->mlx_ptr;
	w = dt->win_ptr;
	r = DEF_MENU_ROW_H;
	mlx_string_put(m, w, 15, y += r, UI_CLR_1, "STEUERUNGEN");
	mlx_string_put(m, w, 15, y += r, UI_CLR_2, "Zoom: Scrollen oder [+] / [-]");
	mlx_string_put(m, w, 15, y += r, UI_CLR_2, "Bewegen: Ziehen / Pfeiltasten");
	mlx_string_put(m, w, 15, y += r, UI_CLR_2, "Abflachen: [ / ]");
	mlx_string_put(m, w, 15, y += r, UI_CLR_2, "Drehen: RMB drucken & Bewegen");
	mlx_string_put(m, w, 35, y += r, UI_CLR_2, "oder:");
	mlx_string_put(m, w, 57, y += r, UI_CLR_1, "X-Achse - Q/W");
	mlx_string_put(m, w, 57, y += r, UI_CLR_1, "Y-Achse - A/S");
	mlx_string_put(m, w, 57, y += r, UI_CLR_1, "Z-Achse - Z/W");
	mlx_string_put(m, w, 15, y += r, CYAN, "Automatische Drehung: [M]");
	mlx_string_put(m, w, 15, y += r, UI_CLR_2, "Projektionen");
	mlx_string_put(m, w, 57, y += r, UI_CLR_1, "ISO: [I]");
	mlx_string_put(m, w, 57, y += r, UI_CLR_1, "Parallel: [P]");
	mlx_string_put(m, w, 15, y += r, UI_CLR_2, "Knoten: [N]");
	mlx_string_put(m, w, 15, y += r, UI_CLR_2, "Zurucksetzen: [R]");
	mlx_string_put(m, w, 15, y += r, UI_CLR_2, "Kartenfarben: [1][2][3][4]");
	mlx_string_put(m, w, 15, y += r, CYAN, "Geheimer Admin-Modus: [/]");
}

void	add_zoom_info(t_data *dt)
{
	int		y;
	void	*mlx;
	void	*win;
	t_view	*view;
	char	*str;

	y = WINDOW_H - 10;
	mlx = dt->mlx_ptr;
	win = dt->win_ptr;
	view = dt->view;
	mlx_string_put(mlx, win, WINDOW_W - 69, y, UI_CLR_1, "Zoom: ");
	str = ft_itoa(floor(view->zoom * 10));
	mlx_string_put(mlx, win, WINDOW_W - 35, y, UI_CLR_2, str);
	free(str);
}

void	add_coor_info(t_data *dt)
{
	int		y;
	void	*mlx;
	void	*win;
	t_view	*view;
	char	*str;

	y = WINDOW_H - 40;
	mlx = dt->mlx_ptr;
	win = dt->win_ptr;
	view = dt->view;
	// z depth tests
	// str = ft_itoa(floor(dt->map->coor[0][2].z_depth));
	// mlx_string_put(mlx, win, WINDOW_W - 150, y - 20, UI_CLR_1, "[0][2] Z Depth: ");
	// mlx_string_put(mlx, win, WINDOW_W - 30, y - 20, UI_CLR_2, str);
	reset_all_angle_degrees_data(dt);
	mlx_string_put(mlx, win, WINDOW_W - 51, y, UI_CLR_1, "X: ");
	str = ft_itoa(floor(view->rot_x));
	mlx_string_put(mlx, win, WINDOW_W - 35, y, UI_CLR_2, str);
	mlx_string_put(mlx, win, WINDOW_W - 51, y += 10, UI_CLR_1, "Y: ");
	free(str);
	str = ft_itoa(floor(view->rot_y));
	mlx_string_put(mlx, win, WINDOW_W - 35, y, UI_CLR_2, str);
	free(str);
	mlx_string_put(mlx, win, WINDOW_W - 51, y += 10, UI_CLR_1, "Z: ");
	str = ft_itoa(floor(view->rot_z));
	mlx_string_put(mlx, win, WINDOW_W - 35, y, UI_CLR_2, str);
	free(str);
	add_zoom_info(dt);
}

void	add_license_info(t_data *dt)
{
	void	*mlx;
	void	*win;

	mlx = dt->mlx_ptr;
	win = dt->win_ptr;
	mlx_string_put(mlx, win, WINDOW_W / 2 - 100, WINDOW_H - 10, GREY, \
			VERSION_INFO);
}
