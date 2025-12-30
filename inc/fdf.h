/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmlasko <dmlasko@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 10:30:26 by dmlasko           #+#    #+#             */
/*   Updated: 2025/01/19 14:15:51 by dmlasko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

// includes
# include <mlx.h>
# include <stdlib.h>
# include <string.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <X11/Xlib.h>
# include <math.h>
# include <limits.h>
# include <stdio.h>
# include <fcntl.h>

// headers
# include "colors.h"
# include "settings.h"
# include "structs.h"
# include "keys.h"
# include "errors.h"

// user libraries
# include "ft_printf.h"
# include "get_next_line.h"

// parsing & updating maps
void print_map_colors(t_data *dt);

int				check_cl_arguments(int argc, char **argv);
t_map			*parse_map(t_data *dt, char *filepath);
t_map			*init_map(t_data *dt, int width, int height, int z);
void			fill_in_map(t_data *dt, char *filepath);
void			print_map(t_map *map);
t_map			*create_map(int fd, t_data *dt);

void			update_z_rel(t_data *dt);
int				update_colors(t_data *dt, t_map *map);

void			update_bounding_box(t_data *dt);

// iso calculations
void			scale_coor(int *x, int *y, int *z, t_view *view);
void			rotate_x(int *y, int *z, double rot_x);
void			rotate_y(int *x, int *z, double rot_y);
void			rotate_z(int *x, int *y, double rot_z);
void			apply_isometric_projection(int *x, int *y, int *z);


// colors
unsigned int	pack_rgb(int red, int green, int blue);
int				get_color_between_colors(double dist, int start_clr, int end_clr);
int				hex_to_int(const char *hexString);
int				get_color_between_nodes(t_data *dt, t_node pt_1, \
							t_node pt_2, double dist);

// drawing
void			img_pix_put(t_img *img, int x, int y, int clr);
void			img_pix_put_buffer(t_data *dt, t_img *img, int x, int y, float z, int clr);
int				pixel_is_in_window(int x, int y);
void			draw_node(t_data *dt, t_node *node, int clr);
int				render_map(t_data *dt);
float			get_iso_coor(int *x, int *y, int *z, t_view *view);
void			update_all_iso_coordinates(t_data *dt, t_map *map, t_view *view);

// drawing lines
void			draw_vertical_line(t_data *dt, t_node pt_1, t_node pt_2);
void			draw_single_color_vertical_line(t_img *img, t_line line);
void			draw_sloped_line(t_data *dt, t_node pt_1, t_node pt_2);
void			draw_horizontal_line(t_img *img, t_line line);
void			connect_two_nodes(t_data *dt, t_node *coor_1, t_node *coor_2);
int				draw_rectangle(t_img *img, t_node *pt_1, t_node *pt_2, int clr);

// aux
void			swap(void *a, void *b, size_t size);
int				ft_count_str(char const *s, char const c);

// memory management
int				init_data(t_data *dt);
void			init_view(t_view *view);
void			*protected_malloc(size_t size);
void			free_map(t_map *map, int allocated_rows);

// UI / admin
void			show_admin(t_data *dt);
void			add_ui(t_data *dt);
void			add_controls_panel_en(t_data *dt);
void			add_controls_panel_de(t_data *dt);
void			add_zoom_info(t_data *dt);
void			add_coor_info(t_data *dt);
void			add_license_info(t_data *dt);
void			update_origin_coor(t_data *dt);

int				validate_welcome_img(const char *filename);

// angle operations & conversion
double			deg_to_radians(double angle);
void			reset_rotation(t_data *dt);
void			reset_angle_degrees(double *angle);
void			reset_all_angle_degrees_data(t_data *dt);

// rendering
void			render_background(t_img *img, int clr);
int				render_frame(t_data *dt);

// setup
int				setup_mlx_and_win(t_data *dt);
int				setup_img(t_data *dt);
void			setup_view(t_data *dt);

// keyboard & mouse
void			setup_hooks(t_data *dt);
int				handle_keypress(int keysym, t_data *dt);
int				handle_keyrelease(int keysym, void *dt);
void			setup_mouse(t_mouse *mouse);
int				mouse_move(int x, int y, t_data *dt);
int				mouse_release(int button, int x, int y, t_data *dt);
int				mouse_press(int button, int x, int y, t_data *dt);
int				close_window(void);
int				show_welcome_img(t_data *dt);

#endif
